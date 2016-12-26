# include "iGraphics.h"
#include<stdio.h>
#include<stdlib.h>
#include <shellapi.h>
#include<iostream.h>
int pause_ckr=0;
char temp_name[20]="_";
int mposx,mposy;
int ckx=450, cky=30;
int game_saving;
int cksx=1, cksy=1;
static int blink_count=0;
int timer,rad;
int i,j;
int pause_save;
int loading_number=0;
int tn,cn;
bool turn=0;
char my_key;
char show_time[3];
char saved_names[5][20];
char name[30];
int menu_check=0;
int mousex,mousey;
int score;
int len;
bool mode;
bool welcome;
char username[30];
bool game_over=true;
void blink_text();
void not_game();

int paused=1;


char scrstr[7];

char scrscr[7];
int rannx=150,ranny=130;

double chhx[4],chhy[4];

int hand=0;
double manl1x[4],manl1y[4],manl2x[4],manl2y[4];
struct
{
	int x,y;
	double r,b,g;
}man;



float ckspd=1;
float carspd=.5;
float trkspd=.5;
int bmpckr;


int score1=0;

void version1(void);
void truckl(void);
void carr(void);
void chicken();
void dclr(void);
void chickenckr();
void showtimef();
void menu();

int new_game=0;
void scoring(void);
void mann(void);
void radius(void);
void scoring_ct();
int lane,temp,wing,life=3,start_time=90;
void help(void);
void iSpecialKeyboard(unsigned char key);
void save_game();
void load_game();
void game_overf();
void pausef();
void reset();
void High_scoref();
struct 
{
	float x,y;
	
	double spd;

	float xdis, ydis;
	
	double red,green,blue;
	
} autor[6],autol[6];
double trix[10],triy[10];
void scoring_ct();
void iSetcolor(double x,double y, double z);

void iDraw()
{
	
	FILE *naming;
	naming=fopen("names.bin","r");
	for(int ii=0;ii<5;ii++)
	{
		fscanf(naming,"%s",saved_names[i]);
		if(feof(naming)) break;
	}
	fclose(naming);
	//remove("names.bin");
	
	
		if(menu_check==0) menu();
		else if(menu_check==1)
		{
			if(paused==0) pausef();
			else version1();
		}
		else if(menu_check==3) help();
		else if(menu_check==2) load_game();
		else if(menu_check==4) not_game();
		else if(menu_check==5) save_game();
		else if(menu_check==6) High_scoref();
		



		//if(game_over=false) game_overf();

		
		
	
	
}

void iMouseMove(int mx, int my)
{
	
}
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//printf("%d %d\n",mx,my);
		PlaySound("typewriter_click.wav",NULL,SND_ASYNC);
		mousex=mx;
		mousey=my;
		printf("%d\t%d\n",ckx,cky);
		//printf(" %d %d %d %d %d %d %d %d ",turn,ckx,cky,rannx,ranny,cksx,cksy,score);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		/*if(menu_check==-1)*/ menu_check=0;
		reset();
		for(int ii=0;ii<30;ii++) {username[ii]=NULL; name[ii]=NULL;}
			//memset(username,0,sizeof (char));
		
		
		
	}
}


void iPassiveMouseMove(int mx, int my)
{
	//place your codes here
	//iShowBMP(mx,my,"mouse_p.bmp");
	mposx=mx;
	mposy = my;
}

