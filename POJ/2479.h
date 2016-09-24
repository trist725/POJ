// 2479 Maximum sum

#include<iostream>
using namespace std;

#include<stdio.h>

#define MIN_SIGN_INT -0xfffffff

int main()
{
	int caseCount;
	int num[50010];
	int lmax[50010];
	int rmax[50010];
	int length;
	int sum;
	int max;
	int maxSum;
	int currSum;
	scanf("%d",&caseCount);
	for(int c=0;c<caseCount;c++)
	{
		scanf("%d",&length);
		for(int i=0;i<length;i++)
		{
			scanf("%d",&num[i]);
		}
		sum=num[0];
		max=sum;
		lmax[0]=max;
		for(int i=1;i<length;i++)
		{
			if(sum>0)
			{
				sum+=num[i];
			}
			else
			{
				sum=num[i];
			}
			if(sum>max)
			{
				max=sum;
			}
			lmax[i]=max;
		}
		sum=num[length-1];
		max=sum;
		rmax[length-1]=max;
		for(int i=length-2;i>=0;i--)
		{
			if(sum>0)
			{
				sum+=num[i];
			}
			else
			{
				sum=num[i];
			}
			if(sum>max)
			{
				max=sum;
			}
			rmax[i]=max;
		}
		maxSum=lmax[0]+rmax[1];
		for(int i=1;i<length;i++)
		{
			currSum=lmax[i-1]+rmax[i];
			if(currSum>maxSum)
			{
				maxSum=currSum;
			}
		}
		printf("%d\n",maxSum);
	}
	//system("pause");
	return 0;
}