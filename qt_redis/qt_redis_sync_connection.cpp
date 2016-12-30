/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 28-12-2016
///		Date update	: 28-12-2016
///		Comment		:
/// ============================================================================

#include <QDebug>

#include "qt_redis_sync_connection.h"

namespace rele_auto
{

/// ############################################################################
///			class qt_redis_sync_connection
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
	///	~qt_redis_sync_connection( )
    /// ------------------------------------------------------------------------
	qt_redis_sync_connection::~qt_redis_sync_connection( )
	{
	}

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
	///	clear( )
    /// ------------------------------------------------------------------------
	void qt_redis_sync_connection::clear( )
	{
		//close connection if it opened
		this->close( );
		//clear results previous command
		this->_reply_type = qt_redis_reply_type::nothing;
		this->_reply.clear( );
	}

	void qt_redis_sync_connection::fill_reply_data( )
	{
		if( this->_rds_ctx == nullptr || this->_rds_ctx->err )
		{
			return;
		}

		if( this->_rds_reply == nullptr ) return;

		switch( this->_rds_reply->type )
		{
			case REDIS_REPLY_INTEGER:
			{
				qDebug( ) << "REDIS_REPLY_INTEGER";
				this->_reply_type = qt_redis_reply_type::integer;
				this->_reply.append( QString::number( this->_rds_reply->integer ) );
				break;
			}

			case REDIS_REPLY_STRING:
			{
				qDebug( ) << "REDIS_REPLY_STRING";
				this->_reply_type = qt_redis_reply_type::string;
				this->_reply.append( QString( this->_rds_reply->str ) );
				break;
			}

			case REDIS_REPLY_ARRAY:
			{
				qDebug( ) << "REDIS_REPLY_ARRAY";
				this->_reply_type = qt_redis_reply_type::array;
				qDebug( ) << "elements: " << this->_rds_reply->elements;

				size_t count = 0;
				while( count != this->_rds_reply->elements )
				{
					this->_reply.append( QString( (*(this->_rds_reply->element + count))->str ) );
					++count;
				}
			}
			break;

			default:
				break;
		}
	}

    /// ------------------------------------------------------------------------
	///	open( )
    /// ------------------------------------------------------------------------
	bool qt_redis_sync_connection::open( )
	{
		struct timeval timeout = { 1, 500000 }; // 1.5 seconds
		this->_rds_ctx = redisConnectWithTimeout(
												this->_host.toStdString( ).data( ),
												this->_port,
												timeout
												);
		if( this->_rds_ctx == nullptr || this->_rds_ctx->err )
		{
			if( this->_rds_ctx )
			{
				qDebug( ) << "Connection error: " << this->_rds_ctx->errstr;
				this->clear( );
				return false;
			}
			else
			{
				qDebug( ) << "Connection error: can't allocate redis context\n";
				return false;
			}
		}

		return true;
	}

    /// ------------------------------------------------------------------------
	///	close( )
    /// ------------------------------------------------------------------------
	void qt_redis_sync_connection::close( )
	{
		//free hiredis results struct
		if( this->_rds_reply != nullptr )
		{
			freeReplyObject( this->_rds_reply );
		}
		this->_rds_reply = nullptr;

		//free hiredis context
		if( this->_rds_ctx != nullptr )
		{
			redisFree( this->_rds_ctx );
		}
		this->_rds_ctx = nullptr;
	}

    /// ------------------------------------------------------------------------
	///	execute(const qt_redis_command &cmd)
    /// ------------------------------------------------------------------------
	void qt_redis_sync_connection::execute( const qt_redis_command &cmd )
	{
		if( this->_port == -1 || this->_host.isEmpty( ) )
		{
			return;
		}

		this->clear( );

		if( !this->open( ) )
		{
			return;
		}

		//exec command synchronously
		this->_rds_reply = static_cast<redisReply *>(
											redisCommand(
													this->_rds_ctx,
													cmd.toStdString( ).data( )
														)
													);
		//fill  result object
		this->fill_reply_data( );

		this->close( );
	}

/// ############################################################################
}//namespace rele_auto