void iKeyboard(unsigned char key)
{
	PlaySound("haha.wav",NULL,SND_ASYNC);
	

	if(menu_check==1&&paused==1)
	{
		if(tolower(key)=='p')
		{
			paused=0;
		}
		if(toupper(key) == 'Q')
		{
			menu_check=0;
			mousex=-50;
			game_over=false;
			reset();
		}
	//	else paused=1;
	}
	if(menu_check==1)
	{
		
		 if(toupper(key)=='A')
		{
			
			if(ckx>31)
				ckx-=5;
			turn=1;
			cksx=-1;
			wing++;
			
		}
		else if(toupper(key)=='D')
		{
			if(ckx<869)
				ckx+=5;
			turn=1;
			cksx=1;
			wing++;
			;
		}
		else if(toupper(key)=='W')
		{
			if(cky<569)
				cky+=5;
			cksy=1;
			turn=0;
			wing--;
			
		}
		else if(toupper(key)=='X')
		{
			if(cky>31)
				cky-=5;
			cksy=-1;
			turn=0;
			wing--;
			
		}
		else if(toupper(key)=='H')
		{
			if(menu_check==0){ /*hand=0;*/ menu_check=3;}
		}
	}
			
		my_key=key;
/*	if(pause_ckr==1)
	{
		if(key==13)
		{
			pause_save=1;
			my_key=0;
		}
	}*/
	if(menu_check==0)
	{
		if(tolower(key)==13)
		{
			if(paused)
			{
				if(bmpckr==2){ exit(0);
				printf(" %d ",bmpckr);}
				else if(bmpckr==0)
				{
					 menu_check=1;
					 start_time=90;
					 //reset();
					

				}
				else if(bmpckr==1)
				{
					menu_check=2;
					loading_number=1;
					iClear();
				}
			}
			/*if(paused==1)
			{
				if(pause_ckr==0 ) { paused=1;my_key=0;}
				else if(pause_ckr==1) { my_key=0;save_game();}
				else if(pause_ckr==2) { my_key=0; reset();}

			}*/
		}
		
	}
	if(menu_check==2 || (menu_check==5) || menu_check==6)
	{
		if(!mode)
		{
			username[len++]=toupper(key);
			if(key==8) {len-=2; username[len]=0;
			username[len+1]=NULL;}
			if(key==13) {mode=1; len--; username[len]=NULL;}
			strcpy(temp_name,username); strcat(temp_name,"_");
		}
	}
}
void iSpecialKeyboard(unsigned char key)
{
	PlaySound("haha.wav",NULL,SND_ASYNC);
	//if(paused==0) paused=1;
	if(key == GLUT_KEY_END) exit(0);
	if(menu_check!=1)
	{
		
		if(key== GLUT_KEY_DOWN) bmpckr++;
		if(key == GLUT_KEY_UP) bmpckr--;
		if(key == GLUT_KEY_LEFT) 
		{
			if(hand==1) hand=0;
		}
		if(key == GLUT_KEY_RIGHT) 
		{
			if(hand==0) hand=1;
		}

		if(bmpckr>2) bmpckr=2;
		if(bmpckr<0) bmpckr=0;
	}
	else if(menu_check==1)
	{
		if(key == GLUT_KEY_UP) 
		{
			my_key='W';
			if(cky<569)
				cky+=5;
			cksy=1;
			turn=0;
			wing--;
			
		}
		if(key == GLUT_KEY_DOWN) {
			my_key='X';
			if(cky>31)
				cky-=5;
			cksy=-1;
			turn=0;
			wing--;
		}
		if(key == GLUT_KEY_LEFT){
			my_key='A';
			if(ckx>31)
				ckx-=5;
			turn=1;
			cksx=-1;
			wing++;
		}
		if(key == GLUT_KEY_RIGHT){
			my_key='D';
				if(ckx<869)
				ckx+=5;
			turn=1;
			cksx=1;
			wing++;
		}
	}
	if(paused==0)
	{
		if(key== GLUT_KEY_LEFT) pause_ckr--;
		if(key == GLUT_KEY_RIGHT) pause_ckr++;
		if(pause_ckr>2) pause_ckr=2;
		if(pause_ckr<0) pause_ckr=0;

	}
}

