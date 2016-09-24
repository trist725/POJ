// 1065 Wooden Sticks

#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

struct Stick
{
	int Length;
	int Weight;
	bool Fit;
}sticks[5010];
int n;

inline bool Compare(const Stick &left,const Stick &right)
{
	if(left.Length==right.Length)
	{
		return left.Weight<right.Weight;
	}
	else
	{
		return left.Length<right.Length;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&sticks[i].Length,&sticks[i].Weight);
			sticks[i].Fit=false;
		}
		sort(sticks,&sticks[n],Compare);
		int setup=0;
		for(int left=n;left>0;)
		{
			int currWeight=-1;
			for(int i=0;i<n;i++)
			{
				if(!sticks[i].Fit&&sticks[i].Weight>=currWeight)
				{
					currWeight=sticks[i].Weight;
					sticks[i].Fit=true;
					left--;
				}
			}
			setup++;
		}
		printf("%d\n",setup);
	}
	//system("pause");
	return 0;
}