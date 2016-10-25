# include "iGraphics.h"
#include<time.h>
int sx,sy,dx,bdx,bdy,fps,dy,Dis_x,Dis_y,frls=1;
int i,j,k,frl=1,length=4,flen=0,fsmove=0;
int color_v,pp=1,lxx=80,sfoodsec=9,flag_sfood=1,flag_sfood2=0,speed_increase;
int no_length=1,score=0,f_img_move=0,update_var;
FILE *sf;
float img_dx,img_dy;
char str[20];
int lx,ly;

typedef struct point{
	int x;
	int y;
} pnt;
pnt food,sfood;

pnt head,sn[50];




void Food();
void SFOOD();
void smove(){
	if(update_var==0){if(frl==2){if(frls==1){
		dy=0;
		sx=sx+dx;
	}
	else {
		dx=0;
		sy+=dy;

	}
	if(sx<=0 || sx>=810 || sy<=-10 || sy>=610){
		frl=3;
	}

	if(flen==1){for(j=length-1;j>0;j--){
		sn[j]=sn[j-1];
	}

		
	}
	sn[0].x=sx;
	sn[0].y=sy;
				if(flen==0){sn[1].x=sx-10;
				sn[1].y=sy;
				sn[2].x=sx-20;
				sn[2].y=sy;
				sn[3].x=sx-30;
				sn[3].y=sy;
				flen=1;}
	}}
	if(update_var==1){
		sf=fopen("save.txt","r");
		fscanf(sf,"%d %d ",&sx,&sy);
		//fscanf(sf,"%d",&sy);
		sn[0].x=sx;
		sn[0].y=sy;
		fscanf(sf,"%d ",&length);
		for(i=1;i<length;i++){
			fscanf(sf,"%d %d ",&sn[i].x,&sn[i].y);
		}
		
		fscanf(sf,"%d ",&frls);
		fscanf(sf,"%d ",&dx);
		fscanf(sf,"%d ",&dy);
		fscanf(sf,"%d ",&food.x);
		fscanf(sf,"%d ",&food.y);
		fscanf(sf,"%d ",&score);
		fscanf(sf,"%d ",&speed_increase);

		fclose(sf);
		//frl=2;
		fsmove=0;
		update_var=0;
		//printf("YEEEEEESSSS....................");
	}
	color_v=color_v+(pp)*15;
	if(color_v>=245 || color_v<=0){pp=pp*-1;}
	
}

void iDraw()
{
	//place your drawing codes here	
	iClear();
	if(frl==3){
		iText(40,500,"Game Over",GLUT_BITMAP_HELVETICA_18);
		iSetColor(255-color_v,color_v,color_v);
		iText(40,400,"Press r to restart",GLUT_BITMAP_HELVETICA_18);
	}
	else if(frl==10){
			//iFilledCircle(200,200,7);
		if(f_img_move==0)
		{iShowBMP(img_dx,img_dy,"image\\snake_menu.bmp");}
		else{
			iShowBMP(0,0,"image\\snake_menu2.bmp");
			iSetColor(255-color_v,255-color_v,color_v);
			iLine(25,320,245,320);
			iSetColor(255-color_v,255-color_v,color_v);
			iLine(25,260,245,260);
			iSetColor(255-color_v,255-color_v,color_v);
			iLine(25,200,265,200);
			iSetColor(255-color_v,255-color_v,color_v);
			iLine(25,135,265,135);
			iSetColor(255-color_v,255-color_v,color_v);
			iLine(25,76,150,76);

		}
	}
	
		else if(frl==2){
			if (fsmove==0){smove();
			
			fsmove=1;}
			for(i=0;i<length;i++){
				
				//smove();
				for(k=1;k<length;k++){
					if(sn[0].x==sn[k].x && sn[0].y==sn[k].y)frl=3;
				}
				/*sn[1].x=sx-10;
				sn[2].x=sx-20;
				sn[3].x=sx-30;*/
			
					iShowBMP2(sn[i].x,sn[i].y,"image\\Snake.bmp",1);
					
			}
			//iFilledCircle(sn[i].x,sn[i].y,8);
			
			head.x=sx+8;
		head.y=sy+8;
		Food();
		//
		for(i=0;i<length;i++){
			if(sn[i].x+8>food.x-12 && sn[i].x+8<food.x+12 && sn[i].y+8>food.y-12 && sn[i].y+8<food.y+12){
			time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%(Dis_x-30);
        if(food.x<=10){
			food.x+=15;}
        food.y=rand()%(Dis_y-30);
		if(food.y<=10){

			food.y+=15;}
		
			}
		}

		//

		iSetColor(255,255,0);
		iFilledCircle(food.x,food.y,6);
		if(no_length==1){if((length)>=6 && (length)%6==0 ){
			if(flag_sfood2==0){flag_sfood=0;flag_sfood2=1;}
		if(sfoodsec==0 ){flag_sfood=1;
		sfoodsec=9;
		no_length=0;
		flag_sfood2=0;
		
		}
		else {
		SFOOD();
		iSetColor(255-color_v,255-color_v,255-color_v);
		iFilledCircle(sfood.x,sfood.y,10);}
		
		}}

		sprintf(str,"TOTAl Score=%d %d",length-4,score);
		
		iSetColor(255,255,255);
		iText(10,10,str);
				
				
				
		}
		else if(frl==22){
			
		iText(200,200,"TTTTTTTTT");
		}
		else if(frl==1) {

			iShowBMP(0,0,"image\\Snake_front.bmp");
			iSetColor(255-color_v,255-color_v,255-color_v);
			iText(18,25,"Press any key to continue");
			


			
			

		}

		
		}
		
		
	
		
	
	
	



