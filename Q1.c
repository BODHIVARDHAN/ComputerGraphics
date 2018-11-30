#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
 
float points1[1000][3];
float points2[1000][3];

void display();


void display(){

  glClearColor(0.0,0.0,0.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  
  glMatrixMode(GL_PROJECTION);
  gluPerspective(30.0, 1.0, 1.0, 10.0);
    
 gluLookAt( 0.0, 0.0, 5.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0);


  glColor3f(0,1,1);
  glBegin(GL_LINE);
  for(int i=0;i<999;i++){
    glVertex3f(points1[i][0],points1[i][1],points1[i][2]);
  }
  glEnd();  
  glFlush();  
  
  glBegin(GL_LINE);
  for(int i=0;i<999;i++){
    glVertex3f(points2[i][0],points2[i][1],points2[i][2]);
  }
  glEnd();    
  glFlush();

  for(int i=0;i<1000;i++){
    glBegin(GL_LINES);
    glVertex3f(points1[i][0],points1[i][1],points1[i][2]);
    glVertex3f(points2[i][0],points2[i][1],points2[i][2]);
    glEnd();    
  }
  glFlush();

  glColor3f(0,1,0);
  
  glBegin(GL_LINES);
  glVertex3f(-0.3,-0.3,-0.3);//|
  glVertex3f(-0.3,0.6,-0.3);
  glEnd();
  
  glBegin(GL_LINES);
  glVertex3f(-0.3,-0.3,-0.3);
  glVertex3f(0.7,-0.3,-0.3);
  glEnd();
glBegin(GL_LINES);
  glVertex3f(-0.3,0.5,-0.3);
  glVertex3f(0.6,0.5,-0.3);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(-0.3,0.6,-0.3);
  glVertex3f(0.7,0.6,-0.3);
  glEnd();

  
  glBegin(GL_LINES);//
  glVertex3f(0.4,0.3,-0.3);
  glVertex3f(-0.3,0.3,-0.3);
  glEnd();
glBegin(GL_LINES);
  glVertex3f(0.5,0.4,-0.3);
  glVertex3f(-0.3,0.4,-0.3);
  glEnd();

  glBegin(GL_LINES);
  glVertex3f(0.3,0.3,0.3);
  glVertex3f(0.3,-0.3,0.3);
  glEnd();
	glBegin(GL_LINES);
  glVertex3f(0.4,0.4,0.3);
  glVertex3f(0.4,-0.3,0.3);
  glEnd();

glBegin(GL_LINES);
  glVertex3f(0.5,0.5,0.3);
  glVertex3f(0.5,-0.3,0.3);
  glEnd();

glBegin(GL_LINES);
  glVertex3f(0.6,0.6,0.3);
  glVertex3f(0.6,-0.3,0.3);
  glEnd();


  glFlush();
  glutSwapBuffers();
 
}
  
int main(int argc, char* argv[]){
 
  glutInit(&argc,argv);
 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (1000, 1000);
  glutInitWindowPosition (100, 100);
  glutCreateWindow("Q1");
 
  glutDisplayFunc(display);
 
 
  glutMainLoop();
 
  return 0;
 
}
