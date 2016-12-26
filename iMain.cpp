/***************************** Hedder files***********************************/
# include "iGraphics.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <shellapi.h>
#include <math.h>
#include <time.h>
#include<conio.h>

/****************************** Array declarations **********************************/
char strarr[26][26];
char strar[26][26];
char winarr[26][26];
char highscore[3][30]={"set_iharth","set_ihartha","shidwartha"};
char highscore1[3][4]={"999","999","999"};
char *music[]={"start.MID"};

int timearr[3];
int varry[250];
int arr[26][26];
int rightset_je[26][26];
int inx[]={-1,-1,-1,0,0,1,1,1};
int iny[]={-1,0,1,-1,1,-1,0,1};

/****************************** Functions **********************************/
void save(void);
void newgame(void);
void load(void);
void gamewin(void);
void recursion(int h,int k);
void right(int corxx,int coryy,int mati,int matj);
void gameover();
void drawing(void);
void mineflag(void);
void timenextt(void);
void helpmenu(void);
void blinkk(void);
void filemouse(int mx,int my);
void leftclick(int aa,int aaa,int co,int coo);
void hssave(void);
void hsload(void);
void filemenu();

/****************************** variables **********************************/

time_t  vol,vol2,voln1,voln2;							//for music varible

int tempx,tempy;						
int tempi,tempj;

int newct=0;int count,ctr,counttt,countt;				//counter

int scoreopen=0;
int gameoverr=0;
int timestop=1;
int fileopen=0;
int gameopen=0;
int helpopen=0;
int level=1;
int sound=0;
int flag=0;

int i,j;												//variable i,j related
int ci,cj;
int cori,corj;

int lmoux,lmouy,rmoux,rmouy;
int st;
int inix;int iniy;										//funtion accessing..........
int aax,aay;
int mposx,mposy;
int midx,midy;
int mfx,mfy;
int x,y;
int box,boy;
int help;
int duck;



int set_x_mine;											//set mine positon
int set_y_mine;


int mineno;
int flagno;
int varnum;


int m,n;	
int mmm,nnn,z;											//local function accessing
int corx,cory,set_j,set_i,corxx,coryy;



int timenext;											//highscore.....&time showing.........
int high;
int hightime;
int blink=0;
int blin=0;


FILE   *hs;FILE *hs1;									//file pointer..........

/******************************Functions for Score storege***************************/
void hssave(void)										//save highscore in file
{

	hs=fopen("highscore.txt","wb");
	fwrite(highscore,sizeof highscore,1,hs);

	hs1=fopen("highscore1.txt","wb");

	fwrite(highscore1,sizeof highscore1,1,hs1);

	fclose(hs);
	fclose(hs1);
}

/******************************Functions for Score loading***************************/
void hsload(void)
{

	hs=fopen("highscore.txt","rb");						//open highscore file..............
	fread(highscore,sizeof highscore,1,hs);

	hs1=fopen("highscore1.txt","rb");
	fread(highscore1,sizeof highscore1,1,hs1);

	fclose(hs1);

	fclose(hs);
}
/****************************** left click ***************************/

void leftclick(int aa,int aaa,int co,int coo)
{	
	//if the click happens in strar on digit ..........for explode with left 

	if((lmoux>aa&&lmoux<(aa+16)&&lmouy>aaa&&lmouy<(aaa+16))&&(arr[co][coo]<=8)&&(arr[co][coo]>=0))
	{
		st=1;													
		counttt=0;					
		for(z=0;z<8;z++)
		{
			mmm=co+inx[z];nnn=coo+iny[z];
			if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)					//corner checking..........
			{
				if(strar[mmm][nnn]=='*')
					counttt++;
			}

		}
		countt=0;
		for(z=0;z<8;z++)
		{
			mmm=co+inx[z];nnn=coo+iny[z];
			if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
			{
				if(arr[mmm][nnn]==11)
					countt++;
			}

		}
		//explode with left click..........

		if(countt==counttt)									
		{

			for(z=0;z<8;z++)
			{
				mmm=co+inx[z];nnn=coo+iny[z];
				if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
				{	
					if(arr[mmm][nnn]==11)arr[mmm][nnn]=11;
					else if(strar[mmm][nnn]=='*')
						arr[mmm][nnn]=-1;
					else
						arr[mmm][nnn]=strar[mmm][nnn]-48;
				}

			}
		}
	}

		//if click on mine..........

	else if(lmoux>aa&&lmoux<(aa+16)&&lmouy>aaa&&lmouy<(aaa+16)&&strar[co][coo]=='*')
	{
		st=1;
		arr[co][coo]=-1;

	}
	
	//normal click..........

	else if(lmoux>aa&&lmoux<(aa+16)&&lmouy>aaa&&lmouy<(aaa+16))
	{	
		st=1;
		arr[co][coo]=strar[co][coo]-48;
	}

}
/****************************** Middle click ***************************/

