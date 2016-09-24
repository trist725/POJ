// 2239 Selecting Courses

#include<iostream>

using namespace std;

#include<cstdio>

int n=84;
int m;
bool g[84][300];
int result;
int link[300];
bool assign[300];

bool findPath(int index)
{
	for(int i=0;i<m;i++)
	{
		if(g[index][i]&&!assign[i])
		{
			assign[i]=true;
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
		memset(assign,0,sizeof(assign));
		if(findPath(i))
		{
			result++;
		}
	}
	return result;
}

int main()
{
	while(scanf("%d",&m)!=EOF)
	{
		memset(g,0,sizeof(g));
		memset(link,-1,sizeof(link));
		for(int i=0;i<m;i++)
		{
			int k;
			scanf("%d",&k);
			for(int j=0;j<k;j++)
			{
				int r,s;
				scanf("%d%d",&r,&s);
				g[(r-1)*12+s-1][i]=true;
			}
		}
		printf("%d\n",getMaxMatch());
	}
	return 0;
}