// 2385 Apple Catching

#include<stdio.h>
#include<iostream>

int t,w;
int fall[1001];
int dp[1001][32];

int query(int i,int j)
{
	if(dp[i][j]>=0)
	{
		return dp[i][j];
	}
	if(j>0)
	{
		int lastNoMove=query(i-2,j);
		int lastMove=query(i-1,j-1);
		dp[i][j]=lastNoMove>lastMove?lastNoMove:lastMove;
		dp[i][j]+=fall[i];
	}
	else
	{
		dp[i][j]=query(i-2,j)+fall[i];
	}
	return dp[i][j];
}

int main()
{
	scanf("%d%d",&t,&w);
	int curr=1;
	int idx=0;
	fall[idx]=0;
	int n;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		if(n==curr)
		{
			fall[idx]++;
		}
		else
		{
			curr=n;
			fall[++idx]=1;
		}
	}
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<w;i++)
	{
		dp[0][i]=fall[0];
		dp[1][i]=fall[0]+fall[1];
	}
	dp[1][0]=0;
	int a=query(idx,w);
	int b=0;
	if(idx>0)
	{
		b=query(idx-1,w);
	}
	printf("%d\n",a>b?a:b);
	//system("pause");
	return 0;
}