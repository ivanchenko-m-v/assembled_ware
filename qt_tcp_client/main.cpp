#include <QCoreApplication>
#include "qt_redis_client.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	imv::test_redis_client obj;
	//obj.run_command( "ping" );
	//obj.run_command( "INFO" );
	//obj.run_command( "sinterstore /BЛ:/64 /BЛ /64" );
	obj.run_command( "sort /BЛ:/64 ALPHA GET *->n BY *->n" );

	return a.exec( );
}

