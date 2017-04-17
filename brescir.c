#include<stdio.h>
#include <GL/glut.h>

void putpixel (int x, int y)  
{  
 
   glBegin (GL_POINTS);  
   glVertex2i (x, y);  
   glEnd ();  
   glFlush (); 
}
 
int main(int argc, char **argv)
{
     
  int x,y,r,d,x1,y1;

  printf("\nEnter the radius");
  scanf("%d",&r);
  printf("\nEnter the center ");
  scanf("%d%d",&x1,&y1);
  
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
  glutInitWindowPosition(100,100);
  glutInitWindowSize(640,640);
  glutCreateWindow("bresenham_circle");
  gluOrtho2D(0.0,800.0,0.0,800.0);
  glClear(GL_COLOR_BUFFER_BIT);

  d=3-2*r;
  x=0;
  y=r;

  do
  {
	putpixel(x+x1,y+y1);
	putpixel(y+x1,x+y1);
	putpixel(-x+x1,y+y1);
	putpixel(y+x1,-x+y1);
	putpixel(-x+x1,-y+y1);
	putpixel(-y+x1,-x+y1);
	putpixel(x+x1,-y+y1);
	putpixel(-y+x1,x+y1);

	if(d<0)
	{
		x++;
		d=d+4*x+6;
	}
	else
	{
		x++;
		y--;
		d=d+4*(x-y)+10;
	}
 }while(x<=y);
 
 glFlush();
 glutMainLoop();
 return 0;
}
