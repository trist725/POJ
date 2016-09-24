// 1887 Testing the CATCHER

#include<iostream>

using namespace std;

#include<stdio.h>

int main()
{
	int caseNum=0;
	int num[33000];
	int history[33000];
	int i=0;
	while(scanf("%d",&num[i])&&num[i]!=-1)
	{
		i++;
		caseNum++;
		if(caseNum!=1)
		{
			printf("\n");
		}
		while(scanf("%d",&num[i])&&num[i]!=-1)
		{
			i++;
		}
		int max=1;
		for(int j=0;j<i;j++)
		{
			int currMax=0;
			for(int k=0;k<j;k++)
			{
				if(num[j]<=num[k]&&history[k]>currMax)
				{
					currMax=history[k];
				}
			}
			currMax++;
			history[j]=currMax;
			if(currMax>max)
			{
				max=currMax;
			}
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n",caseNum,max);
		i=0;
	}
	//system("pause");
	return 0;
}