void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(frl==10 && mx>25 && mx<245 && my>=320 && my<=380){
			sx=60;
	   sy=60;
	   score=0;
	  frls=1;
	  dx=10;
	dy=10;
	length=4;
	flen=0;
	speed_increase=0;
			fsmove=0;
			frl=2;}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(frl==10 && mx>25 && mx<245 && my>=260 && my<=319)
			{update_var=1;
		frl=2;}
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}
 

void iKeyboard(unsigned char key)
{	
	if(frl==2 && key=='k'){
		sf=fopen("save.txt","w+");
		fprintf(sf,"%d ",sx);
		fprintf(sf,"%d ",sy);
		fprintf(sf,"%d ",length);
		
		for(i=1;i<length;i++){
			fprintf(sf,"%d %d ",sn[i].x,sn[i].y);
		}
		
		fprintf(sf,"%d ",frls);
		fprintf(sf,"%d ",dx);
		fprintf(sf,"%d ",dy);
		fprintf(sf,"%d ",food.x);
		fprintf(sf,"%d ",food.y);
		fprintf(sf,"%d ",score);
		fprintf(sf,"%d ",speed_increase);
		fclose(sf);
		//printf("Yesssssssss");
			

	}
	if(key=='l'){
		//printf("anyyyyy");
		//sf=fopen("save.txt","r");
		//fscanf(sf,"%d",&sx);
		//fscanf(sf,"%d",&sy);
		//sn[0].x=sx;
		//sn[0].y=sy;
		//fscanf(sf,"%d",&length);
		//for(i=1;i<length;i++){
		//	fscanf(sf,"%d %d",&sn[i].x,&sn[i].y);
		//}
		//
		//fscanf(sf,"%d",&frls);
		//fscanf(sf,"%d",&dx);
		//fscanf(sf,"%d",&dy);
		//fscanf(sf,"%d",&food.x);
		//fscanf(sf,"%d",&food.y);

		//fclose(sf);
		////frl=2;
		//fsmove=0;
		//printf("YEEEEEESSSS....................");

		update_var=1;
		
	}
	if(key=='d' && frls==0){
		frls=1;
		dx=(10+speed_increase);
	}
	if(key=='a' && frls==0){
		frls=1;
		dx=-(10+speed_increase);
	}
	if(key=='w' && frls==1){
		frls=0;
		dy=(10+speed_increase);

	}
	if(key=='s' && frls==1){
		frls=0;
		dy=-(10+speed_increase);
	}
	if(frl==3 && key=='r'){
		sx=60;
	   sy=60;
	   score=0;
	  frls=1;
	  dx=10;
	dy=10;
	length=4;
	flen=0;
	speed_increase=0;
			fsmove=0;
		
		
		frl=2;}
	if(frl==1 && key>0 && key<255){frl=10;}


	if(key=='p'){
		//printf("anyyyyyy");
		iPauseTimer(0);}
	if(key== 'R')iResumeTimer(0);

	if(key=='m')frl=10;
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
void SFOOD(){
	
		if(head.x>sfood.x-12 && head.x<sfood.x+12 && head.y>sfood.y-12 && head.y<sfood.y+12)
    {
        length++;
		
		score+=50;

		flag_sfood=1;
		fsmove=0;
		sfoodsec=9;
		no_length=0;
		flag_sfood2=0;
        time_t a;
        a=time(0);
        srand(a);
        sfood.x=rand()%Dis_x;
        if(sfood.x<=15){
			sfood.x+=20;}
        sfood.y=rand()%Dis_y;
		if(sfood.y<=15){

			sfood.y+=20;}


    }
    else if(sfood.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {	 time_t a;
        a=time(0);
        srand(a);
        sfood.x=rand()%Dis_x;
        if(sfood.x<=15)
            sfood.x+=20;
        sfood.y=rand()%Dis_y;
        if(sfood.y<=15)
            sfood.y+=20;
    }
		for(i=0;i<length;i++){
			if(sn[i].x+8>food.x-14 && sn[i].x+8<food.x+14 && sn[i].y+8>food.y-14 && sn[i].y+8<food.y+14){
			time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%(Dis_x-30);
        if(food.x<=10){
			food.x+=15;}
        food.y=rand()%(Dis_y-30);
		if(food.y<=10){

			food.y+=15;}
		
			}
		}
	}


void Food()
{   
	if(head.x>food.x-12 && head.x<food.x+12 && head.y>food.y-12 && head.y<food.y+12)
    {
        length++;
		score+=10;
		if(length>35)speed_increase=8;
		else if(length>25)speed_increase=6;
		else if(length>15)speed_increase=4;
		else if(length>10)speed_increase=2;
		if(length>=40)frl=22;
		fsmove=0;
		no_length=1;
		flag_sfood=1;
		sfoodsec=9;
		flag_sfood2=0;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%(Dis_x-30);
        if(food.x<=10){
			food.x+=15;}
        food.y=rand()%(Dis_y-30);
		if(food.y<=10){

			food.y+=15;}

		
    }
    else if(food.y==0 || food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {	time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%(Dis_x-30);
        if(food.x<=10)
            food.x+=15;
        food.y=rand()%(Dis_y-30);
        if(food.y<=10)
            food.y+=15;
    }
	
	for(i=0;i<length;i++){
			if(sn[i].x+8>food.x-12 && sn[i].x+8<food.x+12 && sn[i].y+8>food.y-12 && sn[i].y+8<food.y+12){
			time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%(Dis_x-30);
        if(food.x<=10){
			food.x+=15;}
        food.y=rand()%(Dis_y-30);
		if(food.y<=10){

			food.y+=15;}
		
			}
		}
	
}



void sfoodtime(){
		if(flag_sfood==0){
			
				sfoodsec--;
	}
		//printf("%d %d\n",sfoodsec,flag_sfood);
}
void imgmove(){
	if(frl==10){
	if(img_dx<248){
		img_dx+=1;
		if(img_dx>=248){f_img_move=1;iPauseTimer(2);}
	}
	
	if(img_dy>0){
		img_dy=img_dy-.5;
	}
	}
}
int main()
{
	
	sx=60;
	sy=60;
	dx=10;
	dy=10;
	Dis_x=800;
	Dis_y=600;
	color_v=1;
	img_dx=0;

	img_dy=108;
	fps=100;
	iSetTimer(fps,smove);
	iSetTimer(1000,sfoodtime);
	iSetTimer(10,imgmove);
	

	iInitialize(Dis_x,Dis_y,"demooo");
 

	return 0;
}	