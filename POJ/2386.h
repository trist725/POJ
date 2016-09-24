// 2386 Lake Counting

#include<iostream>

using namespace std;

#include<stdio.h>

#define MARKED 0
#define DRY -2
#define WATER -1

int farm[110][110];
int xi[8]={1,1,1,0,0,-1,-1,-1};
int yi[8]={1,0,-1,1,-1,1,0,-1};
int n,m;

void mark(int i,int j)
{
	farm[i][j]=MARKED;
	int x;
	int y;
	for(int d=0;d<8;d++)
	{
		x=i+xi[d];
		y=j+yi[d];
		if(x>=0&&x<n&&y>=0&&y<m&&farm[x][y]==WATER)
		{
			farm[x][y]=MARKED;
			mark(x,y);
		}
	}
}

int main()
{
	char state;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			do
			{
				scanf("%c",&state);
			}while(state!='.'&&state!='W');
			if(state=='.')
			{
				farm[i][j]=DRY;
			}
			else
			{
				farm[i][j]=WATER;
			}
		}
	}
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(farm[i][j]==WATER)
			{
				count++;
				mark(i,j);
			}
		}
	}
	printf("%d\n",count);
	//system("pause");
	return 0;
}