// 1552 Doubles

#include<stdio.h>
#include<iostream>

int main()
{
	bool mark[100];
	int num[16];
	num[0]=0;
	while(num[0]!=-1)
	{
		memset(mark,false,sizeof(mark));
		int i=-1;
		do
		{
			i++;
			scanf("%d",&num[i]);
			if(num[i]>0)
			{
				mark[num[i]]=true;
			}
		}while(num[i]>0);
		if(num[0]!=-1)
		{
			int value=0;
			for(int j=0;j<i;j++)
			{
				if(num[j]<50&&mark[num[j]*2])
				{
					value++;
				}
			}
			printf("%d\n",value);
		}
	}
	//system("pause");
	return 0;
}