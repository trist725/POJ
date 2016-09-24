// 1013	Counterfeit Dollar

#include<stdio.h>
#include<iostream>

const int REAL=2;
const int LIGHT=1;
const int HEAVY=3;
const int UNKNOW=0;
const int COIN_NUM=12;

int coin[COIN_NUM];
int weightCount[COIN_NUM];

inline void SetHeavy(int i)
{
	if(coin[i]==LIGHT||coin[i]==REAL)
	{
		coin[i]=REAL;
	}
	else
	{
		coin[i]=HEAVY;
		weightCount[i]++;
	}
}

inline void SetLight(int i)
{
	if(coin[i]==HEAVY||coin[i]==REAL)
	{
		coin[i]=REAL;
	}
	else
	{
		coin[i]=LIGHT;
		weightCount[i]++;
	}
}

int main()
{
	int n;
	char left[16];
	char right[16];
	char balance[8];
	scanf("%d",&n);
	for(int a=0;a<n;a++)
	{
		memset(coin,UNKNOW,sizeof(coin));
		memset(weightCount,0,sizeof(weightCount));
		for(int b=0;b<3;b++)
		{
			scanf("%s%s%s",left,right,balance);
			if(balance[0]=='e')
			{
				for(int i=0;left[i]!='\0';i++)
				{
					coin[left[i]-'A']=REAL;
					coin[right[i]-'A']=REAL;
				}
			}
			else
			{
				if(balance[0]=='u')
				{
					for(int i=0;left[i]!='\0';i++)
					{
						SetHeavy(left[i]-'A');
						SetLight(right[i]-'A');
					}
				}
				else
				{
					for(int i=0;left[i]!='\0';i++)
					{
						SetLight(left[i]-'A');
						SetHeavy(right[i]-'A');
					}
				}
			}
		}
		int max=0;
		int maxIndex=0;
		for(int i=0;i<COIN_NUM;i++)
		{
			if((coin[i]==HEAVY||coin[i]==LIGHT)&&weightCount[i]>max)
			{
				max=weightCount[i];
				maxIndex=i;
			}
		}
		if(coin[maxIndex]==HEAVY)
		{
			printf("%c is the counterfeit coin and it is heavy.\n",'A'+maxIndex);
		}
		else
		{
			printf("%c is the counterfeit coin and it is light.\n",'A'+maxIndex);
		}
	}
	//system("pause");
	return 0;
}