int main()
{
	ShellExecute(NULL,"open","start.MID",0,0,0);
	dclr();
	//start_time=150;
	

	
	iSetTimer(1000, showtimef);
	iSetTimer(0,scoring);
	iSetTimer(50,radius);
	iSetTimer(600,blink_text);

		
	

	iInitialize(900, 600, "ROAD CROSSING");
	return 0;
}	
void version1(void)
{
	//*if(toupper(my_key)!='Q')
	//{
	//PlaySound("typewriter_click.wav",NULL,SND_ASYNC);

	iClear();
	
		
	iSetcolor(.1,.1,0);
	iFilledRectangle(0,0,900,600);
	
	iSetcolor(1,.5,.2);
	iFilledRectangle(0,296,900,8);
	iFilledRectangle(0,80,900,4);
	iFilledRectangle(0,516,900,4);
	
	iSetcolor(1,.5,.2);

	for(lane=6;lane<930;lane+=30)
		iFilledRectangle(lane,64,14,16);
	
	for(lane=2;lane<930;lane+=30)
		iFilledRectangle(lane,520,14,16);

	iSetcolor(.51,.31,.41);
	iFilledRectangle(0,0,920,64);
	iFilledRectangle(0,537,920,64);
	
	

	iSetcolor(.81,.511,.81);
	for(lane=-6;lane<934;lane+=60)
		iFilledRectangle(lane,189,56,2);
	for(lane=-12;lane<934;lane+=60)
		iFilledRectangle(lane,409,56,2);

	iSetcolor(0,.2,0.4);
	iLine(0,64,900,64);
	iLine(0,80,900,80);
	iLine(0,520,900,520);
	iLine(0,536,900,536);			// road


	iSetcolor(1,.5,.2);
	iSetColor(0,0,0);
	iFilledRectangle(0,0,209,65);
	iFilledRectangle(0,538,209,100);
	iShowBMP(0,550,"score.bmp");


	
	chicken();
	truckl();
	carr();
	chickenckr();
	scoring_ct();

	scoring();

	

	iSetcolor(1,1,1);
	iText(30,40,"LIFE:",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(30,10,"TIME:",GLUT_BITMAP_TIMES_ROMAN_24);

	iShowBMP(0,0,"time.bmp");
	iSetcolor(1,1,1);
	for(i=0;i<life;i++)
		iFilledCircle(100+i*25,47,10,100);
	if(start_time<-1)
		menu_check=6;
	int start_time1=start_time;
	int score_x=140;
	int score_y=5,ch;
	for(int ii=0;ii<4;ii++)
	{
		ch=start_time1%10;
		switch(ch)
		{
			case 0:
			{
				iShowBMP(score_x,score_y,"0.bmp");
				score_x-=32;
				break;
			}
			case 1:
			{
				iShowBMP(score_x,score_y,"1.bmp");
				score_x-=32;
				break;
			}
			case 2:
			{
				iShowBMP(score_x,score_y,"2.bmp");
				score_x-=32;
				break;
			}
			case 3:
			{
				iShowBMP(score_x,score_y,"3.bmp");
				score_x-=32;
				break;
			}
			case 4:
			{
				iShowBMP(score_x,score_y,"4.bmp");
				score_x-=32;
				break;
			}
			case 5:
			{
				iShowBMP(score_x,score_y,"5.bmp");
				score_x-=32;
				break;
			}
			case 6:
			{
				iShowBMP(score_x,score_y,"6.bmp");
				score_x-=32;
				break;
			}
			case 7:
			{
				iShowBMP(score_x,score_y,"7.bmp");
				score_x-=32;
				break;
			}
			case 8:
			{
				iShowBMP(score_x,score_y,"8.bmp");
				score_x-=32;
				break;
			}
			case 9:
			{
				iShowBMP(score_x,score_y,"9.bmp");
				score_x-=32;
				break;
			}

		}
		start_time1/=10;

		if(start_time1==0) break;



	}
}
/*************************************** code for game *******************************************/


void truckl(void)
{
	for(i=0;i<3;i++)
	{
		iSetcolor(autol[i].red,.2,0.6);
		iFilledRectangle(autol[i].x,autol[i].y+8,58,36);
		iFilledCircle(autol[i].x+8,autol[i].y+8,8,200);
		iFilledCircle(autol[i].x+8,autol[i].y+44,8,200);
		iFilledRectangle(autol[i].x+8,autol[i].y,50,8);
		iFilledRectangle(autol[i].x+8,autol[i].y+44,50,8);
		iFilledRectangle(autol[i].x+162,autol[i].y+6,6,40);

		iSetcolor(0,0,0);

		iRectangle(autol[i].x+26,autol[i].y+6,32,40);

		iSetcolor(1,1,1);
		iFilledRectangle(autol[i].x+18,autol[i].y+6,8,40);
		iSetcolor(.3,autol[i].green,1);

		iFilledRectangle(autol[i].x+58,autol[i].y+4,2,44);
		iFilledRectangle(autol[i].x+60,autol[i].y-2,104,56);

		iSetcolor(1,1,0);
		iFilledRectangle(autol[i].x-2,autol[i].y+4,2,16);
		iFilledRectangle(autol[i].x-2,autol[i].y+30,2,16);



		if(autol[i].x<-150)
		{
			autol[i].x=950;
			do
			{
				autol[i].y=rand();
				
			}while(autol[i].y<84||autol[i].y>136 && autol[i].y<308 || autol[i].y>358);
			
				autol[i].red=rand()/10000;
		
		autol[i].green=rand()/14000;
		
		autol[i].blue=rand()/28000;
			
		}
		else
		{
			if(paused!=0)
			autol[i].x-=autol[i].spd;
		}
		
	}


}
/**************************************** code for drawing truck *******************************/


void carr(void)
{
	for(i=3;i<6;i++)
	{

		iSetcolor(autor[i].red,autor[i].green,autor[i].blue);
		
		trix[0]=autor[i].x+0 , triy[0]=autor[i].y+2 ;
		trix[1]=autor[i].x+21 , triy[1]=autor[i].y ;
		trix[2]=autor[i].x+21 , triy[2]=autor[i].y+52 ;
		trix[3]=autor[i].x+0 , triy[3]=autor[i].y+50 ;

		iFilledPolygon(trix,triy,4);

		iFilledRectangle(autor[i].x+21,autor[i].y,61,52);

		
		trix[0]=autor[i].x+82 , triy[0]=autor[i].y ;
		trix[3]=autor[i].x+82 , triy[3]=autor[i].y+52 ;
		trix[1]=autor[i].x+115 , triy[1]=autor[i].y+1 ;
		trix[2]=autor[i].x+115 , triy[2]=autor[i].y+50 ;
		

		iFilledPolygon(trix,triy,4);

		iSetcolor(1,1,1);

		trix[0]=autor[i].x+10 , triy[0]=autor[i].y+8 ;
		trix[1]=autor[i].x+18 , triy[1]=autor[i].y+6 ;
		trix[2]=autor[i].x+18 , triy[2]=autor[i].y+46 ;
		trix[3]=autor[i].x+10 , triy[3]=autor[i].y+44 ;

		iFilledPolygon(trix,triy,4);

		
		trix[0]=autor[i].x+82 , triy[0]=autor[i].y+6 ;
		trix[3]=autor[i].x+82 , triy[3]=autor[i].y+46 ;
		trix[1]=autor[i].x+94 , triy[1]=autor[i].y+7 ;
		trix[2]=autor[i].x+94 , triy[2]=autor[i].y+44 ;
		

		iFilledPolygon(trix,triy,4);

		iSetcolor(0,0,0);
		iRectangle(autor[i].x+27,autor[i].y+6,48,40);
	



		if(autor[i].x>900)
		{
			autor[i].x=-100;
			do
			{
				autor[i].y=rand();
				
			}while(autor[i].y<192|| autor[i].y>244 && autor[i].y< 414 || autor[i].y > 464 ) ;
	
				
			do
			{
				autor[i].x=-(rand()*rand()%109);
			}	while(fabs(autor[i-1].x-autor[i].x)<90 && fabs(autor[i].x-autor[i-1].x)<50 && autor[i].x>0 && autor[i].x<-30 &&fabs(autor[i+1].x-autor[i].x)<90);

			
			autol[i].red=rand()/10000;
		
		autol[i].green=rand()/14000;
		
		autol[i].blue=rand()/24000;
		}

			
		else
		{
			if(paused!=0)
			autor[i].x+=autor[i].spd;
		}

	}






}
//*************************************** code for drawing car ***********************************/


void chicken()
{

	if(turn)
	{
		iSetcolor(1,0,0);
		
	
		iFilledCircle(ckx+20*cksx,cky,10,100);
		



		chhx[0]=double(ckx-20);
		chhx[1]=double(ckx);
		chhx[2]=double(ckx+20);
		chhx[3]=double(ckx);

		chhy[0]=double(cky);
		chhy[1]=double(cky+20);
		chhy[2]=double(cky);
		chhy[3]=double(cky-20);
		iSetcolor(1,1,1);

		iFilledPolygon(chhx,chhy,4);

		iSetcolor(.7,.25,.75);

		

		iFilledEllipse(ckx,cky,8,14,100);

		
	}

	else
	{
		
	
	
		iSetcolor(1,0,0);
		
	
		iFilledCircle(ckx,cky+20*cksy,10,100);
			iFilledCircle(ckx+1,cky,rad,100);

		chhx[0]=double(ckx-20);
		chhx[1]=double(ckx);
		chhx[2]=double(ckx+20);
		chhx[3]=double(ckx);

		chhy[0]=double(cky);
		chhy[1]=double(cky+20);
		chhy[2]=double(cky);
		chhy[3]=double(cky-20);
		iSetcolor(1,1,1);

		iFilledPolygon(chhx,chhy,4);
	

		iSetcolor(.7,.25,.75);

		

		iFilledEllipse( ckx, cky,14,8,100);
		
		
	}
	
	iSetcolor(0,0,0);
		
	iFilledCircle(ckx,cky,rad,100);
	iSetcolor(1,0,0);
		

	
	


}
//******************************** code for showing chicken ****************************************/


void dclr(void)
{
	mode=0;
	for(i=0;i<3;i++)
	{
		do
		{
			autol[i].y=rand();	
		
		
		}while(autol[i].y<84||autol[i].y>136 && autol[i].y<304 || autol[i].y>464);

		do
		{
			autol[i].x=rand();	
		
		
		}while(autol[i].x<-10 || autol[i].x>900);

		autol[i].spd=trkspd;
		autol[i].xdis=170;
		autol[i].ydis=52;

		
		autol[i].red=rand()/10000;
		
		autol[i].green=rand()/14000;
		
		autol[i].blue=rand()/28000;
		


		


	
	
	
	}


	for(i=3;i<6;i++)
	{
		do
		{
			autor[i].y=rand();	
		
		
		}while(autor[i].y<194||autor[i].y>244 && autor[i].y<414 || autor[i].y>462);

		do
		{
			autor[i].x=rand();	
		
		
		}while(autor[i].x<-15 || autor[i].x>900 || (autor[i].x-autor[i-1].x)<100);

		autor[i].spd=carspd;
		autor[i].xdis=115;
		autor[i].ydis=52;
		autor[i].red=rand()/10000;
		
		autor[i].green=rand()/14000;
		
		autor[i].blue=rand()/28000;
		


	
	
	
	}
	



}
//********************************************** Declaration code *************************************/


void chickenckr()
{
	if(paused!=0)
	{
	if(life)
	{
		iSetcolor(1,0,0);
		for(i=0;i<3;i++)
		{
			if(toupper(my_key)=='D'||toupper(my_key)=='A')
			{
				if(ckx<=autol[i].x)	
				{
					if(fabs(ckx-autol[i].x)<=28)				
						if(cky>=autol[i].y)
						{
							if(fabs(cky-autol[i].y)<=20+autol[i].ydis)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
							
								life--;
								
								ckx=450;
								cky=30;
								
							}
						}
						else
						{
							if(fabs(cky-autol[i].y)<=20)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								
								ckx=450;
								cky=30;
							}
							
						
						}
				}
						
					
				else
				{
					if(fabs(ckx-autol[i].x)<=28+autol[i].xdis)
						if(cky>=autol[i].y)
						{
							if(fabs(cky-autol[i].y)<=20+autol[i].ydis)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								
								ckx=450;
								cky=30;
							}
						}
						else
						{
							if(fabs(cky-autol[i].y)<=20)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								
								ckx=450;
								cky=30;
							}
						
						}
				
				}
			
			}



			if(toupper(my_key)=='W'||toupper(my_key)=='X')
			{
				if(ckx<=autol[i].x)	
				{
					if(fabs(ckx-autol[i].x)<=20)				
						if(cky>=autol[i].y)
						{
							if(fabs(cky-autol[i].y)<=28+autol[i].ydis)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								
								ckx=450;
								cky=30;
							}
						}
						else
						{
							if(fabs(cky-autol[i].y)<=28)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								
								ckx=450;
								cky=30;
							}
							
						
						}
				}
						
					
				else
				{
					if(fabs(ckx-autol[i].x)<=20+autol[i].xdis)
						if(cky>=autol[i].y)
						{
							if(fabs(cky-autol[i].y)<=28+autol[i].ydis)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								
								ckx=450;
								cky=30;
							}
						}
						else
						{
							if(fabs(cky-autol[i].y)<=28)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								
								ckx=450;
								cky=30;
							}
						
						}
				
				}
			
			}





			
		
		}





		for(i=3;i<6;i++)
		{
			if(toupper(my_key)=='D'||toupper(my_key)=='A')
			{
				if(ckx<=autor[i].x)	
				{
					if(fabs(ckx-autor[i].x)<=28)				
						if(cky>=autor[i].y)
						{
							if(fabs(cky-autor[i].y)<=20+autor[i].ydis)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								ckx=450;
								cky=30;

							}
						}
						else
						{
							if(fabs(cky-autor[i].y)<=20)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								ckx=450;
								cky=30;
							}
							
						
						}
				}
						
					
				else
				{
					if(fabs(ckx-autor[i].x)<=28+autor[i].xdis)
						if(cky>=autor[i].y)
						{
							if(fabs(cky-autor[i].y)<=20+autor[i].ydis)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								ckx=450;
								cky=30;
							}
						}
						else
						{
							if(fabs(cky-autor[i].y)<=20)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								ckx=450;
								cky=30;
							}
						
						}
				
				}
			
			}



			if(toupper(my_key)=='W'||toupper(my_key)=='X')
			{
				if(ckx<=autor[i].x)	
				{
					if(fabs(ckx-autor[i].x)<=20)				
						if(cky>=autor[i].y)
						{
							if(fabs(cky-autor[i].y)<=28+autor[i].ydis)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								ckx=450;
								cky=30;
							}
						}
						else
						{
							if(fabs(cky-autor[i].y)<=28)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								ckx=450;
								cky=30;
							}
							
						
						}
				}
						
					
				else
				{
					if(fabs(ckx-autor[i].x)<=20+autor[i].xdis)
						if(cky>=autor[i].y)
						{
							if(fabs(cky-autor[i].y)<=28+autor[i].ydis)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
								
								life--;
								ckx=450;
								cky=30;
							}
						}
						else
						{
							if(fabs(cky-autor[i].y)<=28)
							{
								PlaySound("scream2.wav",NULL,SND_ASYNC);
							
								life--;
								ckx=450;
								cky=30;
							}
						}
				
				}
			
			}





			
		
		}



		if(!life)
		{
			iText(410,275,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
			
		
		
		}
		if(cky>=550)
		{
			PlaySound("applause3.wav",NULL,SND_ASYNC);
			iDelay(1);
			cky=30;
			life++;;
		}



	}
	else 
	{
		
		iText(410,275,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
		
		iDelay(2);
		menu_check=0;
		
		lane=0;
		temp=0;
		wing=0;
		life=3;
		start_time=90;
		ckx=450; cky=30;
		cksx=1; cksy=1;
		i=0;j=0;;
		tn=0;cn=0;
		turn=0;
		my_key=0;;
		
		mousex=0;mousey=0;
	
	}
	}
}

