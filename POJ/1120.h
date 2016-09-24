// 1120 A New Growth Industry

#include<iostream>

using namespace std;

#include<cstdio>


int main()
{
	int d[16];
	int dish[2][22][22];
	int days;
	scanf("%d",&days);
	for(int i=0;i<16;i++)
	{
		scanf("%d",&d[i]);
	}
	memset(dish,0,sizeof(dish));
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=20;j++)
		{
			scanf("%d",&dish[0][i][j]);
		}
	}
	int src=0;
	int alt=1;
	for(int i=0;i<=days;i++)
	{
		for(int x=1;x<=20;x++)
		{
			for(int y=1;y<=20;y++)
			{
				int sum=dish[src][x][y]+dish[src][x-1][y]+dish[src][x+1][y]+dish[src][x][y-1]+dish[src][x][y+1];
				dish[alt][x][y]=dish[src][x][y]+d[sum];
				if(dish[alt][x][y]>3)
				{
					dish[alt][x][y]=3;
				}
				else if(dish[alt][x][y]<0)
				{
					dish[alt][x][y]=0;
				}
			}
		}
		src=(src+1)%2;
		alt=(alt+1)%2;
	}
	char convert[4]={'.','!','X','#'};
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=20;j++)
		{
			printf("%c",convert[dish[alt][i][j]]);
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}