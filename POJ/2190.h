// 2190 ISBN

#include<stdio.h>
//#include<iostream>

int main()
{
	char isbn[20];
	scanf("%s",isbn);
	int mp=0;
	int value=0;
	for(int i=0;i<10;i++)
	{
		if(isbn[i]>='0'&&isbn[i]<='9')
		{
			int n=isbn[i]-'0';
			value+=n*(10-i);
		}
		else
		{
			if(i==9&&isbn[i]=='X')
			{
				value+=10;
			}
			else
			{
				if(isbn[i]=='?')
				{
					mp=10-i;
				}
			}
		}
	}
	int mv=-1;
	for(int i=10;i>=0;i--)
	{
		if((value+i*mp)%11==0)
		{
			mv=i;
		}
	}
	if(mv!=10)
	{
		printf("%d\n",mv);
	}
	else
	{
		if(mp==1)
		{
			printf("X\n");
		}
		else
		{
			printf("-1\n");
		}
	}
	//system("pause");
	return 0;
}