/******************************** Checking chicken for accident ********************************/
void showtimef()
{

	show_time[0]=(start_time/10)+48;
	show_time[1]=(start_time%10)+48;
	show_time[2]='\0';
	//iSetcolor(1,0,0);
	if(menu_check==1&&paused!=0)
		  start_time--;
	
	if(start_time<-1) menu_check=6;
		
}

/************************** Code for showing time *************************/
void menu()
{
	iShowBMP(10,0,"bmpckr1.bmp");

	iSetcolor(0,0,0);
	iFilledRectangle(0,0,900,600);
	iShowBMP(772,536,"gelp.bmp");
	iSetcolor(0,0,0);

	

	if((bmpckr%3)==0)
	{
		iShowBMP(290,100,"newgamer.bmp");
		
	}
	if((bmpckr%3)==1)
	{
		iShowBMP(290,100,"loadgamer.bmp");
		
	
	}
	if((bmpckr%3)==2)
	{
		iShowBMP(290,100,"exiter.bmp");
	}

//	iShowBMP(271,60,"INSTRUCTION2.bmp");


	
		
	if(mousex>=317 && mousey>=136 && mousex<484 && mousey<177)			//exit
	{
		exit(0);
		mousex=900;
		mousey=600;
	}

	else if(mousex>=317 && mousey>=190 && mousex<484 && mousey<230)   //load game
	{
		menu_check=2;
		loading_number=1;
		iClear();
		mousex=900;
		mousey=600;
	}

	else if(mousex>=317 && mousey>=244 && mousex<484 && mousey<281)		//new game
	{
		//reset();
		score=0;
		start_time=90;
		menu_check=1;
		mousex=900;
		mousey=600;
		//reset();
	}
	else if(mousex>772&&mousey>536) menu_check=3;


	if(mposx>=317 && mposy>=136 && mposx<484 && mposy<177)			//exit
	{
		bmpckr=2;
	}

	else if(mposx>=317 && mposy>=190 && mposx<484 && mposy<230)   //load game
	{
		bmpckr=1;
		
		
	}

	else if(mposx>=317 && mposy>=244 && mposx<484 && mposy<281)		//new game
	{
		bmpckr=0;
	}
	else if(mposx>772&&mposy>536)
	{
		iShowBMP(772,536,"help_passive.bmp");
	}
	
	


}
//********************************* SHOWS THE MENU ******************************************************//




