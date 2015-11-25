#include <gl/glut.h>

GLsizei winWidth = 500, winHeight = 500; //표시 윈도우 크기 초기화

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //흰색 표시 윈도우 지정
}

void displayWirePolyhedra(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //표시 윈도우 초기화.
	glColor3f(0.0, 0.0, 1.0); //청색 표사 윈도우 지정

	/*관찰 변환을 설정*/
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	/*정육면체 크기를 조정하고 평형투시 형태의 선형구조로 표시*/
	glScalef(1.5, 2.0, 1.0);
	glutWireCube(1.0);

	/*크기변환, 이동변환을 수행하며 정십이면체를 선형구조로 표현*/
	glScalef(0.8, 0.5, 0.8);
	glTranslatef(-0.6, -0.5, 0.0);
	glutWireDodecahedron();

	/*크기변환, 이동변환을 수행하며 정삼각뿔을 선형구조로 표현*/
	glTranslatef(8.6, 8.6, 2.0);
	glutWireTetrahedron();

	/*크기변환, 이동변환을 수행하며 정팔면체를 선형구조로 표현*/
	glTranslatef(-0.3, -1.0, 0.0);
	glutWireOctahedron();

	/*크기변환, 이동변환을 수행하며 정이십면체를 선형구조로 표현*/
	glScalef(0.8, 0.8, 1.0);
	glTranslatef(4.3, -0.2, 0.5);
	glutWireIcosahedron();

	glFlush();
}

void winReshapeFtn(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
}

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("wire-frame polyhedra");

	init();
	glutDisplayFunc(displayWirePolyhedra);
	glutReshapeFunc(winReshapeFtn);
	glutMainLoop();
}