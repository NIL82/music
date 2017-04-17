#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int xx1,xx2,yy1,yy2;

int sign(int x)
{
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}
void drawline(double X1,double Y1, double X2,double Y2)	
{
	float x,y,dx,dy,length;
	int i;
	
	dx=abs(X2-X1);
	dy=abs(Y2-Y1);

	if(dx>=dy)
		length=dx;
	else
		length=dy;

	dx=(X2-X1)/length;
	dy=(Y2-Y1)/length;

	x=X1 + 0.5*sign(X1);
	y=Y1 + 0.5*sign(Y1);

	i=1;
	while(i<=length)
	{
		glBegin (GL_POINTS);  
                glVertex2i (x, y);  
                glEnd ();  
                glFlush (); 
		x=x+dx;
		y=y+dy;
		i=i+1;
	}
}
   
void display(void)
{	
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(-1000.0,0.0);
	glVertex2i(500.0,0.0);
	glVertex2i(0.0,-500.0);
	glVertex2i(0.0,1000.0);
	glEnd();

	drawline(xx1,yy1,xx2,yy2);		
}
void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-1000.0,500.0,-500.0,1000.0); 
        glClear(GL_COLOR_BUFFER_BIT);
	
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
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("DDA Line");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	glFlush();	
	return 0;
	
}