void help(void)
{
	iClear();
	if(hand==0)
	{
		//if(hand==0)
			iShowBMP(300,114,"help1.bmp");
		iShowBMP(150,180,"helptop2.bmp");
	
		if(mousex>605 && mousex<650 && mousey>180 &&mousey<200)
		{
			hand=1;
			//mousex=-50; mousey=-50;
		}
	}
	
	if(hand==1)
	{
		iShowBMP(150,180,"helptop1.bmp");
		if(mousex>554 && mousex<598 && mousey>180 &&mousey<200)
		{
			hand=0;
			//mousex=-50; mousey=-50;
		}
	}

	iShowBMP(370,0,"back.bmp");
	if(mousex<490 && mousey<64 && mousex>377 )
	{
			menu_check=0;
			hand=0;
	}
	if(mposx<490 && mposy<64 && mposx>377 )
	{
		iShowBMP(370,0,"back2.bmp");
	}

}
/******************************** HELP WINDOW ************************************************/

void scoring(void)
{

	int ch;
	int score_x=176;
	int score_y=560;
	score1=score;
	for(int ii=0;ii<4;ii++)
	{
		ch=score1%10;

		



		switch(ch)
		{
		case 0:
			{
				iShowBMP(score_x,score_y,"0.bmp");
				score_x-=32;
				break;
			}
			case 1:
			{
				iShowBMP(score_x,score_y,"1.bmp");
				score_x-=32;
				break;
			}
			case 2:
			{
				iShowBMP(score_x,score_y,"2.bmp");
				score_x-=32;
				break;
			}
			case 3:
			{
				iShowBMP(score_x,score_y,"3.bmp");
				score_x-=32;
				break;
			}
			case 4:
			{
				iShowBMP(score_x,score_y,"4.bmp");
				score_x-=32;
				break;
			}
			case 5:
			{
				iShowBMP(score_x,score_y,"5.bmp");
				score_x-=32;
				break;
			}
			case 6:
			{
				iShowBMP(score_x,score_y,"6.bmp");
				score_x-=32;
				break;
			}
			case 7:
			{
				iShowBMP(score_x,score_y,"7.bmp");
				score_x-=32;
				break;
			}
			case 8:
			{
				iShowBMP(score_x,score_y,"8.bmp");
				score_x-=32;
				break;
			}
			case 9:
			{
				iShowBMP(score_x,score_y,"9.bmp");
				score_x-=32;
				break;
			}

		}
		score1/=10;

		if(score1==0) break;

	}

	





}
/********************************* SHOWS THE SCORE **************************/

