#include <gl/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //흰색으로 지정
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //디스플레이 윈도우를 지움

	glColor3f(1.0, 0.0, 0.0); //직선조각의 색을 빨강으로 지정
	glBegin(GL_LINES);
	glVertex2i(180, 15);
	glVertex2i(10, 145); //직선조각의 외형을 지정
	glEnd();

	glFlush();// 모든 OpenGL 루틴들을 가능한한 빨리 처리함
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut초기화
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //디스플레이 모드 지정
	glutInitWindowPosition(50, 100); //디스플레이 윈도우의 좌상단 위치 지정
	glutInitWindowSize(400, 300); //디스플레이 윈도우의 폭과 높이 지정
	glutCreateWindow("an example program"); //디스플레이 윈도우 생성

	init(); //초기화 프로시저 실행
	glutDisplayFunc(lineSegment); //그래픽을 디스플레이 윈도우로 보냄
	glutMainLoop(); //모든 것을 디스플레이한 후 대기
}

