// 2521 How much did the businessman lose

#include<stdio.h>
//#include<iostream>

int main()
{
	int n,m,p,c;
	scanf("%d%d%d%d",&n,&m,&p,&c);
	while(n!=0||m!=0||p!=0||c!=0)
	{
		printf("%d\n",-(m-n-p));
		scanf("%d%d%d%d",&n,&m,&p,&c);
	}
	//system("pause");
	return 0;
}