void middleclick(int aa,int aaa,int co,int coo)
{
	//middle click explode....................

	if((midx>aa&&midx<(aa+16)&&midy>aaa&&midy<(aaa+16))&&(arr[co][coo]<=8)&&(arr[co][coo]>=0))
	{
		st=1;
		counttt=0;
		for(z=0;z<8;z++)
		{
			mmm=co+inx[z];nnn=coo+iny[z];
			if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
			{
				if(strar[mmm][nnn]=='*')
					counttt++;
			}

		}
		countt=0;
		for(z=0;z<8;z++)
		{
			mmm=co+inx[z];nnn=coo+iny[z];
			if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
			{
				if(arr[mmm][nnn]==11)
					countt++;
			}

		}
		if(countt==counttt)
		{

			for(z=0;z<8;z++)
			{
				mmm=co+inx[z];nnn=coo+iny[z];
				if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
				{	
					if(arr[mmm][nnn]==11)arr[mmm][nnn]=11;
					else if(strar[mmm][nnn]=='*')
						arr[mmm][nnn]=-1;
					else
						arr[mmm][nnn]=strar[mmm][nnn]-48;
				}

			}
		}
		//this is for show possible positon on midclick............

		else
		{
			duck=1;
			newct++;
			for(z=0;z<8;z++)
			{
				mmm=co+inx[z];nnn=coo+iny[z];
				if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
					if(arr[mmm][nnn]==10)
						arr[mmm][nnn]=15;
			}
		}

	}

	//this is for show possible positon on midclick.....

	else if((midx>aa&&midx<(aa+16)&&midy>aaa&&midy<(aaa+16))&&arr[co][coo]==10)
	{
		duck=1;
		st=1;
			newct++;
			for(z=0;z<8;z++)
			{
				mmm=co+inx[z];nnn=coo+iny[z];
				if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)	
					if(arr[mmm][nnn]==10)
						arr[mmm][nnn]=15;
			}

	}
	
}

/****************************** Right click ***************************/
void rightclick(int bb,int bbb,int doo,int dooo)
{	
	//herea array of 3 number contributing to flag ? and normal.............*/
	
	if(rmoux>bb&&rmoux<(bb+16)&&rmouy>bbb&&rmouy<(bbb+16))
	{	
		
		st=1;
		if(arr[doo][dooo]>=10)
		{
		if(rightset_je[doo][dooo]==2)
			arr[doo][dooo]=11;
		else if(rightset_je[doo][dooo]==3)
			arr[doo][dooo]=12;
		else if(rightset_je[doo][dooo]==1)
			arr[doo][dooo]=10;
		}
	}
}
/****************************** for ? and for flag click ***************************/


//increment of rightside array in three diffrent values.................//

void right(int corxx,int coryy,int mati,int matj)
{	
	if(rmoux>corxx&&rmoux<(corxx+16)&&rmouy>coryy&&rmouy<(coryy+16))
	{	
		
		st=1;
		rightset_je[mati][matj]++;
		if(rightset_je[mati][matj]>3)
			rightset_je[mati][matj]=rightset_je[mati][matj]-3;

	}
}

