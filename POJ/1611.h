// 1611 The Suspects

#include<stdio.h>
#include<iostream>

int n,m;
int num[30010];
int father[30010];
int setRoot;

void Insert(int p)
{
	int pt=p;
	while(father[pt]>=0)
	{
		pt=father[pt];
	}
	if(pt!=setRoot)
	{
		father[pt]=setRoot;
		num[setRoot]+=num[pt];
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	while(n!=0||m!=0)
	{
		for(int i=0;i<n;i++)
		{
			num[i]=1;
		}
		memset(father,-1,sizeof(father));
		for(int i=0;i<m;i++)
		{
			int gn;
			scanf("%d",&gn);
			for(int j=0;j<gn;j++)
			{
				int p;
				scanf("%d",&p);
				if(j==0)
				{
					setRoot=p;
					while(father[setRoot]>=0)
					{
						setRoot=father[setRoot];
					}
				}
				Insert(p);
			}
		}
		int pt=0;
		while(father[pt]>=0)
		{
			pt=father[pt];
		}
		printf("%d\n",num[pt]);
		scanf("%d%d",&n,&m);
	}
	//system("pause");
	return 0;
}
