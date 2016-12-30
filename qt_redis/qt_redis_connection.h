/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 22-12-2016
///		Date update	: 23-12-2016
///		Comment		:
/// ============================================================================
#ifndef __QT_REDIS_CONNECTION_H__
#define __QT_REDIS_CONNECTION_H__

#include <QObject>
#include <QString>
//adapter hiredis for qt
#include <qt.h>

namespace rele_auto
{

/// ############################################################################
///			class qt_redis_host
/// ############################################################################
using qt_redis_host = QString;

/// ############################################################################
///			class qt_redis_port
/// ############################################################################
using qt_redis_port = int;

/// ############################################################################
///			class qt_redis_command
/// ############################################################################
using qt_redis_command = QString;

/// ############################################################################
///			class qt_redis_reply
/// ############################################################################
using qt_redis_reply = QStringList;

/// ############################################################################
///			class qt_redis_connection
/// ############################################################################
    class qt_redis_connection : public QObject
	{
	Q_OBJECT

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        qt_redis_connection( const qt_redis_connection &rhs );

	public:
        /// --------------------------------------------------------------------
        qt_redis_connection( QObject * parent = nullptr )
			: QObject(parent)
		{ }
        qt_redis_connection(
							const qt_redis_host &host,
							const qt_redis_port &port,
							QObject * parent = nullptr
						   ) : QObject(parent),
						   _host(host),
						   _port(port)
		{ }
        /// --------------------------------------------------------------------
        virtual ~qt_redis_connection( );

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    private:
        void clear( );
        void finish( );

        friend void reply_callback( redisAsyncContext *, void *, void * );

	public:
		void execute( const qt_redis_command &cmd );

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
	public:
		void port( const qt_redis_port &port )
		{
			this->_port = port;
		}
		const qt_redis_port& port( ) const
		{
			return this->_port;
		}
		void host( const qt_redis_host &host )
		{
			this->_host = host;
		}
		const qt_redis_host& host( ) const
		{
			return this->_host;
		}

    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        qt_redis_connection& operator=( const qt_redis_connection &rhs );

    /// ========================================================================
    ///		SIGNALS
    /// ========================================================================
    signals:
        void finished( );

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================
    public slots:
        void debug_results( );

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
    private:
		qt_redis_host	_host = "";
		qt_redis_port	_port = -1;
		qt_redis_reply	_reply;

		redisAsyncContext	*_rds_ctx = nullptr;
		RedisQtAdapter		_hirds_adapter;

	};//class qt_redis_connection
/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace rele_auto

#endif // __QT_REDIS_CONNECTION_H__
