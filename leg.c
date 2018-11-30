#include <stdlib.h>
#include <GL/glut.h>
#include<stdio.h>

#define ROT_INC		0.1

static GLfloat g_rotate = 0;
static GLfloat g_rotInc = ROT_INC;
/*
GLfloat ctrlpoints[4][4][3] ={
   {
     {-0.5, 3.9, 0}, {-2.0, 3.9, 1},
      {2.5, 3.9, 1}, {-0.5, 3.9, 0}},

   {{2.0, -5.0, 0}, {-2.0, -1.0, 1},
    {2.5, -1.0, 1}, {-0.2, -1.0, 0}},

   {{-9.0, -1.0, 0}, {5.0, -5.5, 0},
    {0.0, 1.5, 1}, {-0.1, -2.5, 0}},

   {{-5.0, -3.5, 0}, {3.5, -3.0, 1},
    {-1.5, -2.0, 1}, {-5.0, -3.5, 0}}};*/
GLfloat ctrlpoints[4][4][3] =
    {
   {
     {-0.5, 1.5, 0}, {-2.0, 1.5, 1}, 
      {2.5, 1.5, 1}, {-0.5, 1.5, 0}},    
  
   {{-0.5, 0.5, 0}, {-2.0, 0.5, 1}, 
    {2.5, 0.5, 1}, {-0.5, 0.5, 0}},     
  
   {{-0.1, -0.5, 0}, {-2.0, -0.5, 0},         
    {0, -0.5, 1}, {-0.1, -0.5, 0}}, 
  
   {{-3.0, -1.5, 0}, {-5.5, -1.7, 1},      
    {1.0, -1.7, 1}, {-1.0, -1.5, 0}}
};
/*
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
double surface_point[50][100][3];


int fact(int n) {
  if (n == 0 || n==1)
    return 1;
  return n*fact(n-1);
}

float comb(int n,int i) {
    return  ((float)(fact(n))/(float)(fact(i)*fact(n-i)));
}

float compute_bezier(int n,int b,float u){
  return (comb(n,b)*pow((1-u),(n-b))*pow(u,b));
}

void create_points_on_surf (double b_i_j[5][9][3] , double surface_points[100][100][3]){

  float x,y,z,u=0.0,w=0.0;
  for (int l=0;l<50;l++){
      for(int m=0;m<100;m++) {
          x = 0.0;
          y = 0.0;
          z = 0.0;
          for(int i=0;i<5;i++) {
              for(int j=0;j<9;j++) {
                  x += b_i_j[i][j][0]*compute_bezier(4,i,u)*compute_bezier(8,j,w);
                  y += b_i_j[i][j][1]*compute_bezier(4,i,u)*compute_bezier(8,j,w);
                  z += b_i_j[i][j][2]*compute_bezier(4,i,u)*compute_bezier(8,j,w);
              }
            }
            surface_points[l][m][0] = x;
            surface_points[l][m][1] = y;
            surface_points[l][m][2] = z;
            w+=0.01;
          }
          w=0.0;
          u+=0.02;
        }
}

void plot_surface(double points_arr[50][100][3]){
  for(int j=0;j<50;j++){
    glBegin(GL_POINTS);
    for(int i=0;i<100;i++){
      glVertex3f(points_arr[j][i][0],points_arr[j][i][1],points_arr[j][i][2]);
    }
    glEnd();
    glFlush();
  }
}

void plot_triangle(double points_arr[50][100][3],int n,int m){
  for(int i=0;i<n-1;i++){
    for(int j=0;j<m-1;j++){
      glBegin(GL_TRIANGLES);
      glVertex3f(points_arr[i][j][0],points_arr[i][j][1],points_arr[i][j][2]);
      glVertex3f(points_arr[i+1][j][0],points_arr[i+1][j][1],points_arr[i+1][j][2]);
      glVertex3f(points_arr[i][j+1][0],points_arr[i][j+1][1],points_arr[i][j+1][2]);
      glEnd();
      glFlush();

      glBegin(GL_TRIANGLES);
      glVertex3f(points_arr[i+1][j][0],points_arr[i+1][j][1],points_arr[i+1][j][2]);
      glVertex3f(points_arr[i+1][j+1][0],points_arr[i+1][j+1][1],points_arr[i+1][j+1][2]);
      glVertex3f(points_arr[i][j+1][0],points_arr[i][j+1][1],points_arr[i][j+1][2]);
      glEnd();
      glFlush();
    }
  }
}




void display(){

  glClearColor(0.0,0.0,0.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  gluPerspective(30.0, 1.0, 1.0, 10.0);
    //glMatrixMode(GL_MODELVIEW);
  gluLookAt( 0.0, 0.0, 5.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0);

  glTranslatef(0.0, 0.0, 1.0);
  glRotatef(25, 1.0, 0.0, 0.0);
  glRotatef(10, 0.0, 0.0, 1.0);

  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef( rotate_z, 0.0, 0.0, 1.0 );

  double B_i_j[5][9][3] ={{{0.0,0.5,0.0},{-0.04,0.3,0.0},{-0.02,0.2,0.0},{-0.01,0.0,0.0},{-0.02,-0.2,0.0},{-0.03,-0.4,0.0},{-0.04,-0.5,0.0},{-0.03,-0.7,0.0},{-0.02,-0.9,0.0}},
	  {{0.15,0.5,0.20},{0.15,0.3,0.20},{0.15,0.2,0.20},{0.15,0.0,0.20},{0.15,-0.2,0.20},{0.15,-0.4,0.20},{0.15,-0.5,0.20},{0.15,-0.7,0.20},{0.15,-0.9,0.20}},
	  {{0.18,0.5,0.0},{0.20,0.3,0.0},{0.23,0.2,0.0},{0.21,0.0,0.0},{0.19,-0.2,0.0},{0.17,-0.4,0.0},{0.17,-0.5,0.0},{0.18,-0.7,0.0},{0.18,-0.9,0.0}},

	  {{0.15,0.5,-0.20},{0.15,0.3,-0.20},{0.15,0.2,-0.20},{0.15,0.0,-0.20},{0.15,-0.2,-0.20},{0.15,-0.4,-0.20},{0.15,-0.5,-0.20},{0.15,-0.7,-0.20},{0.15,-0.9,-0.20}},
  {{0.0,0.5,0.0},{-0.04,0.3,0.0},{-0.02,0.2,0.0},{-0.01,0.0,0.0},{-0.02,-0.2,0.0},{-0.03,-0.4,0.0},{-0.04,-0.5,0.0},{-0.03,-0.7,0.0},{-0.02,-0.9,0.0}}};
  create_points_on_surf(B_i_j,surface_point);
glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
  //glColor3f(0,1,0);
  plot_surface(surface_point);
  plot_triangle(surface_point,50,100);
  glutSwapBuffers();

}
*/
  
