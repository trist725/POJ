// 2484 A Funny Game

#include<stdio.h>
//#include<iostream>

int main()
{
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		if(n<=2)
		{
			printf("Alice\n");
		}
		else
		{
			printf("Bob\n");
		}
		scanf("%d",&n);
	}
	//system("pasue");
	return 0;
}