/****************************** filemenu ***************************/
void filemenu()
{
	inix=box-10;iniy=boy+cori*16+120;

	iShowBMP(0,iniy-32,"bkg.bmp");
	iShowBMP(600,iniy-32,"bkg.bmp");


	iText(10,iniy-32+10,"File",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(60,iniy-32+10,"Help",GLUT_BITMAP_TIMES_ROMAN_24);
	

	if(lmoux>10&&lmoux<50&&lmouy>(iniy-32)&&lmouy<iniy)				//if click on file menu.........
	{
		fileopen=1;
		scoreopen=0;
			
		iShowBMP(10,iniy-32-32,"button.bmp");
		iShowBMP(10,iniy-32-32-32,"button.bmp");
		iShowBMP(10,iniy-32-32-32-32,"button.bmp");
		iShowBMP(10,iniy-32-32-32-32-32,"button.bmp");
		iShowBMP(10,iniy-32-32-32-32-32-32,"button.bmp");
		iShowBMP(10,iniy-32-32-32-32-32-32-32,"button.bmp");


		iText(15,iniy-32-32+10,"New",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(15,iniy-32-32-32+10,"Beginner",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(12,iniy-32-32-32-32+10,"Medium",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(15,iniy-32-32-32-32-32+10,"Expert",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(15,iniy-32-32-32-32-32-32+10,"Best times",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(15,iniy-32-32-32-32-32-32-32+10,"Exit",GLUT_BITMAP_TIMES_ROMAN_24);	
	}

	//this for best time showing...........................//

	else if(fileopen==1&&lmoux>10&&lmoux<150&&lmouy>(iniy-32-32-32-32-32-32)&&lmouy<((iniy-32-32-32-32)))
	{
			hsload();
			scoreopen=1;
			iShowBMP(0,0+16+16+16,"congi.bmp");
			iShowBMP(0,0+16+16,"congi.bmp");
			iShowBMP(0,0+16,"congi.bmp");
			iShowBMP(0,0,"congi.bmp");

			iText(70+90,0+16+16+16+3,highscore1[0],GLUT_BITMAP_8_BY_13);
			iText(70,0+16+16+16+3,highscore[0],GLUT_BITMAP_8_BY_13);
			iText(3,0+16+16+16+3,"Begineer",GLUT_BITMAP_8_BY_13);

			iText(70+90,0+16+16+3,highscore1[1],GLUT_BITMAP_8_BY_13);
			iText(70,0+16+16+3,highscore[1],GLUT_BITMAP_8_BY_13);
			iText(3,0+16+16+3,"Medium",GLUT_BITMAP_8_BY_13);

			iText(70+90,0+16+3,highscore1[2],GLUT_BITMAP_8_BY_13);
			iText(70,0+16+3,highscore[2],GLUT_BITMAP_8_BY_13);
			iText(3,0+16+3,"Expert",GLUT_BITMAP_8_BY_13);

		iText(0,3,"Reset all records......",GLUT_BITMAP_8_BY_13);

		
	}

	//if user try to reset his data....................//

	if(scoreopen==1&&(lmoux<10||lmoux>150||lmouy<(iniy-32-32-32-32-32-32)||lmouy>(iniy-32-32-32-32)))
	{
		fileopen=0;
		if(lmoux>0&&lmoux<128&&lmouy>3&&lmouy<64)
		{
			strcpy(highscore1[0],"999");
			strcpy(highscore[0],"set_iharth");
			
			strcpy(highscore1[1],"999");
			strcpy(highscore[1],"set_ihartha");
			
			strcpy(highscore1[2],"999");
			strcpy(highscore[2],"Shidwartha");
			hssave();
		}
	}
	

	//while exit game, a file saves its game level so that on next run it will begin from that stage//

	else if(fileopen==1&&scoreopen==0&&lmoux>10&&lmoux<150&&lmouy>(iniy-32-32-32-32-32-32-32)&&lmouy<(iniy-32-32-32-32-32-32)) 
	{
		FILE *fp;
		fp=fopen("gamelevel.txt","w");
		fprintf(fp,"%d",level);
		fclose(fp);
		exit(0);
	}
}
/****************************** helpmenu ***************************/
void helpmenu(void)
{
	if(lmoux>60&&lmoux<(60+60)&&lmouy>(iniy-32)&&lmouy<iniy)//if you clik on help............
	{
		help=1;
		if(level==1)iShowBMP(23,23,"begin.bmp");
		if(level==2)iShowBMP(23,23,"medium.bmp");
		else if(level==3)iShowBMP(23,23,"medium.bmp");

	}
}
/****************************** mineboard ***************************/
void mine_board(void)
{

		//for showing time this is for first digit ............//

			 if(timearr[0]==0)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"00.bmp");		
		else if(timearr[0]==1)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"11.bmp");
		else if(timearr[0]==2)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"22.bmp");
		else if(timearr[0]==3)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"33.bmp");
		else if(timearr[0]==4)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"44.bmp");
		else if(timearr[0]==5)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"55.bmp");
		else if(timearr[0]==6)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"66.bmp");
		else if(timearr[0]==7)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"77.bmp");
		else if(timearr[0]==8)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"88.bmp");
		else if(timearr[0]==9)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"99.bmp");

			//for showing time this is for second digit ............//


		   	 if(timearr[1]==0)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"00.bmp");
		else if(timearr[1]==1)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"11.bmp");
		else if(timearr[1]==2)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"22.bmp");
		else if(timearr[1]==3)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"33.bmp");
		else if(timearr[1]==4)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"44.bmp");
		else if(timearr[1]==5)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"55.bmp");
		else if(timearr[1]==6)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"66.bmp");
		else if(timearr[1]==7)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"77.bmp");
		else if(timearr[1]==8)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"88.bmp");
		else if(timearr[1]==9)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"99.bmp");

			//for showing time this is for third digit ............//


			 if(timearr[2]==0)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"00.bmp");
		else if(timearr[2]==1)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"11.bmp");
		else if(timearr[2]==2)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"22.bmp");
		else if(timearr[2]==3)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"33.bmp");
		else if(timearr[2]==4)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"44.bmp");
		else if(timearr[2]==5)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"55.bmp");
		else if(timearr[2]==6)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"66.bmp");
		else if(timearr[2]==7)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"77.bmp");
		else if(timearr[2]==8)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"88.bmp");
		else if(timearr[2]==9)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"99.bmp");

		//this short part will build out side format..............//

		iSetcolor(0,0,0);
		if (duck==0)
		iShowBMP(box+(cori*16)/2-16,boy+cori*16+20+16,"duck.bmp");
		else
		iShowBMP(box+(cori*16)/2-16,boy+cori*16+20+16,"boo.bmp");
			

		iRectangle(box-2,boy-2,cori*16+4,corj*16+4);
		iRectangle(box-10,boy-10,cori*16+20,corj*16+20);

		iRectangle(box-10+10,boy+cori*16+20+10,cori*16+20-20,64-20);
		iRectangle(box-10,boy+cori*16+20,cori*16+20,64);
		iSetcolor(255,255,255);
		

		//for loop for preparing board...................//

		y=20;
		boy=y;
		for(i=0;i<cori;i++)
		{
			x=20;
			box=x;
			
			for(j=0;j<cori;j++)
			{	
				if(timestop!=1&&fileopen==0)
				{
					leftclick(x,y,i,j);
					rightclick(x,y,i,j);
					middleclick(x,y,i,j);
				}
				
				if(arr[i][j]==14)
				{
					if(blin%2==0)iShowBMP(x,y,"flag.bmp");
					else
						iShowBMP(x,y,"mine2.bmp");
				}

				else
				{
					if(arr[i][j]==13)
					{
						if(blin%2==0)iShowBMP(x,y,"flag.bmp");
						else
							iShowBMP(x,y,"mine2.bmp");
					}
					if(arr[i][j]==0)
					{	
						iShowBMP(x,y,"0.bmp");
						arr[i][j]=-3;
						recursion(i,j);
					}
					else if(arr[i][j]==-1)
						gameover();

					else if(arr[i][j]==-3||arr[i][j]==9)
						iShowBMP(x,y,"0.bmp");	
					
					else if(arr[i][j]==1)
						iShowBMP(x,y,"1.bmp");

					else if(arr[i][j]==2)
						iShowBMP(x,y,"2.bmp");

					else if(arr[i][j]==3)
						iShowBMP(x,y,"3.bmp");

					else if(arr[i][j]==4)
						iShowBMP(x,y,"4.bmp");

					else if(arr[i][j]==12)
						iShowBMP(x,y,"q.bmp");

					else if(arr[i][j]==5)
						iShowBMP(x,y,"5.bmp");

					else if(arr[i][j]==6)
						iShowBMP(x,y,"6.bmp");

					else if(arr[i][j]==7)
						iShowBMP(x,y,"7.bmp");

					else if(arr[i][j]==8)
						iShowBMP(x,y,"8.bmp");

					else if(arr[i][j]==10)
					{
						if(level==1)
						iShowBMP(x,y,"board.bmp");
						else if(level==2)
						iShowBMP(x,y,"board1.bmp");
						else if(level==3)
						iShowBMP(x,y,"board2.bmp");
					}

					else if(arr[i][j]==11)
						iShowBMP(x,y,"flag.bmp");
					else if(arr[i][j]==15)
						iShowBMP(x,y,"0.bmp");


				}
				x=x+16;

			}
			y=y+16;
		}
		if(newct>3)
		{
			duck=0;
		midx=0;midy=0;
		for(i=0;i<cori;i++)
			for(j=0;j<corj;j++)
				if(arr[i][j]==15)
					arr[i][j]=10;
				newct=0;
		}

	gamewin();

}
/****************************** gamewinning ***************************/
void gamewin(void)
{
		
	//counts flag number.............//

		flagno=0;
		for(i=0;i<cori;i++)
		{
			for(j=0;j<cori;j++)
			{
				if(arr[i][j]==11||arr[i][j]==14)
					flagno++;
			}
		}
		mineflag();

	//checks	wheather each flag i s on mine position or not........// 

		flag=0;
		if(flagno==mineno)
		{
			for(i=0;i<cori;i++)
			{
				for(j=0;j<corj;j++)
				{
					if(strarr[i][j]=='*')
					{
						if(arr[i][j]==11||arr[i][j]==14)
						{
							flag=1;
							continue;
						}
						else
						{
							flag=0;
							break;
						}
					}

				}
			}

		}

		if(flag==1)
		{
			if(sound==0)sound=1;
			iShowBMP(box+(cori*16/2)-60,boy+(cori*16/2)-10,"button.bmp");
			
			//show blink after game finishing..............//

			iText(box+(cori*16/2)-50,boy+(cori*16/2),"You win",GLUT_BITMAP_TIMES_ROMAN_24);
			timestop=1;
			blink=1;
			for(i=0;i<cori;i++)
				for(j=0;j<corj;j++)
				{
					if(strarr[i][j]=='*')
					{
						arr[i][j]=14;
					}
				}

			helpopen=2;
			hsload();
			
			//show times....................//

			if(timestop==1&&gameopen==1)
			{
				high=(highscore1[0][0]-48)*100+(highscore1[0][1]-48)*10+(highscore1[0][2]-48);
				hightime=timearr[0]*100+timearr[1]*10+timearr[2];
				if(hightime<=high)
				{
					highscore1[0][0]=timearr[0]+48;				//casting int time in array...............//
					highscore1[0][1]=timearr[1]+48;
					highscore1[0][2]=timearr[2]+48;
					
					iShowBMP(598,16,"button.bmp");
				}	
				strcpy(highscore[0],"player");
			}
			else if(timestop==1&&gameopen==2)
			{
				high=(highscore1[1][0]-48)*100+(highscore1[1][1]-48)*10+(highscore1[1][2]-48);
				hightime=timearr[0]*100+timearr[1]*10+timearr[2];
				
				if(hightime<=high)
				{
				
					highscore1[1][0]=timearr[0]+48;
					highscore1[1][1]=timearr[1]+48;
					highscore1[1][2]=timearr[2]+48;

					iShowBMP(598,16,"button.bmp");
				
				}
				strcpy(highscore[1],"player");
			} 
			else if(timestop==1&&gameopen==3)
			{
				high=(highscore1[2][0]-48)*100+(highscore1[2][1]-48)*10+(highscore1[2][2]-48);
				hightime=timearr[0]*100+timearr[1]*10+timearr[2];
				
				if(hightime<=high)
				{
				
					highscore1[2][0]=timearr[0]+48;
					highscore1[2][1]=timearr[1]+48;
					highscore1[2][2]=timearr[2]+48;

					iShowBMP(598,16,"button.bmp");
				
				}
				strcpy(highscore[2],"player");
			}
			
			//if score leesthan highscore........................//

			if(hightime>high)
			{
				iShowBMP(0,0,"congi.bmp");
				iText(3,3,"Fail to make highscore",GLUT_BITMAP_8_BY_13);
			}

			//if player makes high scores...//

			else
			{
				iShowBMP(0,0+16+16+16,"congi.bmp");
				iShowBMP(0,0+16+16,"congi.bmp");
				iShowBMP(0,0+16,"congi.bmp");
				iShowBMP(0,0,"congi.bmp");

				iText(70+90,0+16+16+16+3,highscore1[0],GLUT_BITMAP_8_BY_13);
				iText(70,0+16+16+16+3,highscore[0],GLUT_BITMAP_8_BY_13);
				iText(3,0+16+16+16+3,"Begineer",GLUT_BITMAP_8_BY_13);

				iText(70+90,0+16+16+3,highscore1[1],GLUT_BITMAP_8_BY_13);
				iText(70,0+16+16+3,highscore[1],GLUT_BITMAP_8_BY_13);
				iText(3,0+16+16+3,"Medium",GLUT_BITMAP_8_BY_13);

				iText(70+90,0+16+3,highscore1[2],GLUT_BITMAP_8_BY_13);
				iText(70,0+16+3,highscore[2],GLUT_BITMAP_8_BY_13);
				iText(3,0+16+3,"Expert",GLUT_BITMAP_8_BY_13);

				iText(0,3,"Reset all records......",GLUT_BITMAP_8_BY_13);

					//reseet all highscore data .................into default//

				if(lmoux>0&&lmoux<128&&lmouy>3&&lmouy<64)
				{
					strcpy(highscore1[0],"999");
					strcpy(highscore[0],"set_iharth");
					
					strcpy(highscore1[1],"999");
					strcpy(highscore[1],"set_ihartha");
					
					strcpy(highscore1[2],"999");
					strcpy(highscore[2],"Shidwartha");
				}

			hssave();
			}
		}


}

