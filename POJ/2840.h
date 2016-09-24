// 2840 Big Clock

#include<stdio.h>
//#include<iostream>

int main()
{
	int t;
	int h,m;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d:%d",&h,&m);
		if(m==0)
		{
			printf("%d\n",(h+11)%24+1);
		}
		else
		{
			printf("0\n");
		}
	}
	//system("pause");
	return 0;
}