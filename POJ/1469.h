// 1469 COURSES

#include<iostream>

using namespace std;

#include<cstdio>

int n,m;
bool g[100][300];
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

bool hasFullMatch()
{
	for(int i=0;i<n;i++)
	{
		memset(assign,0,sizeof(assign));
		if(!findPath(i))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d%d",&n,&m);
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
		if(hasFullMatch())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	//system("pause");
	return 0;
}