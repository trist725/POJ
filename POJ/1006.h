// 1006 Biorhythms

#include<iostream>

using namespace std;

int main()
{
	int c=1;
	int p,e,i,d;
	cin>>p>>e>>i>>d;
	while(p!=-1)
	{
		int n=(p*5544+e*14421+i*1288-d+21252)%21252; 
		if(n==0)
		{
			n=21252;
		}
		cout<<"Case "<<c<<": the next triple peak occurs in "<<n<<" days."<<endl;
		cin>>p>>e>>i>>d;
		c++;
	}
	//system("pause");
	return 0;
}