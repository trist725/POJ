// 1005 I Think I Need a Houseboat

#include<iostream>

using namespace std;

#include<cmath>

int main()
{
	int n;
	cin>>n;
	double x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		cout<<"Property "<<i<<": This property will begin eroding in year ";
		cout<<(int)ceil((x*x+y*y)*3.14/100)<<"."<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	//system("pause");
	return 0;
}