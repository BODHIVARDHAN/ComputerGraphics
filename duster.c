#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

double rotate_y=0; 
double rotate_x=0;
double rotate_z=0;

void display(){
  
  glClearColor(1.0,1.0,1.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  
  glMatrixMode(GL_PROJECTION);
  gluPerspective(30.0, 1.0, 1.0, 10.0);
  gluLookAt( 0.0, 0.0, 5.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0);

  glTranslatef(0.0, 0.0, 1.0);
  glRotatef(25, 1.0, 0.0, 0.0);
  glRotatef(10, 0.0, 0.0, 1.0);
 
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef( rotate_z, 0.0, 0.0, 1.0 );

///////////////////////////////////////////////////////////////////////////////////////////
  glColor3f(0.0 ,0.0 ,0.0);
  glBegin(GL_LINES);
  glVertex3f(0.3,0.2,0.2);
  glVertex3f(0.3,0.2,-0.2);
  glEnd();

  glBegin(GL_LINES);
  glVertex3f(-0.3,0.2,0.2);
  glVertex3f(-0.3,0.2,-0.2);
  glEnd();
 
  
  glBegin(GL_LINES);
  glVertex3f(0.3,0.2,-0.2);
  glVertex3f(-0.3,0.2,-0.2);
  glEnd();

  glBegin(GL_LINES);
  glVertex3f(-0.3,0.2,0.2);
  glVertex3f(0.3,0.2,0.2);
  glEnd();
////////////////////////////////////////////////////////////////////////////////////////////

  glColor3f(0.0,0.0,0);
  glBegin(GL_LINES);
  glVertex3f(0.5,0.1,-0.2);
  glVertex3f(0.3,0.2,-0.2);
  glEnd();
  
  glBegin(GL_LINES);
  glVertex3f(-0.5,0.1,-0.2);
  glVertex3f(-0.3,0.2,-0.2);
  glEnd();

  glBegin(GL_LINES);
  glVertex3f(0.5,0.1,0.2);
  glVertex3f(0.3,0.2,0.2);
  glEnd();

  glBegin(GL_LINES);
  glVertex3f(-0.5,0.1,0.2);
  glVertex3f(-0.3,0.2,0.2);
  glEnd();
///////////////////////////////////////////////////////////////////////////////////////////
  glColor3f(0,0,0);
  glBegin(GL_LINES);
  glVertex3f(0.5,0.1,0.2);
  glVertex3f(0.5,0.1,-0.2);
  glEnd();
  
  glBegin(GL_LINES);
  glVertex3f(0.5,-0.1,0.2);
  glVertex3f(0.5,-0.1,-0.2);
  glEnd();
 
  glBegin(GL_LINES);
  glVertex3f(-0.5,0.1,0.2);
  glVertex3f(-0.5,0.1,-0.2);
  glEnd();

  glBegin(GL_LINES);
  glVertex3f(-0.5,0.1,0.2);
  glVertex3f(0.5,0.1,0.2);
  glEnd();
  
  glBegin(GL_LINES);
  glVertex3f(-0.5,-0.1,-0.2);
  glVertex3f(-0.5,0.1,-0.2);
  glEnd();
  
  glBegin(GL_LINES);
  glVertex3f(0.5,0.1,-0.2);
  glVertex3f(0.5,-0.1,-0.2);
  glEnd();
  
  glBegin(GL_LINES);
  glVertex3f(-0.5,-0.1,-0.2);
  glVertex3f(0.5,-0.1,-0.2);
  glEnd();
  
  glBegin(GL_LINES);
  glVertex3f(-0.5,-0.1,-0.2);
  glVertex3f(-0.5,-0.1,0.2);
  glEnd();
  
  glBegin(GL_LINES);
  glVertex3f(-0.5,0.1,0.2);
  glVertex3f(-0.5,-0.1,0.2);
  glEnd();

  glBegin(GL_LINES);
  glVertex3f(0.5,0.1,-0.2);
  glVertex3f(-0.5,0.1,-0.2);
  glEnd();

  glBegin(GL_LINES);
  glVertex3f(-0.5,-0.1,0.2);
  glVertex3f(0.5,-0.1,0.2);
  glEnd();

  glBegin(GL_LINES);
  glVertex3f(0.5,0.1,0.2);
  glVertex3f(0.5,-0.1,0.2);
  glEnd();

  glFlush();
  glutSwapBuffers();
 
}
 
void specialKeys( int key, int x, int y ) {
 
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
 
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
 
  glutPostRedisplay();
 
}
 
int main(int argc, char* argv[]){
 
  glutInit(&argc,argv);
 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (1000, 1000);
  glutInitWindowPosition (100, 100);
  glutCreateWindow("Assign_Duster");
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
  glutMainLoop();
  return 0;
}
