#include "../include/renderer.h"

renderer::renderer(){
	// controller ctl(&hc);
	// ctrl = &ctl;
}

void renderer::initialize_renderer(){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("4D VISUALIZER");

    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(-0.3, 0.2, 0.14, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0);
	glRotatef(-90, 0, 1, 0);

}

void renderer::idle(){
    ctrl->pipeline();

	usleep(33*1000);
	glutPostRedisplay();
}

void renderer::keyboard_relay(unsigned char k , int x, int y){
    ctrl->keyboard_function(k, x, y);
}

void renderer::display_hypercube(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glBegin(GL_POINTS);
		for(int x =0; x < 16; x++){
			glColor3f(COLOR(WHITE));
			glVertex3d(hypercube3D(x));
		}
	glEnd();
	//X DELTA RENDERER
	glBegin(GL_LINES);
		for(int offset = 0; offset < 16; offset +=4)
			for(int x = offset; x < offset+3; x+=2){
				glColor3f(COLOR(RED));
				glVertex3d(hypercube3D(x));
				glVertex3d(hypercube3D(x+1));
			}
	glEnd();
	//Y DELTA RENDERER
	glBegin(GL_LINES);
		for(int offset = 0; offset < 16; offset +=4)
			for(int x = offset; x < offset+2; x++){
				glColor3f(COLOR(GREEN));
				glVertex3d(hypercube3D(x));
				glVertex3d(hypercube3D(x+2));
			}
	//Z DELTA RENDERER
	glBegin(GL_LINES);
		for(int offset = 0; offset < 16; offset +=8)
			for(int x = offset; x < offset+4; x++){
				glColor3f(COLOR(BLUE));
				glVertex3d(hypercube3D(x));
				glVertex3d(hypercube3D(x+4));
			}
	glEnd();
	//W DELTA RENDERER
	glBegin(GL_LINES);
		for(int x = 0; x < 8; x++){
			glColor3f(COLOR(WHITE));
			glVertex3d(hypercube3D(x));
			glVertex3d(hypercube3D(x+8));
		}
	glEnd();
	glPopMatrix();

	glPushMatrix();
		glBegin(GL_LINES);
			//glColor3f(1.0, 0.0, 0.0);
			glColor3f(COLOR(RED));
            glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(3.0, 0.0, 0.0);
		glEnd();
		glBegin(GL_LINES);
			//glColor3f(1.0, 0.0, 0.0);
			glColor3f(COLOR(GREEN));
            glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 3.0, 0.0);
		glEnd();
        glBegin(GL_LINES);
			//glColor3f(1.0, 0.0, 0.0);
			glColor3f(COLOR(BLUE));
            glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, -3.0);
		glEnd();
	glPopMatrix();

	glFlush();
}