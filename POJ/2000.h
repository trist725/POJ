// 2000 Gold Coins

#include<iostream>
using namespace std;

int main()
{
	int lastDay;
	while(cin>>lastDay&&lastDay>0)
	{
		int currDay=0;
		int pay=0;
		int i=1;
		while(currDay<lastDay)
		{
			if(currDay+i<=lastDay)
			{
				pay+=i*i;
				currDay+=i;
			}
			else
			{
				pay+=(lastDay-currDay)*i;
				currDay=lastDay;
			}
			i++;
		}
		cout<<lastDay<<" "<<pay<<endl;
	}
	//system("pause");
	return 0;
}