# include "iGraphics.h"
#include<time.h>
int sx,sy,dx,bdx,bdy,fps,ffps,dy,Dis_x,Dis_y;
int i,frl=1,length=5;
int len=1,slen[1000];
char str[20];
typedef struct point{
	int x;
	int y;
} pnt;
pnt food;
pnt head,s[30];

void Food();



/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	
	iClear();
	if(frl==3){
		iText(400,500,"GAme Over");
	}
		else{
			for(i=0;i<len;i++){
				for(i=length;i>0;i--)
				{
				iShowBMP2(s[i].x,s[i].y,"image\\Snake.bmp",0);
				
				
			}
		

		head.x=s[length].x+8;
		head.y=s[length].y+8;
		Food();
		iSetColor(255,255,0);
		iFilledCircle(food.x,food.y,5);
		sprintf(str,"TOTAl LENgth=%d",length);
		
		iSetColor(255,255,255);
		iText(10,10,str);
		}
		
		
	
		
	
	
	
}


void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}
 

void iKeyboard(unsigned char key)
{
	if(key=='d' && frl==0){
		frl=1;
		dx=5;
	}
	if(key=='a' && frl==0){
		frl=1;
		dx=-5;
	}
	if(key=='w' && frl==1){
		frl=0;
		dy=5;

	}
	if(key=='s' && frl==1){
		frl=0;
		dy=-5;
	}

	//place your codes for other keys here
	
}
 
/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{
 
	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}
void Food()
{
	if(head.x>food.x-8 && head.x<food.x+8 && head.y>food.y-8 && head.y<food.y+8)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%Dis_x;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%Dis_y;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%Dis_x;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%Dis_y;
        if(food.y<=10)
            food.y+=11;
    }
}

void smove(){
	if(frl==1){
		dy=0;
		s[length].x=s[length].x+dx;
		for(i=length;i>0;i--)
		{
			s[i-1].x=s[i].x;
	}
	else {
		dx=0;
		s[length].y=s[length].y+dy
			for(i=length;i>0;i--)
		{
			s[i-1].y=s[i].y;
	}

	}
	if(s[length].x=0 || s[length].x==800 || s[length]y.==0 || s[length].y==600){
		frl=3;
	}
	
}


int main()
{
	
	s[length].x=60;
	s[length].y=60;
	dx=10;
	dy=10;
	Dis_x=800;
	Dis_y=600;
	fps=1000;
	iSetTimer(fps,smove);
	iInitialize(Dis_x,Dis_y,"demooo");
 

	return 0;
}	