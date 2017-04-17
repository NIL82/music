#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int xx1,xx2,yy1,yy2;

void drawline(int X1,int Y1, int X2,int Y2)	
{
	int x,y,dx,dy,e;
	int i;
	
	dx=abs(X2-X1);
	dy=abs(Y2-Y1);

	x = X1;
	y = Y1;
	e = 2*dy-dx;
	i=1;
	while(i<=dx)
	{
		glBegin (GL_POINTS);  
                glVertex2i (x, y);  
                glEnd ();  
                glFlush (); 
		while(e>0)
		{
			y=y+1;
			e=e-2*dx;
		}
		x = x+1;
		e = e+2*dy;
		i=i+1;
	}
}
   
void display(void)
{	
	glColor3f(1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawline(xx1,yy1,xx2,yy2);
	glFlush();		
}

int main(int argc,char** argv)
{
	
	printf("\n Enter vertex x1 ");
        scanf("%d",&xx1);
        printf("\n Enter vertex y1 ");
        scanf("%d",&yy1);
        printf("\n Enter vertex x2 ");
        scanf("%d",&xx2);
        printf("\n Enter vertex y2 ");
        scanf("%d",&yy2);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("BResenham Line");
       
        gluOrtho2D(0.0,640.0,0.0,480.0);
		
	glutDisplayFunc(display);
	glutMainLoop();		
	return 0;	
}

