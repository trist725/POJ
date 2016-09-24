// 1014 Dividing

#include<stdio.h>
#include<iostream>

int count[6];
int limit[6]={8,6,8,8,12,8};
bool dp[200];

int main()
{
	int n=0;
	while(true)
	{
		n++;
		int sum=0;
		int target;
		for(int i=0;i<6;i++)
		{
			scanf("%d",&count[i]);
			if(count[i]>=limit[i])
			{
				if(count[i]%2==0)
				{
					count[i]=limit[i];
				}
				else
				{
					count[i]=limit[i]-1;
				}
			}
			sum+=count[i]*(i+1);
		}
		if(sum==0)
		{
			break;
		}
		if(sum%2==0)
		{
			if(count[0]>=6)
			{
				printf("Collection #%d:\nCan be divided.\n\n",n);
				continue;
			}
			target=sum/2;
		}
		else
		{
			printf("Collection #%d:\nCan't be divided.\n\n",n);
			continue;
		}
		memset(dp,false,sizeof(dp));
		dp[0]=true;
		for(int i=0;i<6;i++)
		{
			for(int j=1;j<=count[i];j++)
			{
				for(int k=target;k>=i+1;k--)
				{
					dp[k]=dp[k]||dp[k-i-1];
				}
			}
		}
		if(dp[target])
		{
			printf("Collection #%d:\nCan be divided.\n\n",n);
		}
		else
		{
			printf("Collection #%d:\nCan't be divided.\n\n",n);
		}
	}
	return 0;
}

//以下是错误理解题意的代码，通过回溯求解
//
//#include<stdio.h>
//#include<iostream>
//
//int value[6];
//int mark[6];
//
//int main()
//{
//	int n=0;
//	while(true)
//	{
//		n++;
//		int sum=0;
//		int target;
//		for(int i=0;i<6;i++)
//		{
//			scanf("%d",&value[i]);
//			sum+=value[i];
//			mark[i]=0;
//		}
//		if(sum==0)
//		{
//			break;
//		}
//		if(sum%2==0)
//		{
//			target=sum/2;
//		}
//		else
//		{
//			printf("Collection #%d:\nCan't be divided.\n\n",n);
//			continue;
//		}
//		bool find=false;
//		int curr=0;
//		for(int i=0;i>=0;)
//		{
//			if(i>=6)
//			{
//				if(curr==target)
//				{
//					printf("Collection #%d:\nCan be divided.\n\n",n);
//					find=true;
//					break;
//				}
//				else
//				{
//					i--;
//				}
//			}
//			else
//			{
//				if(mark[i]==0)
//				{
//					mark[i]=1;
//					i++;
//				}
//				else
//				{
//					if(mark[i]==1)
//					{
//						curr+=value[i];
//						if(curr>target)
//						{
//							mark[i]=0;
//							i--;
//						}
//						else
//						{
//							mark[i]=-1;
//							i++;
//						}
//					}
//					else
//					{
//						mark[i]=0;
//						curr-=value[i];
//						i--;
//					}
//				}
//			}
//		}
//		if(!find)
//		{
//			printf("Collection #%d:\nCan't be divided.\n\n",n);
//		}
//	}
//	system("pause");
//	return 0;
//}