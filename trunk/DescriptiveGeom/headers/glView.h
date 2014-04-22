#ifndef GLVIEW_H
#define GLVIEW_H

#include <QWidget>
#include <qtOpenGl/QGLWidget>

class glView : public QGLWidget
{
	Q_OBJECT

	QPointF oldMousePos;
public:
	glView(QWidget *parent);
	~glView();
	void initializeGL();
	void paintGL();
	void resizeGL(int w, int h);
	void keyPressEvent(QKeyEvent* event);
	void mouseMoveEvent(QMouseEvent * event);

public slots:
	void setBackGround(int r,int g, int b);
};

#endif // GLVIEW_H
