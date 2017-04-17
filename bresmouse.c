#include<stdio.h>
#include <GL/glut.h>  
#include <math.h> 

int xx1,yy1,xx2,yy2;
int first = 0;
int sign(int x)
{
   if(x>0)
	return 1;
   if(x<0)
	return -1;
   return 0;
}

void drawline(int x1, int y1, int x2, int y2)
{
	int dx,dy,x,y,s1,s2,i,flag=0,temp,e;
	dx=abs(x2-x1);
	dy=abs(y2-y1);

	x=xx1;
	y=yy1;

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
}
void mouse(int button, int state, int x, int y)
 {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    {                
    switch(first)  
    {  
        case 0:  
         xx1=x;  
         yy1=y;          
         first=1;
         break;
  
        case 1:  
         xx2=x;  
         yy2=y; 	
                         	       
	glColor3f(1.0,0.0,0.0);
	drawline(xx1,yy1,xx1,yy2);
	drawline(xx1,yy2,xx2,yy2);
	drawline(xx2,yy2,xx2,yy1);
	drawline(xx2,yy1,xx1,yy1);
	
	glColor3f(0.0,1.0,0.0);
	drawline(xx1,(yy1+yy2)/2,(xx1+xx2)/2,yy2);
	drawline((xx1+xx2)/2,yy2,xx2,(yy1+yy2)/2);
	drawline(xx2,(yy1+yy2)/2,(xx1+xx2)/2,yy1);
	drawline((xx1+xx2)/2,yy1,xx1,(yy1+yy2)/2);	

	glColor3f(0.0,0.0,1.0);
	drawline((xx1+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2,(xx2+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2);
	drawline((xx2+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2,(xx2+(xx1+xx2)/2)/2,(yy1+(yy1+yy2)/2)/2);
	drawline((xx2+(xx1+xx2)/2)/2,(yy1+(yy1+yy2)/2)/2,(xx1+(xx1+xx2)/2)/2, (yy1+(yy1+yy2)/2)/2);
	drawline((xx1+(xx1+xx2)/2)/2, (yy1+(yy1+yy2)/2)/2,(xx1+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2);	
        
       glEnd();  
       glFlush(); 
       first=0;  
       break;  
     }  
   }   
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(0.0,640,480.0,0.0); 
        glClear(GL_COLOR_BUFFER_BIT);
	
}

int main(int argc,char** argv)
{    
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("BResenham Line");
	init(); 
        glutMouseFunc(mouse);
	glFlush();
	glutMainLoop();
	return 0;
	
}