/****************************** Drawing function ***************************/
void drawing(void)
{
	if(gameopen==1)
	{	
		mine_board();
	}
	else if(gameopen==2)
	{
		mine_board();
	}
	else if(gameopen==3)
	{
		mine_board();	
	}
}
/****************************** mineflag number ***************************/
void mineflag(void)
{
	int mineflag;
	int firstdigit;
	int seconddigit;
	
	mfx=box-16+20;mfy=boy+cori*16+20+18;
	mineflag=mineno-flagno;
	
	if(timestop==1)
	{
		iShowBMP(mfx,mfy,"00.bmp");
		iShowBMP(mfx+16,mfy,"00.bmp");
	}
	else
	{
		if(mineflag<1)
		{
			iShowBMP(mfx,mfy,"00.bmp");
			iShowBMP(mfx+16,mfy,"00.bmp");
		}
		else
		{
		firstdigit=mineflag/10;									//counts the niumber of flag amd mine in board.....//
		seconddigit=mineflag%10;
		
			 if(firstdigit==0)iShowBMP(mfx,mfy,"00.bmp");
		else if(firstdigit==1)iShowBMP(mfx,mfy,"11.bmp");
		else if(firstdigit==2)iShowBMP(mfx,mfy,"22.bmp");
		else if(firstdigit==3)iShowBMP(mfx,mfy,"33.bmp");
		else if(firstdigit==4)iShowBMP(mfx,mfy,"44.bmp");
		else if(firstdigit==5)iShowBMP(mfx,mfy,"55.bmp");
		else if(firstdigit==6)iShowBMP(mfx,mfy,"66.bmp");
		else if(firstdigit==7)iShowBMP(mfx,mfy,"77.bmp");
		else if(firstdigit==8)iShowBMP(mfx,mfy,"88.bmp");
		else if(firstdigit==9)iShowBMP(mfx,mfy,"99.bmp");
		
		
			 if(seconddigit==0)iShowBMP(mfx+16,mfy,"00.bmp");
		else if(seconddigit==1)iShowBMP(mfx+16,mfy,"11.bmp");
		else if(seconddigit==2)iShowBMP(mfx+16,mfy,"22.bmp");
		else if(seconddigit==3)iShowBMP(mfx+16,mfy,"33.bmp");
		else if(seconddigit==4)iShowBMP(mfx+16,mfy,"44.bmp");
		else if(seconddigit==5)iShowBMP(mfx+16,mfy,"55.bmp");
		else if(seconddigit==6)iShowBMP(mfx+16,mfy,"66.bmp");
		else if(seconddigit==7)iShowBMP(mfx+16,mfy,"77.bmp");
		else if(seconddigit==8)iShowBMP(mfx+16,mfy,"88.bmp");
		else if(seconddigit==9)iShowBMP(mfx+16,mfy,"99.bmp");
		}
	}	
}

