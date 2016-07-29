#include <QCoreApplication>
#include "qt_redis_client.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	imv::test_redis_client obj;
	//obj.run_command( "ping" );
	obj.run_command( "INFO" );

	return a.exec( );
}

