#include <iostream>
using namespace std;

#include <QCoreApplication>
#include <QTimer>

#include "example-qt.h"
#include "qt_redis_sync_connection.h"

void getCallback( redisAsyncContext *, void * r, void * privdata )
{

    redisReply * reply = static_cast<redisReply *>(r);
    ExampleQt * ex = static_cast<ExampleQt *>(privdata);

    if( reply == nullptr || ex == nullptr ) return;

    if( reply->elements )
    {
		size_t count = 0;
		while( count != reply->elements )
		{
			cout << "key" << count << ": " << (*(reply->element + count))->str << endl;
			++count;
		}
    }
    else
    {
		cout << "key: " << reply->str << endl;
    }

    ex->finish( );
}

void ExampleQt::run( )
{

    m_ctx = redisAsyncConnect("localhost", 6379);

    if (m_ctx->err) {
        cerr << "Error: " << m_ctx->errstr << endl;
        redisAsyncFree(m_ctx);
        emit finished();
    }

    m_adapter.setContext(m_ctx);

    //redisAsyncCommand(m_ctx, NULL, NULL, "SET key %s", m_value);
    //redisAsyncCommand(m_ctx, getCallback, this, "GET key");
    //redisAsyncCommand(m_ctx, getCallback, this, "sinterstore /BЛ:/64 /BЛ /64");
    redisAsyncCommand(m_ctx, getCallback, this, "sort /BЛ:/64 ALPHA GET # GET *->n BY *->n");
}

int main (int argc, char **argv)
{

    QCoreApplication app(argc, argv);
/*
    ExampleQt example(argv[argc-1]);

    QObject::connect(&example, SIGNAL(finished()), &app, SLOT(quit()));
    QTimer::singleShot(0, &example, SLOT(run()));
    */
    /*
    rele_auto::qt_redis_connection cnn( "localhost", 6379 );
    QObject::connect(&cnn, SIGNAL(finished()), &cnn, SLOT(debug_results()));
    //cnn.execute("sinterstore /BЛ:/64 /BЛ /64");
    cnn.execute("exists /BЛ:/64");
    //cnn.execute("sort /BЛ:/64 ALPHA GET # GET *->n GET *->p BY *->n");
    */
    rele_auto::qt_redis_sync_connection cnn( "localhost", 6379 );
    cnn.execute("exists /BЛ:/64");
    if(
		cnn.reply_type( ) == rele_auto::qt_redis_reply_type::integer  &&
		cnn.result_integer( ) == 0
	  )
    {
		cnn.execute("sinterstore /BЛ:/64 /BЛ /64");
    }
    if(
		cnn.result_integer( ) > 0
	  )
	{
		cnn.execute("sort /BЛ:/64 ALPHA GET # GET *->n GET *->p BY *->n");
		if( cnn.reply_type( ) == rele_auto::qt_redis_reply_type::array )
		{
			for( const QString &s : cnn.result( ) )
			{
				std::cout << s.toStdString( ) << std::endl;
			}
		}
    }

    return app.exec( );
}