/****************************** gameover***************************/


void gameover()
{

	//when it gets -1 from array then it makes all mine in -1..............//
	int w,s;
	iShowBMP(box+(cori*16)/2-16,boy+cori*16+20+16,"loser.bmp");

	
	if(gameoverr==0)PlaySound("LOGOSTIN_2.WAV",NULL,SND_ASYNC);
	iShowBMP(x,y,"mine2.bmp");
	
	iShowBMP(box+(cori*16/2)-60,boy+(cori*16/2)-10,"button.bmp");

	iText(box+(cori*16/2)-50,boy+(cori*16/2),"You lose",GLUT_BITMAP_TIMES_ROMAN_24);

	for(w=0;w<cori;w++)
	for(s=0;s<corj;s++)
	{
		if(strarr[w][s]=='*')
		{
			if(arr[w][s]==11)
				arr[w][s]=13;
			else if(arr[w][s]!=13)
				arr[w][s]=-1;
		}
	}
	timestop=1;
	blink=1;
	gameoverr=1;

}
/****************************** idraw ***************************/
void iDraw()
{
	iClear();
	iShowBMP(0,0,"back.bmp");

	time(&vol);					//open background music..............//
	if((vol-vol2)%123==0)
	ShellExecute(NULL,"open",music[0],0,0,0);

	drawing();
	filemenu();
	helpmenu();
	if(sound==1)
	{
		PlaySound("applause3.wav",NULL,SND_ASYNC);
		sound=2;
	}

}

