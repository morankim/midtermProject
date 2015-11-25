#include <gl/glut.h>

GLsizei winWidth = 500, winHeight = 500; //ǥ�� ������ ũ�� �ʱ�ȭ

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //��� ǥ�� ������ ����
}

void displayWirePolyhedra(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //ǥ�� ������ �ʱ�ȭ.
	glColor3f(0.0, 0.0, 1.0); //û�� ǥ�� ������ ����

	/*���� ��ȯ�� ����*/
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	/*������ü ũ�⸦ �����ϰ� �������� ������ ���������� ǥ��*/
	glScalef(1.5, 2.0, 1.0);
	glutWireCube(1.0);

	/*ũ�⺯ȯ, �̵���ȯ�� �����ϸ� �����̸�ü�� ���������� ǥ��*/
	glScalef(0.8, 0.5, 0.8);
	glTranslatef(-0.6, -0.5, 0.0);
	glutWireDodecahedron();

	/*ũ�⺯ȯ, �̵���ȯ�� �����ϸ� ���ﰢ���� ���������� ǥ��*/
	glTranslatef(8.6, 8.6, 2.0);
	glutWireTetrahedron();

	/*ũ�⺯ȯ, �̵���ȯ�� �����ϸ� ���ȸ�ü�� ���������� ǥ��*/
	glTranslatef(-0.3, -1.0, 0.0);
	glutWireOctahedron();

	/*ũ�⺯ȯ, �̵���ȯ�� �����ϸ� ���̽ʸ�ü�� ���������� ǥ��*/
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