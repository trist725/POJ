// 2993 Emag eht htiw Em Pleh

#include<iostream>

using namespace std;

int main()
{
	char chess[8][8];
	memset(chess,0,sizeof(chess));
	char ch;
	char dot,r,c;
	while(cin>>ch&&ch!=':')
	{
		;
	}
	ch=',';
	while(ch==',')
	{
		cin>>ch;
		if(ch>='A'&&ch<='Z')
		{
			dot=ch;
			cin>>c>>r;
		}
		else
		{
			dot='P';
			c=ch;
			cin>>r;
		}
		chess[8-(r-'0')][c-'a']=dot;
		cin>>ch;
	}
	while(ch!=':')
	{
		cin>>ch;
	}
	ch=',';
	while(ch==',')
	{
		cin>>ch;
		if(ch>='A'&&ch<='Z')
		{
			dot=ch;
			cin>>c>>r;
		}
		else
		{
			dot='P';
			c=ch;
			cin>>r;
		}
		chess[8-(r-'0')][c-'a']=dot+('a'-'A');
		cin>>ch;
	}
	char bg;
	cout<<"+---+---+---+---+---+---+---+---+"<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<"|";
		for(int j=0;j<8;j++)
		{
			bg=(i+j)%2?':':'.';
			cout<<bg;
			if(chess[i][j]!=0)
			{
				cout<<chess[i][j];
			}
			else
			{
				cout<<bg;
			}
			cout<<bg<<"|";
		}
		cout<<endl;
		cout<<"+---+---+---+---+---+---+---+---+"<<endl;
	}
	//system("pause");
	return 0;
}