// 2860 Block game with the Little Prince

#include<iostream>

using namespace std;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int init[20];
	int final[20];
	for(int i=0;i<k;i++)
	{
		cin>>init[i];
	}
	for(int i=0;i<k;i++)
	{
		cin>>final[i];
	}
	int diff=0;
	for(int i=0;i<k;i++)
	{
		diff+=init[i]>final[i]?init[i]-final[i]:0;
	}
	cout<<diff<<endl;
	//system("pause");
	return 0;
}