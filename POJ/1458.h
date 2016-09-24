// 1458 Common Subsequence

#include<iostream>

using namespace std;

#include<stdio.h>

#define EMPTY -1

char src[500];
char dest[500];
int history[500][500];

int getMax(int i,int j)
{
	if(i<0||j<0)
	{
		return 0;
	}
	if(history[i][j]!=EMPTY)
	{
		return history[i][j];
	}
	if(src[i]==dest[j])
	{
		history[i][j]=getMax(i-1,j-1)+1;
	}
	else
	{
		int a=getMax(i-1,j);
		int b=getMax(i,j-1);
		history[i][j]=a>b?a:b;
	}
	return history[i][j];
}

int main()
{
	while(cin>>src>>dest)
	{
		for(int i=0;i<500;i++)
		{
			for(int j=0;j<500;j++)
			{
				history[i][j]=EMPTY;
			}
		}
		cout<<getMax(strlen(src)-1,strlen(dest)-1)<<endl;
	}
	//system("pause");
	return 0;
}