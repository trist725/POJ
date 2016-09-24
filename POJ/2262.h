// 2262 Goldbach's Conjecture

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
	int n;
	cin>>n;
	while(n!=0)
	{
		int end=n/2;
		int i;
		for(i=2;i<end;i++)
		{
			if(prime[i]&&prime[n-i])
			{
				break;
			}
		}
		cout<<n<<" = "<<i<<" + "<<n-i<<endl;
		cin>>n;
	}
	//system("pause");
	return 0;
}