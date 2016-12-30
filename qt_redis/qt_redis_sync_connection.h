/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 28-12-2016
///		Date update	: 30-12-2016
///		Comment		:
/// ============================================================================
#ifndef __QT_REDIS_SYNC_CONNECTION_H__
#define __QT_REDIS_SYNC_CONNECTION_H__

#include <QObject>
#include <QString>

#include <hiredis.h>

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
///			enum qt_redis_reply_type
/// ############################################################################
	enum qt_redis_reply_type : int
	{
		nothing	= -1,
		integer	= 8,
		string	= 16,
		array	= 32
	};

/// ############################################################################
///			class qt_redis_sync_connection
/// ############################################################################
    class qt_redis_sync_connection : public QObject
	{
	Q_OBJECT

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        qt_redis_sync_connection( const qt_redis_sync_connection &rhs );

	public:
        /// --------------------------------------------------------------------
        qt_redis_sync_connection( QObject * parent = nullptr )
			: QObject(parent)
		{ }
        qt_redis_sync_connection(
							const qt_redis_host &host,
							const qt_redis_port &port,
							QObject * parent = nullptr
						   ) : QObject(parent),
						   _host(host),
						   _port(port)
		{ }
        /// --------------------------------------------------------------------
        virtual ~qt_redis_sync_connection( );

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    private:
		void clear( );
		void fill_reply_data( );

	public:
		bool open( );
		void close( );

		void execute( const qt_redis_command &cmd );

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
	public:
        /// --------------------------------------------------------------------
		void port( const qt_redis_port &port )
		{
			this->_port = port;
		}
		const qt_redis_port& port( ) const
		{
			return this->_port;
		}

        /// --------------------------------------------------------------------
		void host( const qt_redis_host &host )
		{
			this->_host = host;
		}
		const qt_redis_host& host( ) const
		{
			return this->_host;
		}

        /// --------------------------------------------------------------------
		qt_redis_reply_type reply_type( ) const
		{
			return this->_reply_type;
		}

        /// --------------------------------------------------------------------
		int result_integer( ) const
		{
			int result = -1;

			if( this->_reply.size( ) )
			{
				const QString &s = this->_reply.at(0);
				result = s.toInt( );
			}
			return result;
		}

        /// --------------------------------------------------------------------
		const qt_redis_reply& result( ) const
		{
			return this->_reply;
		}

    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        qt_redis_sync_connection& operator=( const qt_redis_sync_connection &rhs );

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
    private:
		qt_redis_host	_host{""};
		qt_redis_port	_port = -1;
		qt_redis_reply	_reply;
		qt_redis_reply_type _reply_type = qt_redis_reply_type::nothing;

		redisContext	*_rds_ctx = nullptr;
		redisReply		*_rds_reply = nullptr;

	};//class qt_redis_sync_connection
/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace rele_auto

#endif // __QT_REDIS_SYNC_CONNECTION_H__