/****************************** imousemove ***************************/
void iMouseMove(int mx, int my)
{

}
/****************************** passive mouse move ***************************/
void iPassiveMouseMove(int mx, int my)
{
	//place your codes here
	mposx=mx;
	mposy = my;

}
/****************************** imouse ***************************/

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		filemouse(mx,my);			//call imouse file menu caculaton............//

		if(help==1&&lmoux>23&&lmouy<256&&lmouy>23&&lmouy<256)
		{
			help=0;
			lmoux=0;lmouy=0;
		}

	//	printf("(%d %d)",mx,my);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
		PlaySound("typewriter_click.wav",NULL,SND_ASYNC);

		rmoux=mx;rmouy=my;
		lmoux=0;lmouy=0;
		midx=0;midy=0;
		cory=boy;
		for(set_j=0;set_j<cori;set_j++)
		{
			corx=box;
			for(set_i=0;set_i<cori;set_i++)
			{	
				if(arr[set_j][set_i]>=10)
					right(corx,cory,set_j,set_i);

				corx=corx+16;
			}
			cory=cory+16;
		}
		
	}

	if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
			PlaySound("typewriter_click.wav",NULL,SND_ASYNC);
			midx=mx;midy=my;
			lmoux=0;lmouy=0;
			rmoux=0;rmouy=0;
	}
	
}
/****************************** leftclick imouse file works ***************************/
void filemouse(int mx,int my)
{
		lmoux=mx;lmouy=my;
		rmoux=0;rmouy=0;
		midx=0;midy=0;
		PlaySound("typewriter_click.wav",NULL,SND_ASYNC);

		if((fileopen==1&&scoreopen==0&&lmoux>10&&lmoux<80&&lmouy>(iniy-32-32)&&lmouy<(iniy-32))||(lmoux>(box+(cori*16)/2-16)&&lmoux<(box+(cori*16)/2-16+32)&&lmouy>(boy+cori*16+20+16)&&lmouy<(boy+cori*16+20+16+32)))
		{

			//if you click on duck face oer new game........................//
			//	then it will take data to identify its level and load array /////////

			sound=0;
			st=0;
			flag=0;
			closeWindowMy();
			lmoux=0;lmouy=0;
			FILE *fp;
			fp=fopen("gamelevel.txt","w");
			fprintf(fp,"%d",level);
			fclose(fp);

			FILE *fpp;

			fpp=fopen("gamelevel.txt","r");
			fscanf(fpp,"%d",&level);

			fclose(fpp);

			fileopen=0;

			if(level==1)
			{
				cori=9;
				corj=9;
				
				varnum=10;
			}
			else if(level==2)
			{
				cori=16;
				corj=16;
				
				varnum=40;
			}
			
			else if(level==3)
			{
				cori=25;
				corj=25;
				varnum=99;
			}
			memset(strarr,0,sizeof(strarr));						//this is to initialise all strarr int 0 every time.......//
			memset(arr,0,sizeof(arr));
			memset(rightset_je,0,sizeof(rightset_je));
			memset(timearr,0,sizeof(timearr));
			for(i=0;i<cori;i++)for(j=0;j<corj;j++)
			{
				strarr[i][j]='.';
				arr[i][j]=10;
				rightset_je[i][j]=1;
			}
			load();
			newgame();
			gameopen=level;
			timenext=0;
			timestop=0;
			blink=0;
			save();
			gameoverr=0;
	
			if(level==1)
			iInitialize(184,282, "Minesweeper");
			if(level==2)
			iInitialize(296,396, "Minesweeper");
			if(level==3)
			iInitialize(440,536, "Minesweeper");

			fp=fopen("gamelevel.txt","w");
			fprintf(fp,"%d",level);
			fclose(fp);
		
		}

		//this same is for level 1.............................//

		else if(fileopen==1&&scoreopen==0&&lmoux>10&&lmoux<80&&lmouy>(iniy-32-32-32)&&lmouy<(iniy-32-32))
		{
			sound=0;
			st=0;
			flag=0;
			lmoux=0;lmouy=0;
			level=1;
			fileopen=0;
			
			cori=9;
			corj=9;
			varnum=10;
			
			memset(strarr,0,sizeof(strarr));
			memset(arr,0,sizeof(arr));
			memset(rightset_je,0,sizeof(rightset_je));
			memset(timearr,0,sizeof(timearr));
			for(i=0;i<cori;i++)for(j=0;j<corj;j++)
			{
				strarr[i][j]='.';
				arr[i][j]=10;
				rightset_je[i][j]=1;
			}
			load();
			newgame();
			gameopen=1;
			save();
			timestop=0;
			timenext=0;
			blink=0;
			gameoverr=0;
			closeWindowMy();		//close the existing window and createw anew window,,,,,,,,,,,/////
			iInitialize(184,282, "Minesweeper");
			

			FILE *fp;
			fp=fopen("gamelevel.txt","w");
			fprintf(fp,"%d",level);
			fclose(fp);

		}

		else if(fileopen==1&&scoreopen==0&&lmoux>10&&lmoux<80&&lmouy>(iniy-32-32-32-32)&&lmouy<(iniy-32-32-32))
		{
			sound=0;
			st=0;
			flag=0;
			lmoux=0;lmouy=0;
			level=2;
			fileopen=0;
			cori=16;
			corj=16;
			
			memset(strarr,0,sizeof(strarr));
			memset(arr,0,sizeof(arr));
			memset(rightset_je,0,sizeof(rightset_je));
			memset(timearr,0,sizeof(timearr));
			for(i=0;i<cori;i++)for(j=0;j<corj;j++)
			{
				strarr[i][j]='.';
				arr[i][j]=10;
				rightset_je[i][j]=1;
			}
			varnum=40;
			load();
			newgame();
			gameopen=2;
			timenext=0;
			timestop=0;
			blink=0;
			save();
			gameoverr=0;
			closeWindowMy();
			iInitialize(296,396, "Minesweeper");
			
			FILE *fp;
			fp=fopen("gamelevel.txt","w");
			fprintf(fp,"%d",level);
			fclose(fp);
		}
		
		else if(fileopen==1&&scoreopen==0&&lmoux>10&&lmoux<80&&lmouy>(iniy-32-32-32-32-32)&&lmouy<((iniy-32-32-32-32)))
		{
			sound=0;
			st=0;
			flag=0;
			lmoux=0;lmouy=0;
			level=3;
			fileopen=0;
			cori=25;
			corj=25;
			
			memset(rightset_je,0,sizeof(rightset_je));
			memset(strarr,0,sizeof(strarr));
			memset(arr,0,sizeof(arr));
			memset(timearr,0,sizeof(timearr));
			for(i=0;i<cori;i++)for(j=0;j<corj;j++)
			{
				strarr[i][j]='.';
				arr[i][j]=10;
				rightset_je[i][j]=1;
			}
			varnum=99;

			load();
			gameopen=3;
			timenext=0;
			newgame();
			save();
			timestop=0;
			blink=0;
			gameoverr=0;
			closeWindowMy();
			iInitialize(440,536, "Minesweeper");

			
			FILE *fp;
			fp=fopen("gamelevel.txt","w");
			fprintf(fp,"%d",level);
			fclose(fp);
		}
		else if(fileopen==1&&scoreopen==0&&(lmoux<10||lmoux>80||lmouy<(iniy-32-32-32-32-32-32-32)||lmouy>(iniy-32)))
		{
			fileopen=0;
			lmoux=0;lmouy=0;
		}

}
/****************************** normal key ***************************/
void iKeyboard(unsigned char key)
{

}

