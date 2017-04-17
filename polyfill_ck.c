#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

typedef struct pixel
{
	GLubyte red,green,blue;
}pixel;

pixel c,d,boundary,fill;     // objects of pixel

int count=0,ch=1,X,Y;

struct vertex
{
	int x,y;
}v[10];


void Init()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1,1,1,0);
  gluOrtho2D(0 , 800 , 0 , 700);
}

 int sign(int a)
 {
 if(a>=0)
 return 1;
 else 
 return -1;
 }
 
void breshnam(int xp1,int yp1,int xp2,int yp2)
{
 int x,y,dx,dy,dx2,dy2,sdx,sdy,steps,pk,i;
 char str[10];
 dx=xp2-xp1;
 dy=yp2-yp1;
 if(abs(dy)>abs(dx))
 {
  steps=abs(dy);
  if(yp1<yp2)
  {
   x=xp1;y=yp1;
  }
  else
  {
   x=xp2;y=yp2;
   dx=xp1-xp2;dy=yp1-yp2;
  }
  
   dx2=2*abs(dx);
   dy2=2*abs(dy);
   sdx=sign(dx);
   sdy=sign(dy);
   
  pk=dx2-abs(dy);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  
  for(i=0;i<steps;i++)
  {
   if(pk<0)
   {
    y++;
    pk=pk+dx2;
   }
   else
   {
    y++;x=x+sdx;
    pk=pk+dx2-dy2;
   }
   glVertex2i(x,y);
  }
 
  glEnd();
  glFlush();
 }
 
 else
 {
  steps=abs(dx);
  if(xp1<xp2)
  {
   x=xp1;y=yp1;
  }
  else
  {
   x=xp2;y=yp2;
   dx=xp1-xp2;dy=yp1-yp2;
  }
  
   dx2=2*abs(dx);
   dy2=2*abs(dy);
   sdx=sign(dx);
   sdy=sign(dy);
   
  pk=dy2-abs(dx);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  
  for(i=0;i<steps;i++)
  {
   if(pk<0)
   {
    x++;
    pk=pk+dy2;
   }
   else
   
   {
    y=y+sdy;x++;
    pk=pk+dy2-dx2;
   }
   glVertex2i(x,y);
  }
  glEnd();
  glFlush();
 }
}


 void boundary_fill(int x,int y,pixel b,pixel f)
{
	glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&c);
	if(c.red!=b.red && c.green!=b.green && c.blue!=b.blue && c.red!=f.red && c.green!=f.green && c.blue!=f.blue)
	{
		glColor3ub(f.red,f.green,f.blue);
		glBegin(GL_POINTS);
  		glVertex2i(x,y);
		glEnd();
		glFlush();

		boundary_fill(x+1,y,b,f);
		boundary_fill(x-1,y,b,f);
		boundary_fill(x,y+1,b,f);
		boundary_fill(x,y-1,b,f);		
	}
}
void polygon()
{
int i;
glColor3ub(10,10,10);
 for(i=0;i<count-1;i++)
 {
  breshnam(v[i].x,v[i].y,v[i+1].x,v[i+1].y);
 }
 breshnam(v[i].x,v[i].y,v[0].x,v[0].y);
}



void mouse(int btn,int state,int x,int y)
{
int ymax=glutGet(GLUT_WINDOW_HEIGHT);
 if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
 {
  v[count].x=x;
  v[count].y=ymax-y;
  count++;
 } 
  
 if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
 {
     
	switch(ch)
	{
case 1:
	X=x;
 	Y=ymax-y;
	glReadPixels(X,Y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&d);
	fill.red = d.red;
	fill.green = d.green;
	fill.blue = d.blue;
 	polygon();	
      	ch=2;
	break;
case 2:
	X=x;
 	Y=ymax-y;
	boundary_fill(X,Y,boundary,fill);
	break;
	}
 }
}

void draw()
{
        glClear(GL_COLOR_BUFFER_BIT );
	glBegin(GL_QUADS);
		glColor3ub(100,150,250);glVertex2i(100,100);glVertex2i(150,100);glVertex2i(150,150);glVertex2i(100,150);
		glColor3ub(0,0,100);glVertex2i(151,100);glVertex2i(200,100);glVertex2i(200,150);glVertex2i(151,150);
		glColor3ub(0,100,0);glVertex2i(201,100);glVertex2i(250,100);glVertex2i(250,150);glVertex2i(201,150);
		glColor3ub(0,100,100);glVertex2i(251,100);glVertex2i(300,100);glVertex2i(300,150);glVertex2i(251,150);
		glColor3ub(100,0,0);glVertex2i(301,100);glVertex2i(350,100);glVertex2i(350,150);glVertex2i(301,150);
		glColor3ub(100,0,100);glVertex2i(351,100);glVertex2i(400,100);glVertex2i(400,150);glVertex2i(351,150);
		glColor3ub(100,100,0);glVertex2i(401,100);glVertex2i(450,100);glVertex2i(450,150);glVertex2i(401,150);
		glColor3ub(175,175,100);glVertex2i(451,100);glVertex2i(500,100);glVertex2i(500,150);glVertex2i(451,150);
		glColor3ub(175,0,0);glVertex2i(501,100);glVertex2i(550,100);glVertex2i(550,150);glVertex2i(501,150);
		glColor3ub(0,175,0);glVertex2i(551,100);glVertex2i(600,100);glVertex2i(600,150);glVertex2i(551,150);
		glColor3ub(0,0,175);glVertex2i(601,100);glVertex2i(650,100);glVertex2i(650,150);glVertex2i(601,150);
		glColor3ub(175,0,175);glVertex2i(651,100);glVertex2i(700,100);glVertex2i(700,150);glVertex2i(651,150);        
 	glEnd();
glFlush();
}


int main(int argc,char ** argv)
{

	boundary.red = 10;
	boundary.green = 10;
	boundary.blue = 10;
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(800,700);
   glutCreateWindow("mouse click");
  Init();
  glutMouseFunc(mouse);
  glutDisplayFunc(draw);													
  glutMainLoop();
return 0;
}

