#include "dialog_ware_search.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	dialog_ware_search w;
	w.show();

	return a.exec();
}
