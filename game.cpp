#include<stdio.h>
//#include<stdafx.h>
#include<glut.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


int d1 = 0, d2 = 0, floor = 0,up=0,count=0,spin=0,mul=1,sph=0;
int flag[3] = { 0, 0, 0 };
int shift[3] = { 0, 0, 0 };
clock_t end;
clock_t start;
void *currentfont;
void setFont(void *font)
{
	currentfont = font;                      // Set the currentfont to the font
}
void drawstring(float x, float y, float z, char *string)
{
	char *c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		glColor3f(0.0, 0.0, 0.0);
		glutBitmapCharacter(currentfont, *c);
	}
}



void roomback()
{

	glBegin(GL_LINE_LOOP);
	glVertex2f(20, 20);
	glVertex2f(20, -20);
	glVertex2f(-20, -20);
	glVertex2f(-20, 20);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(20, 20);
	glVertex2f(40, 40);
	glVertex2f(20, -20);
	glVertex2f(40, -40);
	glVertex2f(-20, -20);
	glVertex2f(-40, -40);
	glVertex2f(-20, 20);
	glVertex2f(-40, 40);
	glEnd();
	glFlush();
	
}
void hex()
{
	
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-2.5, -10 - 15+up);
	glVertex2f(2.5, -10 - 15+up);
	glVertex2f(5, -15 - 15+up);
	glVertex2f(2.5, -20 - 15+up);
	glVertex2f(-2.5, -20 - 15+up);
	glVertex2f(-5, -15 - 15+up);
	glEnd();
	

}
void room(int floor)
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	if (floor == 0)
	{
		
		
		glClearColor(0, 0, 0, 1);
		setFont(GLUT_BITMAP_TIMES_ROMAN_24);
		glColor3f(1, 0, 0);
		drawstring(-13, 10, 0, "QUICK CLICKS");

		setFont(GLUT_BITMAP_HELVETICA_12); //Font set to helvetica with size 12
		glColor3f(0, 0, 1);
		drawstring(-25, 0, 0, "Click your way through three levels as fast as you can to win!");
		glFlush();

	}
	if (floor == 1)
	{
		start = clock();
		roomback();
		glBegin(GL_POLYGON);
		glVertex2f(10, 10);
		glVertex2f(10, -10);
		glVertex2f(-10, -10);
		glVertex2f(-10, 10);
		glEnd();
		glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(2, 2);
		glVertex2f(2, -2);
		glVertex2f(-2, -2);
		glVertex2f(-2, 2);
		glEnd();
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glVertex2f(2, -7);
		glVertex2f(2, -3);
		glVertex2f(-2, -3);
		glVertex2f(-2, -7);
		glEnd();
		glColor3f(0, 1, 0);
		glBegin(GL_POLYGON);
		glVertex2f(2, 3);
		glVertex2f(2, 7);
		glVertex2f(-2, 7);
		glVertex2f(-2, 3);
		glEnd();
		glFlush();
		
	}
	if (floor == 2)
	{
		roomback();
		
		glColor3f(0.9, 0.7, 0);
		glLineWidth(4);
		glBegin(GL_LINES);
		glVertex2f(0, -30);
		glVertex2f(0, 30);
		glEnd();
		
		hex();
		
		glFlush();
			
	}
	if (floor == 3)
	{
		
		
		roomback();
		glPopMatrix();
		glRotatef(0+spin, 0, 0, 1);
		glColor3f(0, 0, 1);
		
		glBegin(GL_POLYGON);
		glVertex2f(5*mul, 5*mul);
		glVertex2f(5*mul, -5*mul);
		glVertex2f(-5*mul, -5*mul);
		glVertex2f(-5*mul, 5*mul);
		glEnd();
		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-40, 40, -40, 40, -40, 40);
		glMatrixMode(GL_MODELVIEW);
		
	}
	if (floor == 4)
	{
		GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_shininess[] = { 50.0 };
		GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
		glClearColor(1, 1.0, 1.0, 0.0);
		glShadeModel(GL_SMOOTH);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_DEPTH_TEST);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glutSolidSphere(10, 100, 100);
		
		glFlush();
		
	}
	if (floor == 5)
	{
		end = clock();
		setFont(GLUT_BITMAP_TIMES_ROMAN_24);
		glColor3f(1, 0, 0);
		
		char s[100];
		char str[100] = "COMPLETED IN ";
		char strr[100] = " seconds.";
		sprintf_s(s, "%4.2f", (float)(end - start) / CLOCKS_PER_SEC);
		strcat_s(str, s);
		strcat_s(str, strr);
		drawstring(-20, 10, 0,str );

	}
	glPopAttrib();

}
void door1()
{
	glBegin(GL_POLYGON);
	printf("polygon\n");
	glVertex2f(-40+d1, 40);
	glVertex2f(0+d1, 40);
	glVertex2f(0+d1, -40);
	glVertex2f(-40+d1, -40);
	glEnd();
	glFlush();
}
void door2()
{
	glBegin(GL_POLYGON);
	glVertex2f(0+d2, 40);
	glVertex2f(40+d2, 40);
	glVertex2f(40+d2, -40);
	glVertex2f(0+d2, -40);
	glEnd();
	glFlush();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	room(floor);
	door1();
	door2();
	

}
void idleclose()
{
	if (d1 == 0)
	{
		floor++;
		glutPostRedisplay();
		glutIdleFunc(NULL);

	}
	else
	{
		d1 += 1;
		d2 -= 1;
		printf("%d\n", d1);
		printf("%d\n", d2);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		printf("came here\n");


		glClear(GL_COLOR_BUFFER_BIT);
		room(floor);

		door1();
		door2();
	}
}
void idleopen()
{
	if (d1 == -40)
	{
		
		glutIdleFunc(NULL);

	}
	else
	{
		d1 -= 1;
		d2 += 1;
		printf("%d\n", d1);
		printf("%d\n", d2);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		for (int j = 0; j < 1000000; j++);
		printf("came here\n");
		
		
		glClear(GL_COLOR_BUFFER_BIT);
		room(floor);
		
		door1();
		door2();
	}
}
void mouse(int b, int s, int x, int y)
{
	
	if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
			glutIdleFunc(idleopen);

	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
	{
		if (floor == 0)
		{
			glutIdleFunc(idleclose);
		}
		if (floor == 1){
			printf("\nx=%d,y=%d", x, y);
			if (x >= 236 && x <= 259 && y >= 206 && y <= 227)
			{
				printf("green picked");
				d1 = -40;
				d2 = 40;
				glutIdleFunc(idleclose);
			}
		}
		if (floor == 2)
		{
			
			up += 10;
			glutPostRedisplay();
			count++;
			if (count == 6)
				glutIdleFunc(idleclose);
		}
		if (floor == 3)
		{
			spin += 60;
			mul += 1;
			printf("\nspin=%d", spin);
			if (spin == 360)
				glutIdleFunc(idleclose);
            glutPostRedisplay();
		}
		if (floor == 4)
		{
			
			
			sph++;
			glMatrixMode(GL_MODELVIEW);
			glRotatef(20, 1, 0, 0);
			glutPostRedisplay();
			if (sph==18)
			 glutIdleFunc(idleclose);
		}
		if (floor == 5)
		{
			
			exit(0);
		}
		
	}
	
		
	
}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-40, 40, -40, 40, -40, 40);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game");
	glutDisplayFunc(display);
	glutIdleFunc(NULL);
	glutMouseFunc(mouse);
	myinit();

	glutMainLoop();
}
