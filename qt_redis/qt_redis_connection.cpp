/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 22-12-2016
///		Date update	: 27-12-2016
///		Comment		:
/// ============================================================================

#include <QDebug>

#include "qt_redis_connection.h"

namespace rele_auto
{

/// ############################################################################
///			class qt_redis_connection
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
	///	~qt_redis_connection( )
    /// ------------------------------------------------------------------------
	qt_redis_connection::~qt_redis_connection( )
	{
	}

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
	///	clear( )
    /// ------------------------------------------------------------------------
	void qt_redis_connection::clear( )
	{
		this->_reply.clear( );
		this->_rds_ctx = nullptr;
	}

    /// ------------------------------------------------------------------------
	///	finish( )
    /// ------------------------------------------------------------------------
	void qt_redis_connection::finish( )
	{
		if( this->_rds_ctx != nullptr )
		{
			redisAsyncFree( this->_rds_ctx );
		}

		emit finished( );
	}

    /// ------------------------------------------------------------------------
	///	reply_callback(redisAsyncContext *, void *, void *)
    /// ------------------------------------------------------------------------
	void reply_callback( redisAsyncContext *, void * r, void * privdata)
	{
		redisReply * reply = static_cast<redisReply *>(r);
		qt_redis_connection * cnn = static_cast<qt_redis_connection *>(privdata);

		if( reply == nullptr || cnn == nullptr ) return;

		switch( reply->type )
		{
			case REDIS_REPLY_INTEGER:
			{
				qDebug( ) << "REDIS_REPLY_INTEGER";
				cnn->_reply.append( QString::number( reply->integer ) );
				break;
			}

			case REDIS_REPLY_STRING:
			{
				qDebug( ) << "REDIS_REPLY_STRING";
				cnn->_reply.append( QString( reply->str ) );
				break;
			}

			case REDIS_REPLY_ARRAY:
			{
				qDebug( ) << "REDIS_REPLY_ARRAY";
				qDebug( ) << "elements: " << reply->elements;

				size_t count = 0;
				while( count != reply->elements )
				{
					cnn->_reply.append( QString( (*(reply->element + count))->str ) );
					++count;
				}
			}
			break;

			default:
				break;
		}

		cnn->finish( );
	}

    /// ------------------------------------------------------------------------
	///	execute(const qt_redis_command &cmd)
    /// ------------------------------------------------------------------------
	void qt_redis_connection::execute( const qt_redis_command &cmd )
	{
		if( this->_port == -1 || this->_host.isEmpty( ) )
		{
			emit finished( );
			return;
		}

		this->clear( );
		this->_rds_ctx = redisAsyncConnect( this->_host.toStdString( ).data( ), this->_port );

		if( this->_rds_ctx != nullptr && this->_rds_ctx->err )
		{
			qDebug( ) << "Error: " << this->_rds_ctx->errstr << endl;
			redisAsyncFree( this->_rds_ctx );
			emit finished( );
			return;
		}

		this->_hirds_adapter.setContext( this->_rds_ctx );

		redisAsyncCommand( this->_rds_ctx, reply_callback, this, cmd.toStdString( ).data( ) );
	}

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
	///	debug_results( )
    /// ------------------------------------------------------------------------
	void qt_redis_connection::debug_results( )
	{
		for( const QString &s : this->_reply )
		{
			qDebug( ) << s;
		}
	}

    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================


/// ############################################################################
}//namespace rele_auto
