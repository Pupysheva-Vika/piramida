/*
 * DemoWindow.cpp
 *
 *  Created on: 13 ���. 2021 �.
 *      Author: grtq
 */

#include "DemoWindow.h"

DemoWindow::DemoWindow(int width, int height)
: Window(width,height)
{
	set_title("��������");
}

void DemoWindow::setup_gl() {
	glClearColor(0.2f, 0.4f, 0.7f, 1.0);
	glMatrixMode(GL_PROJECTION); // ������������� ������� ��������
	gluPerspective (45.0, double(width()) / double(height()), 0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST); //��������� ����� �������
}

void CubeRender(){
	//�������� ���
		glBegin(GL_QUADS);
		glColor3d(1.0, 0.0, 0.0); // ������ ����� (�������)
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, -1.0);

		glColor3d(0.0, 1.0, 1.0); // ������� ����� (���������)
		glVertex3d(-1.0, -1.0, 1.0);
		glVertex3d(1.0, -1.0, 1.0);
		glVertex3d(1.0, 1.0, 1.0);
		glVertex3d(-1.0, 1.0, 1.0);

		glColor3d(0.0, 1.0, 0.0); // ������� ����� (�������)
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(1.0, -1.0, 1.0);
		glVertex3d(1.0, 1.0, 1.0);

		glColor3d(1.0, 1.0, 0.0); // ������� ����� (������)
		glVertex3d(1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, 1.0);
		glVertex3d(1.0, -1.0, 1.0);

		glColor3d(0.7, 0.5, 0.0); // ������� ����� (����������)
		glVertex3d(-1.0, -1.0, -1.0);
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(-1.0, 1.0, 1.0);
		glVertex3d(-1.0, -1.0, 1.0);

		glColor3d(0.0, 0.5, 0.2); // ������� ����� (�����-�������)
		glVertex3d(-1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, -1.0);
		glVertex3d(1.0, 1.0, 1.0);
		glVertex3d(-1.0, 1.0, 1.0);
		glEnd();
}

void DemoWindow::render() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // ������� + ������� ������ ������� �� ������ ��������
	glLoadIdentity(); // ������� ������ ���� = ���������
	gluLookAt(3.0, 4.0, 2.0,  // ���������� ������
			  0.0, 0.0, 0.0,  // ���������� ������
			  0.0, 0.0, 1.0); // ����������� �����, ����������=������
	glRotated(_cube_angle, 0.0, 0.0, 1.0);
	glPushMatrix (); //������������ ^ ������� � ����
	glScaled(0.2, 0.2, 0.2);
	CubeRender();
	glPopMatrix ();
	glScaled(0.2, 0.2, 0.2);
	glTranslated (2.0, 0, 2.0);
	CubeRender();
	glTranslated (2.0, 0, -2.0);
	CubeRender();
	glTranslated (-2.0, 0, -2.0);
	CubeRender();
	glTranslated (4.0, 0, 0);
	CubeRender();
	glTranslated (-8.0, 0, 0);
	CubeRender();
}

void DemoWindow::update() {
	_cube_angle += 0.01; //������� ����
	if (_cube_angle >= 360.0) // ���� ��� �������� ����� 360 ��������
		_cube_angle -= 360.0; // ������� �������� � 0 ��������
}
