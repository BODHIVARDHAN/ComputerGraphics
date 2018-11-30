#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h>
#include<time.h> 
#define pi 3.142857

//for bottom curve 
int timme;
double x[]={500,300,-300,-500};
double y[]={-320,-400,-400,-300};
//for left curve
double xx1[]={-500,-400,-300,0};
double yy1[]={-300,-200,-100,-350};
//for upper right
double xxxx1[]={-200,250,200,-0};
double yyyy1[]={300,150,0,-350};
//upper left cuve
double xxxx[]={0,-300,150,-200};
double yyyy[]={-350,-150,150,300};
//right curve
double xxx[]={0,300,400,520};
double yyy[]={-350,-100,-200,-340};
float i=0;
void myInit (void)
{ 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    glColor3f(0.0, 1.0, 0.0); 
      
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
      
    gluOrtho2D(-780, 780, -420, 420); 
} 

void display (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_LINE_STRIP);
    for(float t=0.0;t<1.0;t+=0.05)
	{
		float xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
     		float yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
		//printf("%.2f",xt);
		glVertex2f(xt,yt);
	}
	for(float t=0.0;t<1.0;t+=0.05)
        {
                float xt=pow(1-t,3)*xx1[0]+3*t*pow(1-t,2)*xx1[1]+3*pow(t,2)*(1-t)*xx1[2]+pow(t,3)*xx1[3];
                float yt=pow(1-t,3)*yy1[0]+3*t*pow(1-t,2)*yy1[1]+3*pow(t,2)*(1-t)*yy1[2]+pow(t,3)*yy1[3];
                //printf("%.2f",xt);
                //printf("%.2f",y[0]); 
                //glBegin( GL_LINE_STRIP );
                glVertex2f(xt,yt);
        }
	for(float t=0.0;t<1.0;t+=0.05)
        {
                float xt=pow(1-t,3)*xxxx[0]+3*t*pow(1-t,2)*xxxx[1]+3*pow(t,2)*(1-t)*xxxx[2]+pow(t,3)*xxxx[3];
                float yt=pow(1-t,3)*yyyy[0]+3*t*pow(1-t,2)*yyyy[1]+3*pow(t,2)*(1-t)*yyyy[2]+pow(t,3)*yyyy[3];
                //printf("%.2f",xt);
                //printf("%.2f",y[0]); 
                //glBegin( GL_LINE_STRIP );
		//glvertex2f(xt,yt);
                glVertex2f(xt*i,yt);
        }
	for(float t=0.0;t<1.0;t+=0.05)
        {
                float xt=pow(1-t,3)*xxxx1[0]+3*t*pow(1-t,2)*xxxx1[1]+3*pow(t,2)*(1-t)*xxxx1[2]+pow(t,3)*xxxx1[3];
                float yt=pow(1-t,3)*yyyy1[0]+3*t*pow(1-t,2)*yyyy1[1]+3*pow(t,2)*(1-t)*yyyy1[2]+pow(t,3)*yyyy1[3];
                //printf("%.2f",xt);
                //printf("%.2f",y[0]); 
                //glBegin( GL_LINE_STRIP );
                glVertex2f(xt*i,yt);
        }
	for(float t=0.0;t<1.0;t+=0.05)
        {
                float xt=pow(1-t,3)*xxx[0]+3*t*pow(1-t,2)*xxx[1]+3*pow(t,2)*(1-t)*xxx[2]+pow(t,3)*xxx[3];
                float yt=pow(1-t,3)*yyy[0]+3*t*pow(1-t,2)*yyy[1]+3*pow(t,2)*(1-t)*yyy[2]+pow(t,3)*yyy[3];
                //printf("%.2f",xt);
                //printf("%.2f",y[0]); 
                glVertex2f(xt,yt);
        }
	i=i+0.005;
	if(i>1){
		i=1;
	}
	glutSwapBuffers();
    glEnd();
    glFlush(); 
}
void delay(){
	display();
	glutTimerFunc(40,delay,1);
}
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0); 
      
    glutCreateWindow("Right Drawing"); 
    myInit(); 
      
    glutDisplayFunc(display); 
    glutTimerFunc(40,delay,1); 
glutPostRedisplay(); 
    glutMainLoop(); 
} 
