// 1125 Stockbroker Grapevine

#include<iostream>

using namespace std;

#include<cstdio>

#define MAX_UNSIGNED_SHORT 0xffff

int main()
{
	int n;
	unsigned short m[101][101];
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		memset(m,MAX_UNSIGNED_SHORT,sizeof(m));
		for(int i=1;i<=n;i++)
		{
			m[i][i]=0;
			int c;
			scanf("%d",&c);
			for(int j=0;j<c;j++)
			{
				int dest,time;
				scanf("%d%d",&dest,&time);
				m[i][dest]=time;
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for( int j=1;j<=n;j++)
				{
					if(m[i][j]>(m[i][k]+m[k][j]))
					{
						m[i][j]=m[i][k]+m[k][j];
					}
				}
			}
		}
		int min=MAX_UNSIGNED_SHORT;
		int rlt=0;
		for(int i=1;i<=n;i++)
		{
			int max=0;
			for(int j=1;j<=n;j++)
			{
				if(m[i][j]>max)
				{
					max=m[i][j];
				}
			}
			if(max<min)
			{
				min=max;
				rlt=i;
			}
		}
		if(min<MAX_UNSIGNED_SHORT)
		{
			printf("%d %d\n",rlt,min);
		}
		else
		{
			printf("disjoint\n");
		}
	}
	//system("pause");
	return 0;
}