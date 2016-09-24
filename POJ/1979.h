// 1979 Red and Black

#include<stdio.h>
#include<iostream>

struct Point
{
	int X;
	int Y;
};

int w,h;
char room[30][30];
Point queue[500];
Point dir[4]={0,1,0,-1,1,0,-1,0};

int main()
{
	scanf("%d%d",&w,&h);
	while(w!=0||h!=0)
	{
		memset(room,0,sizeof(room));
		for(int i=0;i<h;i++)
		{
			scanf("%s",room[i]);
		}
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(room[i][j]=='@')
				{
					queue[0].X=j;
					queue[0].Y=i;
				}
			}
		}
		int ql=1;
		for(int i=0;i<ql;i++)
		{
			for(int j=0;j<4;j++)
			{
				Point newPos;
				newPos.X=queue[i].X+dir[j].X;
				newPos.Y=queue[i].Y+dir[j].Y;
				if(newPos.X>=0&&newPos.X<w&&newPos.Y>=0&&newPos.Y<h)
				{
					if(room[newPos.Y][newPos.X]=='.')
					{
						queue[ql++]=newPos;
						room[newPos.Y][newPos.X]='@';
					}
				}
			}
		}
		printf("%d\n",ql);
		scanf("%d%d",&w,&h);
	}
	//system("pause");
	return 0;
}