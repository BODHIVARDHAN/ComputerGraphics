#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
double x1[]={0,-500,700,0};
double y2[]={300,200,-200,-300};

double x[]={0,-700,700,-110};
double y[]={-300,-150,200,320};

void myInit (void) 
{ 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    glColor3f(0.0, 1.0, 0.0); 
      
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
      
    gluOrtho2D(-780, 780, -420, 420); 
} 
void display1(void)
{
	for(float t=0.0;t<1.0;t+=0.05)
	{
     		float xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
     		float yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
		printf("%.2f",xt);
		//printf("%.2f",y[0]);
		glBegin( GL_LINE_STRIP );
		glVertex2f(xt,yt);
	}
}
  
void display (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    for(float t=0.0;t<1.0;t+=0.05)
	{
     		float xt=pow(1-t,3)*x1[0]+3*t*pow(1-t,2)*x1[1]+3*pow(t,2)*(1-t)*x1[2]+pow(t,3)*x1[3];
     		float yt=pow(1-t,3)*y2[0]+3*t*pow(1-t,2)*y2[1]+3*pow(t,2)*(1-t)*y2[2]+pow(t,3)*y2[3];
		printf("%.2f",xt);
		//printf("%.2f",y[0]);
		glBegin( GL_LINE_STRIP );
		glVertex2f(xt,yt);
	}
display1();
    glEnd(); 
    glFlush(); 
} 
  
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0); 
      
    glutCreateWindow("Circle Drawing"); 
    myInit(); 
      
    glutDisplayFunc(display); 
    glutMainLoop(); 
} 
