// 1163 The Triangle

#include<iostream>

using namespace std;

#include<stdio.h>

int main()
{
	int height;
	scanf("%d",&height);		
	int*last=new int[height];
	int*current=new int[height];
	int num;
	int*temp;
	last[0]=0;
	for(int currHeight=0;currHeight<height;currHeight++)
	{
		for(int i=0;i<=currHeight;i++)
		{
			scanf("%d",&num);
			if(i>0&&i<currHeight)
			{
				if(last[i]>last[i-1])
				{
					current[i]=last[i]+num;
				}
				else
				{
					current[i]=last[i-1]+num;
				}
			}
			else
			{
				if(i<=0)
				{
					current[i]=last[0]+num;
				}
				else
				{
					if(i>=currHeight)
					{
						current[i]=last[currHeight-1]+num;
					}
				}
			}
		}
		temp=last;
		last=current;
		current=temp;
	}
	int maxSum=last[0];
	for(int i=1;i<height;i++)
	{
		if(last[i]>maxSum)
		{
			maxSum=last[i];
		}
	}
	cout<<maxSum<<endl;
	delete last;
	delete current;
	//system("pause");
	return 0;
}