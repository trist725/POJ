// 2586 Y2K Accounting Bug

#include<iostream>

using namespace std;

int main()
{
	int s,d;
	while(cin>>s>>d)
	{
		int sum=-1;
		if(4*s-d<0)
		{
			sum=10*s-2*d;
		}
		else if(3*s-2*d<0)
		{
			sum=8*s-4*d;
		}
		else if(2*s-3*d<0)
		{
			sum=6*s-6*d;
		}
		else if(s-4*d<0)
		{
			sum=3*s-9*d;
		}
		if(sum>0)
		{
			cout<<sum<<endl;
		}
		else
		{
			cout<<"Deficit"<<endl;
		}
	}
	return 0;
}