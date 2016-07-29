#ifndef QT_TCP_CLIENT
#define QT_TCP_CLIENT

#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>
#include <QObject>
#include <QHostAddress>
#include <QByteArray>

namespace imv
{

class qt_redis_client : public QObject
{
Q_OBJECT

public:
	qt_redis_client( QString server, quint16 port ) :
		QObject( ),
		_server(server),
		_port(port)
	{
		this->_sock = new QTcpSocket( this );
		this->connect(
						_sock, SIGNAL( connected( ) ),
						SLOT( slot_connected( ) )
					 );
		this->connect(
						_sock, SIGNAL( disconnected( ) ),
						SLOT( slot_disconnected( ) )
					 );
		this->connect(
						_sock, SIGNAL( readyRead( ) ),
						SLOT( slot_ready_read( ) )
					 );
		this->connect(
						_sock, SIGNAL( error( QAbstractSocket::SocketError ) ),
						SLOT( slot_error( ) )
					 );
	}

	~qt_redis_client( )
	{
		if( this->_sock !=nullptr )
		{
			QString hostname = this->_sock->localAddress().toString();
			hostname.append(":");
			hostname.append(QString::number(this->_sock->localPort()));

			if( this->_sock->isOpen() )
			{
				this->_sock->close( );
			}
			delete _sock;

			qDebug( ) << hostname << " socket destroyed";
		}
	}

	void run_redis_command( const QString &command )
	{
		this->_last_command = command;
		this->_last_response.clear( );

		this->connect_to_server( );
	}

	const QString& redis_response( ) const
	{
		return this->_last_response;
	}

private:
	void connect_to_server(  )
	{
		qDebug( ) << "Connecting to " << _server << " , port: " << _port << "...";
		this->_sock->connectToHost( _server, _port );
	}

	void send_command( )
	{/*
		QByteArray block;
		QDataStream out( &block, QIODevice::WriteOnly );
		out.setVersion(QDataStream::Qt_5_5);

		out << this->_last_command << "\r\n";
		out.device( )->seek(0);
		out << quint16( block.size( ) - sizeof( quint16 ) );
		this->_sock->write( block );
		*/
		this->_sock->write( (this->_last_command + "\r\n").toUtf8() );
		this->_sock->waitForBytesWritten( );

		qDebug( ) << "Sending command: " << this->_last_command;

		this->_sock->waitForReadyRead( );
	}

signals:
	void request_complete( );

private slots:
	void slot_connected( )
	{
		qDebug( ) << "Connected to " << _server << " , port: " << _port;

		this->send_command( );
	}

	void slot_disconnected( )
	{
		qDebug()<< "socket error: connection closed by server";
		this->_sock->close( );
	}

	void slot_ready_read( )
	{
		this->_last_response.clear();
		qDebug()<< "ready read";
		if( this->_sock->isOpen() && this->_sock->isReadable() )
		{
			QDataStream in( this->_sock );

			uint n_bytes = this->_sock->bytesAvailable();
			qDebug()<< "bytes available: " << n_bytes;

			in.setVersion( QDataStream::Qt_5_5 );

			QByteArray arr(40960, '\0');
			in.readRawData(arr.data(), n_bytes );

			this->_last_response.append(arr);
			this->_last_response.replace("\\r\\n", "\r\n" );

			this->_sock->close( );

			emit request_complete( );
		}
	}

	void slot_error( )
	{
		qDebug()<< "socket error: " << this->_sock->errorString( );
		this->_sock->close( );
	}


private:
	QTcpSocket	*_sock = nullptr;
	QString 	_server{""};
	quint16		_port{0};

	QString		_last_command{""};
	QString		_last_response{""};

};

class test_redis_client : public QObject
{
Q_OBJECT

public:
	test_redis_client( ) :
		QObject( )
	{
		_pcli = new qt_redis_client( "localhost", 6379 );
		this->connect(_pcli, SIGNAL(request_complete()), SLOT(slot_request_msg()));
	}

	~test_redis_client( )
	{
		delete _pcli;
	}

	void run_command( const QString &cmd )
	{
		if( _pcli == nullptr )
		{
			return;
		}
		this->_pcli->run_redis_command( cmd );
	}

private slots:
	void slot_request_msg( )
	{
		if( _pcli == nullptr )
		{
			return;
		}
		const QString& response = _pcli->redis_response( );
		qDebug( ) << response;
	}

private:
	qt_redis_client *_pcli = nullptr;
};

}//namespace imv

#endif // QT_TCP_CLIENT

