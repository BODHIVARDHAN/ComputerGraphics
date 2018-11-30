// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
  
// function to initialize 
double x[]={0,-500,-500,0};
double y[]={300,500,-500,-300};

//double xx[]={0,500,550,-100};
//double yy[]={-300,-500,550,275};

void myInit (void) 
{ 
    // making background color black as first  
    // 3 arguments all are 0.0 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    // making picture color green (in RGB mode), as middle argument is 1.0 
    glColor3f(0.0, 1.0, 0.0); 
      
    // breadth of picture boundary is 1 pixel 
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
      
    // setting window dimension in X- and Y- direction 
    gluOrtho2D(-780, 780, -420, 420); 
} /*
void display1 (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    for(float t=0.0;t<1.0;t+=0.05)
	{
		float xt = (1 - t) * (1 - t) * p[0].x + 2 * (1 - t) * t * p[1].x + t * t * p[2].x;
		float yt = (1 - t) * (1 - t) * p[0].y + 2 * (1 - t) * t * p[1].y + t * t * p[2].y;
  
     		//float xt=pow(1-t,3)*xx[0]+3*t*pow(1-t,2)*xx[1]+3*pow(t,2)*(1-t)*xx[2]+pow(t,3)*xx[3];
     		//float yt=pow(1-t,3)*yy[0]+3*t*pow(1-t,2)*yy[1]+3*pow(t,2)*(1-t)*yy[2]+pow(t,3)*yy[3];
		printf("%.2f",xt);
		//printf("%.2f",y[0]);
		glBegin( GL_LINE_STRIP );
		glVertex2f(xt,yt);
	}

    glEnd(); 
    glFlush(); 
} */
void display (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    for(float t=0.0;t<1.0;t+=0.05)
	{
     		float xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
     		float yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
		//printf("%.2f",x[0]);
		//printf("%.2f",y[0]);
		glBegin( GL_LINE_STRIP );
		glVertex2f(xt,yt);
	}
	
//display1();
    glEnd(); 
    glFlush(); 
} 
  
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    // giving window size in X- and Y- direction 
    glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0); 
      
    // Giving name to window 
    glutCreateWindow("Ass_2 Drawing"); 
    myInit(); 
      
    glutDisplayFunc(display); 
    glutMainLoop(); 
}
