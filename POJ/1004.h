// 1004 Financial Management

#include<iostream>
using namespace std;

int main()
{
	double Sum=0;
	double Num;
	for(int i=0;i<12;i++)
	{
		cin>>Num;
		Sum+=Num;
	}
	cout<<"$"<<Sum/12<<endl;
	return 0;
}