/****************************** Special key***************************/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_F2)
	{
		exit(0);
	}
}

/****************************** main function ***************************/
int main()
{	
	time(&vol2);

	iSettimer(1000,timenextt);
	iSettimer(500,blinkk);

	FILE *fpp;

	fpp=fopen("gamelevel.txt","r");
	fscanf(fpp,"%d",&level);

	fclose(fpp);

	fileopen=0;
	if(level==1)
	{
	cori=9;
	corj=9;
	
	varnum=10;
	}
	else if(level==2)
	{
	cori=16;
	corj=16;
	
	varnum=40;
	}
	
	else if(level==3)
	{
	cori=25;
	corj=25;
	varnum=99;
	}
	memset(strarr,0,sizeof(strarr));
	memset(arr,0,sizeof(arr));
	memset(rightset_je,0,sizeof(rightset_je));
	memset(timearr,0,sizeof(timearr));
	for(i=0;i<cori;i++)for(j=0;j<corj;j++)
	{
		strarr[i][j]='.';
		arr[i][j]=10;
		rightset_je[i][j]=1;
	}
	load();
	newgame();
	gameopen=level;
	timenext=0;
	timestop=0;
	blink=0;
	save();
	gameoverr=0;
	
	if(level==1)
	iInitialize(184,282, "Minesweeper");
	if(level==2)
	iInitialize(296,396, "Minesweeper");
	if(level==3)
	iInitialize(440,536, "Minesweeper");
	return 0;
}
/****************************** on finishing show mine &flag ***************************/
void blinkk(void)
{

	if(blink==1)
		blin++;
	if(blin>50)
		blin=0;
}

/****************************** on finishing show mine &flag ***************************/
void timenextt(void)
{

	mfx=box+corj*16;mfy=boy+cori*16+20,corj*16+30;

	if(gameopen!=0&&timestop==0&&st==1)
	{
		timenext++;
		
		if(timenext>999)memset(timearr,0,sizeof(timearr));
		else
		{	
			timearr[0]=timenext/100;					//casting time into arr;
			timearr[2]=timenext%10;
			timearr[1]=(timenext-(timearr[0]*100+timearr[2]))/10;
		}
	}

}

/***************************************** save varry *************************************/
void save(void)
{
	FILE *va;

	va=fopen("varry.txt","wb");
	fwrite(varry,sizeof varry,1,va);

	fclose(va);
}

/***************************************** save varry *************************************/
void load(void)
{
	FILE *va;

	va=fopen("varry.txt","rb");
	fread(varry,sizeof varry,1,va);

	fclose(va);
}

/***************************************** save varry *************************************/

