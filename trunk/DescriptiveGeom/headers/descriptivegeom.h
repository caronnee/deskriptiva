#ifndef DESCRIPTIVEGEOM_H
#define DESCRIPTIVEGEOM_H

#include <QtGui/QMainWindow>
#include "ui_descriptivegeom.h"

class DescriptiveGeom : public QMainWindow
{
	Q_OBJECT

public:
	DescriptiveGeom(QWidget *parent = 0, Qt::WFlags flags = 0);
	~DescriptiveGeom();

private:
	Ui::DescriptiveGeomClass ui;
};

#endif // DESCRIPTIVEGEOM_H
