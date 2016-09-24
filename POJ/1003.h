// 1003 Hangover

#include<iostream>
using namespace std;

int main()
{
	double maxSum;
	while(cin>>maxSum&&maxSum>=0.01)
	{
		double sum=0;
		int i=2;
		while(sum<maxSum)
		{
			sum+=1.0/i;
			i++;
		}
		cout<<i-2<<" card(s)"<<endl;
	}
	//system("pause");
	return 0;
}