void newgame(void)
{	
	mineno=0;
	
	//for level 1/////////////////////

	if(level==1)
	{
		//this will pro duce ten differ ent number.....................//

		varry[0]=(varry[0]+rand())%81;

		for(i=1;i<10;i++)
		{	
			varry[i]=(varry[i]+rand())%81;
			for(j=0;j<i;)
			{
				if(varry[j]==varry[i])
				{
					varry[i]=(varry[i]+rand())%81;
					j=0;
				}
				else
					j++;
			}

		}
		
		//set those numbers in x &y cor dinates from it reminder value///////////////

		for(i=0;i<10;i++)
		{
			set_x_mine=varry[i]%9;
			set_y_mine=varry[i]/9;
			strarr[set_y_mine][set_x_mine]='*';
			mineno++;
		}

		//produce two dimetional strarr array of only '.'&'*';


		for(i=0;i<cori;i++)
		{
			for(j=0;j<corj;j++)
			{
				if(strarr[i][j]=='*')
				{
					strar[i][j]=strarr[i][j];
				}
				else
				{	
					//check its 8 corners and make a strarr of digit and *;/////////////
					count=0;
					for(z=0;z<8;z++)
					{
						m=i+inx[z];n=j+iny[z];
						if(m>=0&&m<cori&&n>=0&&n<corj&&strarr[m][n]=='*')count=count+1;
					}
					strar[i][j]=count+48;
				}
			
			}

		}

	}
	else if(level==2)
	{
		varry[0]=(varry[0]+rand())%256;

		for(i=1;i<40;i++)
		{	
			varry[i]=(varry[i]+rand())%256;
			for(j=0;j<i;)
			{
				if(varry[j]==varry[i])
				{
					varry[i]=(varry[i]+rand())%81;
					j=0;
				}
				else
					j++;
			}

		}

		for(i=0;i<40;i++)
		{
			set_x_mine=varry[i]%16;
			set_y_mine=varry[i]/16;
			strarr[set_y_mine][set_x_mine]='*';
			mineno++;
		}
		for(i=0;i<cori;i++)
		{
			for(j=0;j<corj;j++)
			{
				if(strarr[i][j]=='*')
				{
					strar[i][j]=strarr[i][j];
				}
				else
				{	
					count=0;
					for(z=0;z<8;z++)
					{
						m=i+inx[z];n=j+iny[z];
						if(m>=0&&m<cori&&n>=0&&n<corj&&strarr[m][n]=='*')count=count+1;
					}
					strar[i][j]=count+48;
				}
			
			}

		}

	}
	else if(level==3)
	{
		varry[0]=(varry[0]+rand())%625;

		for(i=1;i<99;i++)
		{	
			varry[i]=(varry[i]+rand())%625;
			for(j=0;j<i;)
			{
				if(varry[j]==varry[i])
				{
					varry[i]=(varry[i]+rand())%81;
					j=0;
				}
				else
					j++;
			}

		}
	
		for(i=0;i<varnum;i++)
		{
			set_x_mine=varry[i]%25;
			set_y_mine=varry[i]/25;
			strarr[set_y_mine][set_x_mine]='*';
			mineno++;
			varry[i]=(varry[i]+set_x_mine+set_y_mine+rand())%625;
		}
		for(i=0;i<cori;i++)
		{
			for(j=0;j<corj;j++)
			{
				if(strarr[i][j]=='*')
				{
					strar[i][j]=strarr[i][j];
				}
				else
				{	
					count=0;
					for(z=0;z<8;z++)
					{
						m=i+inx[z];n=j+iny[z];
						if(m>=0&&m<cori&&n>=0&&n<corj&&strarr[m][n]=='*')count=count+1;
					}
					strar[i][j]=count+48;
				}
			
			}

		}

	}

/*	printf("\n%d\n",mineno);
	
	if(level==1)
	for(i=0;i<cori;i++)
	{
		for(j=0;j<corj;j++)
			printf("%c",strarr[i][j]);
			printf("\n");
	}
	
	if(level==2)
	for(i=0;i<cori;i++)
	{
		for(j=0;j<corj;j++)
			printf("%c",strarr[i][j]);
			printf("\n");
	}

	if(level==3)
	for(i=0;i<cori;i++)
	{
		for(j=0;j<corj;j++)
			printf("%c",strarr[i][j]);
			printf("\n");
	}

	printf("\n");
	
		for(j=0;j<varnum;j++)
			printf("%d  ",varry[j]);
			printf("\n");

	printf("\n%d\n",mineno);*/

}



/******************************  To Show 0 and its  adjacent  ******************************************8*/

void recursion(int h,int k)
{		

		if((h-1)>=0&&(h-1)<cori&&(k-1)>=0&&(k-1)<cori)		//cheack alocation .........and 
		{	
			arr[h-1][k-1]=strar[h-1][k-1]-48;
			if(strar[h-1][k-1]=='0')
			{
			strar[h-1][k-1]=9+48;
		    arr[h-1][k-1]=-3;
			recursion(h-1,k-1);
			}
		}
	

		if((h-1)>=0&&(h-1)<cori&&(k)>=0&&(k)<cori)
		{
			arr[h-1][k]=strar[h-1][k]-48;
			if(strar[h-1][k]=='0')
			{
			strar[h-1][k]=9+48;
			arr[h-1][k]=-3;
            recursion(h-1,k);
			}

		}

		if((h-1)>=0&&(h-1)<cori&&(k+1)>=0&&(k+1)<cori)
		{
			arr[h-1][k+1]=strar[h-1][k+1]-48;
			if(strar[h-1][k+1]=='0')
			{
			strar[h-1][k+1]=9+48;
			arr[h-1][k+1]=-3;
			recursion(h-1,k+1);
			}

		}


		if((h)>=0&&(h)<cori&&(k-1)>=0&&(k-1)<cori)
		{
			arr[h][k-1]=strar[h][k-1]-48;
			if(strar[h][k-1]=='0')
			{
			strar[h][k-1]=9+48;
			arr[h][k-1]=-3;
			recursion(h,k-1);
			}

		}

		if((h)>=0&&(h)<cori&&(k+1)>=0&&(k+1)<cori)
		{
			arr[h][k+1]=strar[h][k+1]-48;
			if(strar[h][k+1]=='0')
			{
			strar[h][k+1]=9+48;
			arr[h][k+1]=-3;
			recursion(h,k+1);
			}

		}

		if((h+1)>=0&&(h+1)<cori&&(k-1)>=0&&(k-1)<cori)
		{
			arr[h+1][k-1]=strar[h+1][k-1]-48;
			if(strar[h+1][k-1]=='0')
			{
			strar[h+1][k-1]=9+48;
			arr[h+1][k-1]=-3;
			recursion(h+1,k-1);
			}

		}

		if((h+1)>=0&&(h+1)<cori&&(k)>=0&&(k)<cori)
		{
			arr[h+1][k]=strar[h+1][k]-48;
			if(strar[h+1][k]=='0')
			{
			strar[h+1][k]=9+48;
			arr[h+1][k]=-3;
			recursion(h+1,k);
			}

		}

		if((h+1)>=0&&(h+1)<cori&&(k+1)>=0&&(k+1)<cori)
		{
			arr[h+1][k+1]=strar[h+1][k+1]-48;
			if(strar[h+1][k+1]=='0')
			{
			strar[h+1][k+1]=9+48;
			arr[h+1][k+1]=-3;
			recursion(h+1,k+1);
			}
		}	

}


















