#include<stdio.h>
#include <GL/glut.h>
#include<math.h>

void putpixel (int x, int y)  
{  
   glColor3f(1.0, 0.0, 0.0);
   glBegin (GL_POINTS);  
   glVertex2i (x, y);  
   glEnd ();  
   glFlush (); 
} 


int main(int argc, char **argv)
{

  float x,y,r,x1,y1,x2,y2,E,xc,yc,i,val;           // E is float 
  printf("\nEnter the radius");
  scanf("%f",&r);
  printf("\nEnter the center ");
  scanf("%f%f",&xc,&yc);
  
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
  glutInitWindowPosition(100,100);
  glutInitWindowSize(640,640);
  glutCreateWindow("dda_circle");
  gluOrtho2D(0.0,600.0,0.0,480.0);
  glClear(GL_COLOR_BUFFER_BIT);

  x=0;
  y=r;
  x1=x;
  y1=y;

  i=0;
  do
  {
    val=pow(2,i);
    i++;
  }while(val<r);
  i--;
  
  E=i/pow(2,i-1); 

  do
  {
    x2=x1+E*y1;
    y2=y1-E*x2;

    putpixel(x2+xc,y2+yc);
    
    x1=x2;
    y1=y2;
   }while((y1-y)<E ||(x-x1)>E);

   glFlush (); 
   glutMainLoop();
   return 0; 
}


