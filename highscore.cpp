#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char highscore[3][30]={"siddharth","siddhartha","shidwartha"};
int highscore1[3]={10,15,20};

FILE   *hs;FILE *hs1;
int i,j;

void hssave(void)
{

	hs=fopen("highscore.txt","wb");
	fwrite(highscore,sizeof highscore,1,hs);

	hs1=fopen("highscore1.txt","wb");

	fwrite(highscore1,sizeof highscore1,1,hs1);

	fclose(hs);
	fclose(hs1);
}

void hsload(void)
{

	hs=fopen("highscore.txt","rb");
	fread(highscore,sizeof highscore,1,hs);

	hs1=fopen("highscore1.txt","rb");
	fread(highscore1,sizeof highscore1,1,hs1);

	fclose(hs1);

	fclose(hs);
}

int main()
{
	hsload();
	
	for(i=0;i<3;i++)
	{
		puts(highscore[i]);
	printf("%d\n",highscore1[i]);
	}

	hssave();

	return 0;
}