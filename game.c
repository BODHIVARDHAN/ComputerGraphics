#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857
 
int c = 0, d = 0, left = 0, right = 0; 
int m = 0, j = 1, flag1 = 0, l = 1, flag2 = 0, n = 0, score = 0, count = 1; 

void myInit (void) 
{ 
	// Reset background color with white (since all three argument is 1.0) 
	glClearColor(0.0, 0.0, 0.0, 0.0); 

	// Set picture color to red (in RGB model) 
	// as only argument corresponding to R (Red) is 1.0 and rest are 0.0 
	//glColor3f(1.0f, 0.0f, 0.0f); 

	// Set width of point to one unit 
	glPointSize(3.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 

	// Set window size in X- and Y- direction 
	gluOrtho2D(-620.0, 620.0, -340.0, 340.0); 
} 

void myDisplay(void) 
{
	int x, y, k; 
	for(float t=0.0;t<1.0;t+=0.05)
        	{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0,1,0); 
		glBegin(GL_QUADS);
                        glVertex2i(-600, -320);
                        glVertex2i(-600, 320);
                        glVertex2i(600, 320);
                        glVertex2i(600, -320);
                glEnd();
		glColor3f(0.1, 0.2, 0.0);
                // these four points draws smaller rectangle which is for catching ball 
                glBegin(GL_QUADS);
                left = -200 + 200 * (d - c);
                right = 200 + 200 * (d - c);
                        glVertex2i(left, -315);
                        glVertex2i(left, -295);
                        glVertex2i(right, -295);
                        glVertex2i(right, -315);
                glEnd();
                glColor3f(0.1, 0.2, 0.0);
                glBegin(GL_QUADS);
                left = -200 + 200 * (d - c);
                right = 200 + 200 * (d - c);
                        glVertex2i(left, 315);
                        glVertex2i(left, 295);
                        glVertex2i(right, 295);
                        glVertex2i(right, 315);
                glEnd();
		glColor3f( 1,0 , 0 );
		glBegin(GL_POLYGON);	
		// i keeps track of angle 
		float i = 0;
	       m = m + 6;
               n = n + 4;	
		while (i <= 2 * pi) 
		{ 
			y = 20 + 20 * cos(i); 
			x = 20 * sin(i); 
			i = i + 0.1; 
			glVertex2i((x - l ), (y - j)); 
		}
		glEnd();
		glBegin(GL_POLYGON);	
                glColor3f( 1,0 , 0 );
       	        i=0;
                while (i <= 2 * pi)
                {
                        y = -100+ 20 * cos(i);
                        x = -30+20 * sin(i);
                        i = i + 0.2;
                        glVertex2i((x - l ), (y - j));
                }
                glEnd();
		glBegin(GL_POLYGON);	
                glColor3f( 1,0 , 0 );
        	i=0;
                while (i <= 2 * pi)
                {
                        y = 10 + 20 * cos(i);
                        x = -200+20 * sin(i);
                        i = i + 0.2;
                        glVertex2i((x - l ), (y - j));
                }
                glEnd();
		glBegin(GL_POLYGON);	
		glColor3f( 0,0 , 1 );
	       i=0;	
		while (i <= 2 * pi) 
		{ 
			y = 220 + 20 * cos(i); 
			x = 20 * sin(i); 
			i = i + 0.2; 
			glVertex2i((x - l ), (y - j)); 
		}
		glEnd();
		glBegin(GL_POLYGON);	
		glColor3f( 0,0 , 1 );
	       i=0;	
		while (i <= 2 * pi) 
		{ 
			y =  20 * cos(i); 
			x = 220 + 20 * sin(i); 
			i = i + 0.2; 
			glVertex2i((x - l ), (y - j)); 
		}
		glEnd();
		glBegin(GL_POLYGON);	
		glColor3f( 0,0 , 1 );
	        i=0;	
		while (i <= 2 * pi) 
		{ 
			y = 60 + 20 * cos(i); 
			x = 60 + 20 * sin(i); 
			i = i + 0.2; 
			glVertex2i((x - l ), (y - j)); 
		}
		glEnd();
		// following condition checks if falling ball is catched on rectangle or not 
		if ((j * m) == 276) 
		{ 
			if ((left > ((-1 * l * n) + 20)) || (right < (-1 * l * n) - 20)) 
			{ 
				printf("Game Over !!!\nYour Score is :\t%d\n", score); 
				exit(0); 
			} 
		} 
		glutSwapBuffers(); 
	} 
} 


// Driver Program 
int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
	// Declares window size 
	glutInitWindowSize(1100, 600); 
	
	// Declares window position which is (0, 0) 
	// means lower left corner will indicate position (0, 0) 
	glutInitWindowPosition(0, 0); 

	// Name to window 
	glutCreateWindow("Game"); 

	// Call to myInit() 
	myInit(); 
	glutDisplayFunc(myDisplay); 
	glutMainLoop(); 
} 

