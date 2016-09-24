// 1719 Shooting Contest

#include<iostream>

using namespace std;

#include<cstdio>

int r,c;
int g[1001][2];
bool assign[1001];
int link[1001];
int path[1001];

bool findPath(int index)
{
	for(int i=0;i<2;i++)
	{
		int t=g[index][i];
		if(!assign[t])
		{
			assign[t]=true;
			if(link[t]==0||findPath(link[t]))
			{
				link[t]=index;
				return true;
			}
		}
	}
	return false;
}

bool haxMaxMatch()
{
	int result=0;
	for(int i=1;i<=c;i++)
	{
		memset(assign,0,sizeof(assign));
		if(findPath(i))
		{
			result++;
		}
	}
	return result>=r;
}


void printPath()
{
	memset(path,0,sizeof(path));
	for(int i=1;i<=r;i++)
	{
		path[link[i]]=i;
	}
	for(int i=1;i<=c;i++)
	{
		if(i>1)
		{
			printf(" ");
		}
		if(path[i]>0)
		{
			printf("%d",path[i]);
		}
		else
		{
			printf("%d",g[i][0]);
		}
	}
	printf("\n");
}

int main()
{
	int x;
	scanf("%d",&x);
	for(int i=0;i<x;i++)
	{
		memset(link,0,sizeof(link));
		scanf("%d%d",&r,&c);
		for(int j=1;j<=c;j++)
		{
			scanf("%d%d",&g[j][0],&g[j][1]);
		}
		if(haxMaxMatch())
		{
			printPath();
		}
		else
		{
			printf("NO\n");
		}
	}
	//system("pause");
	return 0;
}