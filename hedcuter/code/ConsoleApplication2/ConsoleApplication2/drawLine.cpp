#include <gl/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //������� ����
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //���÷��� �����츦 ����

	glColor3f(1.0, 0.0, 0.0); //���������� ���� �������� ����
	glBegin(GL_LINES);
	glVertex2i(180, 15);
	glVertex2i(10, 145); //���������� ������ ����
	glEnd();

	glFlush();// ��� OpenGL ��ƾ���� �������� ���� ó����
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut�ʱ�ȭ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //���÷��� ��� ����
	glutInitWindowPosition(50, 100); //���÷��� �������� �»�� ��ġ ����
	glutInitWindowSize(400, 300); //���÷��� �������� ���� ���� ����
	glutCreateWindow("an example program"); //���÷��� ������ ����

	init(); //�ʱ�ȭ ���ν��� ����
	glutDisplayFunc(lineSegment); //�׷����� ���÷��� ������� ����
	glutMainLoop(); //��� ���� ���÷����� �� ���
}

