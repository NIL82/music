#include<stdio.h>
#include <GL/glut.h>  
#include <math.h> 

int sign(int x)
{
   if(x>0)
	return 1;
   if(x<0)
	return -1;
   return 0;
}

int main(int argc,char** argv)
{    
	int x1,y1,x2,y2;
	int dx,dy,x,y,s1,s2,len=0,i=1,flag=0,temp,e;
	
	printf("\n Enter vertex 1 ");
	scanf("%d",&x1);
	printf("\n Enter vertex 1 ");
	scanf("%d",&y1);
	printf("\n Enter vertex 1 ");
	scanf("%d",&x2);
	printf("\n Enter vertex 1 ");
	scanf("%d",&y2);
    
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("BResenham Line");
       
        gluOrtho2D(-500,640.0,-500.0,480.0);
	glClear(GL_COLOR_BUFFER_BIT);
	  
        glColor3f(1.0,0.0,0.0);	 
       
	dx=abs(x2-x1);
	dy=abs(y2-y1);

	x=x1;
	y=y1;

	s1 = sign(x2-x1);
	s2 = sign(y2-y1);

	if(dy>dx)
	{
		temp=dy;
		dy=dx;
		dx=dy;
		flag=1;
	}
	else
	flag=0;

	e=2*dy-dx;

	do
	{
		glBegin(GL_POINTS);
		      glVertex2i(x,y);
		glEnd();
		
		while(e>=0)
		{	
		  if(flag==1)
			x=x+s1;
		  else
			y=y+s2;
		  e=e-2*dx;
		}

		if(flag==0)
			x=x+s1;
		else
			y=y+s2;
		e=e+2*dy;
		i++;

	}while(i<=dx);
	
        glFlush();
	glutMainLoop();

	return 0;
	
}
