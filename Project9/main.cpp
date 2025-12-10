
/* basics
 *
 * A basic, first OpenGL program.
 *
 * This program illustrates how you open an window, specify its position and size,
 * and draw something in the window.
 *
 * Also illustrated: the state-machine operation of OGL. Notice that if you resize
 * the window, the box becomes blue -- the last color specified! This isn't the right
 * idea! Where should you put the color of the box?
 *
 * When you resize the window so it is not square, the box changes shape. This might
 * not be desired -- we will look into fixing this later. (Keep in mind, this has
 * something to do with the aspect ratio.)
 *
 * Try changing the size of gluOrtho2D -- see in code below -- and you'll see how the
 * relative size of the box changes within the window.
 *
 * See http://www.eas.asu.edu/~cse470/references.html for instruction on how to start
 * your own program
 *
 * Dianne Hansford, August 2004
 */


#include <stdio.h>

 /* Include the GLUT library. This file (glut.h) contains gl.h and glu.h */
#include <GL/glut.h>

/* This is a debug file */
FILE* infofile;

/*
 * The rountine display() gets called each time the window is redrawn.
 */
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(5.0); // Task No. 5 - Change line width

	// Horizontal Line that given in the base code
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(1.0, -0.75);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-1.0, -0.75);
	glEnd();

	glPushMatrix(); 


	glScalef(0.5f, 0.5f, 1.0f);        // Task No. 5 - Change - Scaling the Rectangle
	glColor3f(0.0f, 1.0f, 0.0f);	   // Task No. 1 - Change - Cube color change
	
	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();

	glPopMatrix();

	// Task No. 4 - Added colorful triangle (1 of 2 shapes)
	glPushMatrix();
	glTranslatef(0.4f, 0.2f, 0.0f);   // Task No. 5 – Using Translate Function in order to move the shape to the right
	glScalef(0.7f, 0.7f, 1.0f);// Task No. 5 – Using Scale Function in order to scale the shape to fit between the lines
	glRotatef(-20.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 0.8f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.4f, 0.3f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.4f, 0.3f);
	glEnd();
	glPopMatrix();

	// Task No. 4 - Added colorful pentagon (2 of 2 shapes)
	glPushMatrix();
	glTranslatef(-0.5f, -0.6f, 0.0f); // Task No. 5 – Using Translate Function in order to move the shape to the left
	glScalef(0.4f, 0.4f, 1.0f); //Task No. 5 – Using Scale Function in order to scale the shape to fit between the lines    
	glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.8f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.4f, 0.3f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.25f, -0.2f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-0.25f, -0.2f);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2f(-0.4f, 0.3f);
	glEnd();
	glPopMatrix();


	glPushMatrix();

	//Task No.3 - Added line (1/3)
	glRotatef(90.0, 0.0, 0.0, 1.0);

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(1.0, -0.75);

	glColor3f(0.6, 0.5, 0.0);
	glVertex2f(-1.0, -0.75);
	glEnd();

	glPopMatrix();

	//Task No.3 - Added line (2/3)
	glPushMatrix();

	glRotatef(-90.0, 0.0, 0.0, 1.0);

	glBegin(GL_LINES);
	glColor3f(0.2, 0.3, 1.4);
	glVertex2f(1.0, -0.75);

	glColor3f(0.6, 0.5, 0.4);
	glVertex2f(-1.0, -0.75);
	glEnd();

	glPopMatrix();

	//Task No.3 - Added line (3/3)
	glPushMatrix();

	glTranslatef(0.0, 1.5, 0.0);

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(1.0, -0.75);

	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(-1.0, -0.75);
	glEnd();

	glPopMatrix();

	

	glFlush();
}




/* Initialize states -- called before */

void init()
{
	fprintf(infofile, "init: Entered \n");
	fflush(infofile);


	/* set background clear color to black */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/* set current color to white */
	glColor3f(1.0, 1.0, 1.0);

	/* identify the projection matrix that we would like to alter */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* the window will correspond to these world coorinates */
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

	/* we can play ... see what happens if we swap out this one with that above */
	//gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

	/* identify the modeling and viewing matrix that can be modified from here on */
	/* we leave the routine in this mode in case we want to move the object around */
	/* or specify the camera */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	fprintf(infofile, "init: Exit \n");
	fflush(infofile);
}

/* The main program */

int main(int argc, char** argv)
{
	fopen_s(&infofile, "infofile.txt", "w");
	fprintf(infofile, "basics.c -- a basic OpenGL program\n");
	fflush(infofile);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	// Task No.2 - Change window dimensions and positions
	glutInitWindowSize(1920, 1080); // changed from 500, 500 to full screen 1080p
	glutInitWindowPosition(0, 0); // changed from 200, 200 to top-left corner
	glutCreateWindow("Computed Graphics AAC - ASSIGNMENT #2");

	fprintf(infofile, "Created windows\n");
	fflush(infofile);

	glutDisplayFunc(display);
	init();
	glutMainLoop();
}

