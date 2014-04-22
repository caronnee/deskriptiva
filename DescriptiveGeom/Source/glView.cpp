#include "glView.h"
#include <QEvent>
#include <QKeyEvent>
#include <gl/GLAux.h>
#include <math.h>
#define GL_PI 3.141592

glView::glView(QWidget *parent)
	: QGLWidget(parent)
{
	setMouseTracking(true);
}

void glView::initializeGL() {
	
	glClearColor(200.0f/255, 200.0f/255, 1.0f, 0);
}

void glView::resizeGL(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2, w/2, -h/2, h/2); // set origin to bottom left corner
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void glView::setBackGround( int r,int g, int b )
{
	QColor c(r,g,b,0);
	glClearColor(c.redF(), c.greenF(), c.blueF(), c.alphaF());
	update();
	//qglClearColor(color);
}

GLdouble initMatrix[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};

#define MIN_ANGLE GL_PI/360

void glView::mouseMoveEvent(QMouseEvent * event)
{
	// do this only when mouse left button is pressed
	if ((event->buttons() & Qt::RightButton)!= Qt::RightButton)
	{
		oldMousePos = event->posF();
		return;
	}
	glMatrixMode(GL_PROJECTION);
	GLdouble multMatrix[16];
	memcpy(multMatrix,initMatrix,sizeof(multMatrix));
	QPointF rel = oldMousePos - event->posF();
	oldMousePos = event->posF();
	//if (abs(rel.x()) < abs(rel.y()))
	{
		float angle = rel.x()*MIN_ANGLE;
		float ssin = sin(angle);
		float ccos = cos(angle);
		multMatrix[0] = ccos;
		multMatrix[1] = -ssin;
		multMatrix[4] = ssin;
		multMatrix[5] = ccos;
	}
	/*else
	{
		float angle = rel.y()*MIN_ANGLE;
		float ssin = sin(angle);
		float ccos = cos(angle);
		multMatrix[0] = ccos;
		multMatrix[1] = -ssin;
		multMatrix[4] = ssin;
		multMatrix[5] = ccos;
	}*/
	glMultMatrixd(multMatrix);
	update();
}
void glView::keyPressEvent(QKeyEvent* event) 
{
	switch(event->key()) {
	case Qt::Key_Escape:
		close();
		break;
	default:
		event->ignore();
		break;
	}
}

void glView::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0); // red color

	glBegin(GL_POLYGON);
	glVertex3f(1,0,0);
	glVertex3f(0,1,0);
	glVertex3f(0,0,0);
	glEnd();
}
glView::~glView()
{

}