void display(void)
{
  

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(1.0, 1.0, 1.0, 1.0);
    glScalef(1.0f,1.0f,1.0f);

    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
    glPopMatrix();
   glColor3f(1.0f, 0.5f, 0.0f); 
    glPointSize(5);
    glBegin(GL_LINES);
   glColor3f(1.0f, 0.5f, 0.0f); 
    glVertex2f(0.0, 1.5);
    glVertex2f(-1.0,-1.5);
   glColor3f(1.0f, 0.5f, 0.0f); 
    glEnd();

 glFlush();
}
void myIdleFunc(void) {

	g_rotate += g_rotInc;
	glutPostRedisplay();
}
void myKey(unsigned char c, int x, int y)
{
	switch (c) {
		
	

                case 'l':
                      glRotatef(30.0,1.0f,0.0f,0.0f);
                      break;
                case 'r':
                     glRotatef(-30.0,0.0f,0.0f,1.0f);
                      break;
                
                 case 'u':
                     glRotatef(120.0,0.0f,1.0f,0.0f);
                      break;
                  
                 case 'd':
                     glRotatef(-120.0,0.0f,1.0f,0.0f);
                      break;
                case 'x':
                     glRotatef(-90.0,1.0f,0.0f,0.0f);
                      break;

                
	default:
		//printf("print keys  \n", k);
		break;
	}
}


void myinit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,0, 1, 12, 4, &ctrlpoints[0][0][0]);
    glEnable(GL_MAP2_VERTEX_3);                   
    //glEnable(GL_AUTO_NORMAL);
    //glEnable(GL_NORMALIZE);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glColor3d(0.0,0.0,0.0);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-4.0, 4.0, -4.0 * (GLfloat) h / (GLfloat) w,
            4.0 * (GLfloat) h / (GLfloat) w, -4.0, 4.0);
    else
        glOrtho(-4.0 * (GLfloat) w / (GLfloat) h,
            4.0 * (GLfloat) w / (GLfloat) h, -4.0, 4.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("hand");
    

    myinit();
    glutReshapeFunc(myReshape);
    glutIdleFunc(myIdleFunc);
    
    glutDisplayFunc(display);
    glutKeyboardFunc(myKey);
    glutMainLoop();
    return 0;            
}
