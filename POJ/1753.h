// 1753 flipBoard Game

#include<iostream>

using namespace std;

#include<queue>

int flip(int board,int i)
{
	int dot;
	board=board^(1<<i);
	if(i/4>0)
	{
		board=board^(1<<i-4);
	}
	if(i/4<3)
	{
		board=board^(1<<i+4);
	}
	if(i%4>0)
	{
		board=board^(1<<i-1);
	}
	if(i%4<3)
	{
		board=board^(1<<i+1);
	}
	return board;
}

int main()
{
	int state[65536];
	queue<int> q;
	int board=0;
	int flipBoard;
	char point;
	for(int i=0;i<16;i++)
	{
		cin>>point;
		if(point=='w')
		{
			board=(1<<i)|board;
		}
	}
	memset(state,0,sizeof(state));
	q.push(board);
	state[board]=1;
	bool achieve=false;
	int dot;
	if(board==0||board==65535)
	{
		cout<<0<<endl;
		achieve=true;
	}
	while(!q.empty()&&!achieve)
	{
		board=q.front();
		q.pop();
		for(int i=0;i<16;i++)
		{
			flipBoard=flip(board,i);
			if(flipBoard==0||flipBoard==65535)
			{
				cout<<(state[board])<<endl;
				achieve=true;
			}
			if(state[flipBoard]==0)
			{
				state[flipBoard]=state[board]+1;
				q.push(flipBoard);
			}
		}
	}
	if(!achieve)
	{
		cout<<"Impossible"<<endl;
	}
	//system("pause");
	return 0;
}