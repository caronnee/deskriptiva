#ifndef LINEPANEL_H
#define LINEPANEL_H

#include <QWidget>
#include "ui_linePanel.h"

class LinePanel : public QWidget, public Ui::linePanel
{
	Q_OBJECT

public:
	LinePanel(QWidget *parent = 0);
	~LinePanel();
};

#endif // LINEPANEL_H
