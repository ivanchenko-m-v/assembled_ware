#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QTcpSocket sock;
	sock.connectToHost( "localhost", 6379 );

	sock.write( "ping" );
	QString str = sock.readAll();
	qDebug()<< str;

	return a.exec();
}

