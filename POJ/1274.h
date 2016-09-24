// 1274 The Perfect Stall

#include<iostream>

using namespace std;

#include<cstdio>

int n,m;
bool g[201][201];
int result;
int link[201];
bool flag[201];

bool findPath(int index)
{
	for(int i=0;i<m;i++)
	{
		if(g[index][i]&&!flag[i])
		{
			flag[i]=true;
			if(link[i]<0||findPath(link[i]))
			{
				link[i]=index;
				return true;
			}
		}
	}
	return false;
}

int getMaxMatch()
{
	int result=0;
	for(int i=0;i<n;i++)
	{
		memset(flag,0,sizeof(flag));
		if(findPath(i))
		{
			result++;
		}
	}
	return result;
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(g,0,sizeof(g));
		memset(link,-1,sizeof(link));
		for(int i=0;i<n;i++)
		{
			int k;
			scanf("%d",&k);
			for(int j=0;j<k;j++)
			{
				int r;
				scanf("%d",&r);
				g[i][r-1]=true;
			}
		}
		printf("%d\n",getMaxMatch());
	}
	//system("pause");
	return 0;
}