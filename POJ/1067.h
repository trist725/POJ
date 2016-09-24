// 1067 取石子游戏

#include<stdio.h>
#include<math.h>

const double GOLDEN=(1+sqrt(5.0))/2;

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a>b)
		{
			int temp=a;
			a=b;
			b=temp;
		}
		int k=(int)ceil(double(a)/GOLDEN);
		if(int(k*GOLDEN)==a&&b==a+k)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
	}
	return 0;
}