// 1753 flipBoard Game

#include<iostream>

using namespace std;

//#include<queue>
//#include<stack>
//
//int shift[16];

//struct State
//{
//	int Step;
//	int LastBoard;
//	int LastGo;
//};

int flip(int board,int i)
{
	board=board^(1<<i);
	int r=i/4;
	for(int k=0;k<4;k++)
	{
		//board=board^(shift[r*4+k]);
		board=board^(1<<(r*4+k));
	}
	int c=i%4;
	for(int k=0;k<4;k++)
	{
		//board=board^(shift[k*4+c]);
		board=board^(1<<(k*4+c));
	}
	return board;
}

//int main()
//{
//	State state[65536];
//	queue<int> q;
//	int initBoard=0;
//	int flipBoard;
//	char point;
//	for(int i=0;i<16;i++)
//	{
//		shift[i]=1<<i;
//	}
//	for(int i=0;i<16;i++)
//	{
//		cin>>point;
//		if(point=='+')
//		{
//			initBoard=(shift[i])|initBoard;
//		}
//	}
//	memset(state,0,sizeof(state));
//	q.push(initBoard);
//	state[initBoard].Step=1;
//	bool achieve=false;
//	int dot;
//	if(initBoard==0)
//	{
//		cout<<0<<endl;
//		achieve=true;
//	}
//	int board;
//	while(!q.empty()&&!achieve)
//	{
//		board=q.front();
//		q.pop();
//		for(int i=0;i<16;i++)
//		{
//			flipBoard=flip(board,i);
//			if(state[flipBoard].Step==0)
//			{
//				state[flipBoard].Step=state[board].Step+1;
//				state[flipBoard].LastBoard=board;
//				state[flipBoard].LastGo=i;
//				q.push(flipBoard);
//			}
//			if(flipBoard==0)
//			{
//				achieve=true;
//			}
//		}
//	}
//	if(achieve)
//	{
//		stack<int> path;
//		cout<<state[0].Step-1<<endl;
//		for(int i=0;i!=initBoard;i=state[i].LastBoard)
//		{
//			path.push(state[i].LastGo);
//		}
//		while(!path.empty())
//		{
//			cout<<path.top()/4+1<<" "<<path.top()%4+1<<endl;
//			path.pop();
//		}
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	int board=0;
	char dot;
	for(int i=0;i<16;i++)
	{
		cin>>dot;
		if(dot=='+')
		{
			board=flip(board,i);
		}
	}
	int path[16];
	int step=0;
	for(int i=0;i<16;i++)
	{
		if((board>>i)&1)
		{
			path[step]=i;
			step++;
		}
	}
	cout<<step<<endl;
	for(int i=0;i<step;i++)
	{
		cout<<(path[i]/4+1)<<" "<<(path[i]%4+1)<<endl;
	}
	//system("pause");
	return 0;
}