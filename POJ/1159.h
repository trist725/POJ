// 1159 Palindrome

#include<iostream>

using namespace std;

int main()
{
	int length;
	char str[5100];
	cin>>length;
	cin>>str;
	int history[2][5100];
	int*curr=history[1];
	int*last=history[0];
	int*temp;
	for(int i=0;i<length+2;i++)
	{
		last[i]=0;
		curr[i]=0;
	}
	//for(int i=0;i<length;i++)
	//{
	//	for(int j=length-1;j>i;j--)
	//	{
	//		if(str[i]==str[j-1])
	//		{
	//			curr[j]=last[j+1]+1;
	//			curr[j]=last[j+1];
	//		}
	//		else
	//		{
	//			curr[j]=last[j]>curr[j+1]?last[j]:curr[j+1];
	//			curr[j]=(last[j]<curr[j+1]?last[j]:curr[j+1])+1;
	//		}
	//	}
	//	temp=last;
	//	last=curr;
	//	curr=temp;
	//}
	//cout<<length-last[1]<<endl;
	for(int i=length;i>0;i--)
	{
		for(int j=i;j<=length;j++)
		{
			if(str[i-1]==str[j-1])
			{
				curr[j]=last[j-1];
			}
			else
			{
				curr[j]=1+(last[j]<curr[j-1]?last[j]:curr[j-1]);
			}
		}
		temp=last;
		last=curr;
		curr=temp;
	}
	cout<<last[length]<<endl;
	//system("pause");
	return 0;
}