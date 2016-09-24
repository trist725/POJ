// 1028 Web Navigation

#include <iostream>
using namespace std;

#include<string>

#include<stack>

int main()
{
	const string CMD_VISIT="VISIT";
	const string CMD_BACK="BACK";
	const string CMD_FORWARD="FORWARD";
	const string CMD_QUIT ="QUIT";
	const string RLT_IGNORED ="Ignored";
	stack<string>* backward=new stack<string>;
	stack<string>* forward=new stack<string>;
	string currentUrl="http://www.acm.org/";
	bool isOver=false;
	string command;
	while(!isOver)
	{
		cin>>command;
		if(command==CMD_VISIT)
		{
			backward->push(currentUrl);
			cin>>currentUrl;
			cout<<currentUrl<<endl;
			delete forward;
			forward=new stack<string>;
		}
		else if(command==CMD_BACK)
		{
			if(!backward->empty())
			{
				forward->push(currentUrl);
				currentUrl=backward->top();
				cout<<currentUrl<<endl;
				backward->pop();
			}
			else
			{
				cout<<RLT_IGNORED<<endl;
			}
		}
		else if(command==CMD_FORWARD)
		{
			if(!forward->empty())
			{
				backward->push(currentUrl);
				currentUrl=forward->top();
				cout<<currentUrl<<endl;
				forward->pop();
			}
			else
			{
				cout<<RLT_IGNORED<<endl;
			}
		}
		else 
		{
			isOver=true;
		}
	}
	delete backward;
	delete forward;
	//system("pause");
	return 0;
}