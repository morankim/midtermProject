
#include <stdlib.h>
#include <GL/freeglut.h>
#include <math.h>

static int width, height;

void myDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPointSize(3);

  for (int i = 0; i < 3; i++)
  {
	  glMatrixMode(GL_MODELVIEW);
	  glLoadIdentity();
	  glTranslatef(50+20*i, 50+10*i, 0);
	 // glColor3ub(255-40*i, 0, 0);
	  glColor3ub(1, 1, 1);
	  glutSolidCone(50, 1, 16, 16);
	  glColor3ub(0, 0, 0);
	  glBegin(GL_POINTS);
	  glVertex3d(0, 0, 1);
	  glEnd();
  }

  glFinish();
  //glutSwapBuffers();
  //glFinish();
}



int main(int argc, char ** argv)
{
	glutInit(&argc, argv);

	int width = 400;
	int height = 300;

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(180, 100);
	
	glutCreateWindow("CVT");
	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	//for (int i = 0; i < 3; i++)
	//{
	//	glMatrixMode(GL_MODELVIEW);
	//	glLoadIdentity();
	//	glTranslatef(50 + 20 * i, 50 + 10 * i, 0);
	//	glColor3ub(255 - 40 * i, 0, 0);
	//	glutSolidCone(50, 1, 16, 16);
	//	glColor3ub(0, 0, 0);
	//	glBegin(GL_POINTS);
	//	glVertex3d(0, 0, 1);
	//	glEnd();
	//}
	//glutSwapBuffers();
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);//CVT construnctor에 들어가야
	myDisplay();
	//glutDisplayFunc(myDisplay);

	//glutMainLoopEvent();
	Sleep(5000);

	return 0;
}

