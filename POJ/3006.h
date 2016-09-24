// 3006 Dirichlet's Theorem on Arithmetic Progressions

#include<iostream>

using namespace std;

int main()
{
	bool prime[1000000];
	memset(prime,-1,sizeof(prime));
	prime[1]=false;
	for(int i=2;i<500000;i++)
	{
		for(int j=2*i;j<1000000;j+=i)
		{
			prime[j]=false;
		}
	}
	int a,d,n;
	cin>>a>>d>>n;
	while(a!=0)
	{
		int num=a;
		for(int i=1;i<=n;)
		{
			if(prime[num])
			{
				i++;
			}
			num+=d;
		}
		cout<<num-d<<endl;
		cin>>a>>d>>n;
	}
	system("pause");
	return 0;
}