#include "descriptivegeom.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DescriptiveGeom w;
	w.show();
	return a.exec();
}