void radius()
{
	static int pp=0;
	pp++;
/*	if(pp%3==0) rad=1;
	if(pp%3==1) rad=1;
	if(pp%3==2)*/ rad=3;


}
void scoring_ct()
{
	
 
	if(rannx==0 && ranny==0)
	{
		PlaySound("whah_whah.wav",NULL,SND_ASYNC);
		ranny=rand()%485+85;
		rannx=rand()%850+5;
	}
	else
	{
		iSetcolor(0,1,.1);
		iFilledCircle(rannx,ranny,10,100);
		if(abs(rannx-ckx)<25 && abs(ranny-cky)<25)
		{
			
			
			score=score+10;
			rannx=0;
			ranny=0;

		}
	}

}

void save_game()
{
	//if(game_saving==0)
	//{
		//mode=0;

		iShowBMP(100,100,"save_game_pic.bmp");
		iSetColor(0,0,0);
		if(blink_count%2)
			iText(142,149,username,GLUT_BITMAP_TIMES_ROMAN_24);
		else 
			iText(142,149,temp_name,GLUT_BITMAP_TIMES_ROMAN_24);
		if(mode)
		{
			FILE *names,*saver;
			names=fopen("names.bin","a+");
			fprintf(names,"%s\n",username);
			fclose(names);
			strcat(username,".game");
			saver=fopen(username,"w");
			
			fprintf(saver,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t",turn,ckx,cky,rannx,ranny,cksx,cksy,score,start_time,life);
			fclose(saver);
			reset();
			for(int ii=0;ii<30;ii++) {username[ii]=NULL; name[ii]=NULL;temp_name[ii]=NULL;}
			menu_check=0;
		}

//	}



	else if(game_saving==1);




	else if(game_saving==2);
	


}


void load_game()
{
	//int name_cord_x=250;
	int name_cord_y=406;
	if(loading_number==1)
	{
		iClear();



		iShowBMP(150,100,"loadgame.bmp");

		iSetColor(100,120,130);

		//FILE *naming;
		for(int ii=0;ii<5;ii++)
			iText(250,name_cord_y-ii*30,saved_names[ii]);
		//if(mousex>173 && mousex<636 &&mousey>136 &&mousey<167)
		{
		if(blink_count%2)
			iText(190,141,username,GLUT_BITMAP_TIMES_ROMAN_24);
		else 
			iText(190,141,temp_name,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(mode)
		{

			strcpy(name,username);
			strcat(name,".game");

			FILE *f1;
			if((f1=fopen(name,"r"))!=NULL)
			{
				fscanf(f1,"%d%d%d%d%d%d%d%d%d%d",&turn,&ckx,&cky,&rannx,&ranny,&cksx,&cksy,&score,&start_time,&life);
				fclose(f1);
				//loading_number=0;
				menu_check=1;
				/*for(i=0;i<30;i++)
					name[i]=0;*/
				for(int ii=0;ii<30;ii++) {username[ii]=NULL; name[ii]=NULL;temp_name[ii]=NULL;}
				my_key=0;
			}
			
			else
			{
				menu_check=4;
					for(int ii=0;ii<30;ii++) {username[ii]=NULL; name[ii]=NULL;temp_name[ii]=NULL;}
				//f1=fopen("instruction.txt","w+");
			}
			mode=0;
		}
		
	}
	//my_key=0;


		


}


void iSetcolor(double x,double y, double z)
{
	iSetColor(x*256,y*256,z*256);
}

void game_overf()
{
	iClear();
	iSetColor(255,128,128);
	iRectangle(100,100,500,100);
	iSetColor(128,128,128);
	iText(100,90,"Enter Your Name Here",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(230,126,156);
	iText(130,110,username,GLUT_BITMAP_TIMES_ROMAN_24);
}


void pausef()
{
	iClear();
	if((pause_ckr%3)==0)
	{
		iShowBMP(100,100,"paused.bmp");
		/*if(my_key==13)
		{
			paused=1;
		}*/
	}
	else if((pause_ckr%3)==1)
	{
		iShowBMP(100,100,"paused2.bmp");
		/*if(my_key==13)
		{
			mode=0;
			game_saving=1;
			//my_key=0;
			save_game();
		}*/
	}

	else if((pause_ckr%3)==2)
	{
		iShowBMP(100,100,"paused3.bmp");
		/*if(my_key==13)
		{
			reset();
		}*/
	}


	if(mposx>119 && mposx<207 && mposy>115 && mposy<184)
	{
		pause_ckr=0;
		mousex=-50;
		mousey=-50;
	}
	else if(mposx>264 && mposx<431 && mposy>126 && mposy<211)
		pause_ckr=1;
	else if(mposx>508 && mposx<580 && mposy>151 && mposy<213)
		pause_ckr=2;
	//else pause_ckr=0;

	if(mousex>119 && mousex<207 && mousey>115 && mousey<184)
	{
		paused=1;
		mousex=900;
		mousey=600;
	}
	else if(mousex>264 && mousex<431 && mousey>126 && mousey<211)
	{
		mode=0;
		menu_check=5;
		my_key=0;
		mousex=900;
		mousey=600;

	}
	else if(mousex>508 && mousex<580 && mousey>151 && mousey<213)
	{
		reset();
		my_key=0;
		mousex=900;
		mousey=600;
	}

	
}


void reset()
{
	 pause_ckr=0;
	 mposx=0;mposy=0;
	 //ckx=450; cky=30;
	 cksx=1; cksy=1;
	 timer=0;rad=0;
	 i=0,j=0;
	 //tn,cn;
	 turn=0;
	 my_key=0;
	 //show_time[3]={0,0,0};
	 //name[80];
	 menu_check=0;
	 mousex=0,mousey=0;
	 score=0;
	 len=0;
	 mode=0;
	 //welcome;
	 //username[30];
	 game_over=true;
	 life=3;

	 paused=1;
	 for(int ii=0;ii<30;ii++) {username[ii]=NULL; name[ii]=NULL;temp_name[ii]=NULL;}
	 temp_name[0]='_';
	 temp_name[1]=NULL;
}

void blink_text()
{
	blink_count++;
	if(blink_count==20) blink_count=1;
}


void not_game()
{
	iClear();
	iShowBMP(100,100,"not_game.bmp");
	iShowBMP(150,0,"back.bmp");
	//iText(100,75,"TRY AGAIN");
	if(mposx>162 && mposx<268 && mposy<60)
		iShowBMP(150,0,"back2.bmp");
	if(mousex>162 && mousex<268 && mousey<60){ menu_check=0; mousex=00;mousey=00;}


}

void High_scoref()
{
	iClear();
	//iShowBMP()

	iText(410,275,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
	if(!mode)
	{
		iClear();
		iRectangle(360,520,120,50);
		iText(360,580,"ENTER YOUR NAME");
		iText(370,525,username);
	}
	else
	{
		
		//iDelay(2);
		//menu_check=0;
		
		lane=0;
		temp=0;
		wing=0;
		life=3;
		//start_time=90;
		ckx=450; cky=30;
		cksx=1; cksy=1;
		i=0;j=0;;
		tn=0;cn=0;
		turn=0;
		my_key=0;;
		
		//mousex=0;mousey=0;
		

		//if(mousex<100&&mousey<100) menu_check=0;
	}

}


