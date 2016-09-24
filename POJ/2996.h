// 2996 Help Me with the Game

#include<iostream>

using namespace std;

#include<string>
#include<cstring>

int main()
{
	char chess[2][16][4];
	char r='9';
	char c;
	char ch;
	string buffer;
	memset(chess,0,sizeof(chess));
	while(r>'0')
	{
		cin>>ch;
		if(ch=='+')
		{
			cin>>buffer;
			c='a'-1;
			r--;
		}
		else if(ch=='|')
		{
			c++;
		}
		else if(ch>='a'&&ch<='z')
		{
			int fillPos;
			switch(ch)
			{
			case 'k':
				fillPos=0;
				break;
			case 'q':
				fillPos=1;
				break;
			case 'r':
				if(chess[1][2][0]=='\0')
				{
					fillPos=2;
				}
				else
				{
					fillPos=3;
				}
				break;
			case 'b':
				if(chess[1][4][0]=='\0')
				{
					fillPos=4;
				}
				else
				{
					fillPos=5;
				}
				break;
			case 'n':
				if(chess[1][6][0]=='\0')
				{
					fillPos=6;
				}
				else
				{
					fillPos=7;
				}
				break;
			default:
				fillPos=8;
				while(chess[1][fillPos][0]!='\0')
				{
					fillPos++;
				}
				break;
			}
			ch=ch-('a'-'A');
			if(ch=='P')
			{
				chess[1][fillPos][0]=c;
				chess[1][fillPos][1]=r;
			}
			else
			{
				chess[1][fillPos][0]=ch;
				chess[1][fillPos][1]=c;
				chess[1][fillPos][2]=r;
			}
		}
		else if(ch>='A'&&ch<='Z')
		{
			int fillPos;
			switch(ch)
			{
			case 'K':
				fillPos=0;
				break;
			case 'Q':
				fillPos=1;
				break;
			case 'R':
				if(chess[0][3][0]=='\0')
				{
					fillPos=3;
				}
				else
				{
					if(chess[0][3][2]==r)
					{
						strcpy(chess[0][2],chess[0][3]);
						fillPos=3;
					}
					else
					{
						fillPos=2;
					}
				}
				break;
			case 'B':
				if(chess[0][5][0]=='\0')
				{
					fillPos=5;
				}
				else
				{
					if(chess[0][5][2]==r)
					{
						strcpy(chess[0][4],chess[0][5]);
						fillPos=5;
					}
					else
					{
						fillPos=4;
					}
				}
				break;
			case 'N':
				if(chess[0][7][0]=='\0')
				{
					fillPos=7;
				}
				else
				{
					if(chess[0][7][2]==r)
					{
						strcpy(chess[0][6],chess[0][7]);
						fillPos=7;
					}
					else
					{
						fillPos=6;
					}
				}
				break;
			default:
				fillPos=15;
				while(chess[0][fillPos][0]!='\0')
				{
					if(chess[0][fillPos][1]==r)
					{
						for(int i=7;i<fillPos;i++)
						{
							strcpy(chess[0][i],chess[0][i+1]);
						}
						break;
					}
					else
					{
						fillPos--;
					}
				}
				break;
			}
			if(ch=='P')
			{
				chess[0][fillPos][0]=c;
				chess[0][fillPos][1]=r;
			}
			else
			{
				chess[0][fillPos][0]=ch;
				chess[0][fillPos][1]=c;
				chess[0][fillPos][2]=r;
			}
		}
	}
	bool sep=false;
	cout<<"White: ";
	for(int i=0;i<16;i++)
	{
		if(chess[0][i][0]!='\0')
		{
			if(!sep)
			{
				sep=true;
			}
			else
			{
				cout<<",";
			}
			cout<<chess[0][i];
		}
	}
	cout<<endl;
	sep=false;
	cout<<"Black: ";
	for(int i=0;i<16;i++)
	{
		if(chess[1][i][0]!='\0')
		{
			if(!sep)
			{
				sep=true;
			}
			else
			{
				cout<<",";
			}
			cout<<chess[1][i];
		}
	}
	cout<<endl;
	//system("pause");
	return 0;
}