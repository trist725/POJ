// 2109 Power of Cryptography

#include<iostream>

using namespace std;

#include<math.h>

int main()
{
	double n,p;
	while(scanf("%lf%lf",&n,&p)==2)
	{
		printf("%.0lf\n",pow(p,1.0/n));
	}
	return 0;
}
