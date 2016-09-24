// 3278 Catch That Cow

#include<iostream>

using namespace std;

int mark[200001];
int que[200001];

int main()
{
	memset(mark,-1,sizeof(mark));
	int n,k;
	cin>>n>>k;
	if(n>=k)
	{
		cout<<n-k;
	}
	else
	{
		mark[n]=0;
		que[0]=n;
		int l=1;
		int idx=0;
		while(idx<l)
		{
			int i=que[idx];
			idx++;
			if(i<200000&&mark[i+1]<0)
			{
				if(i+1==k)
				{
					cout<<mark[i]+1<<endl;
					break;
				}
				mark[i+1]=mark[i]+1;
				que[l]=i+1;
				l++;
			}
			if(i>0&&mark[i-1]<0)
			{
				if(i-1==k)
				{
					cout<<mark[i]+1<<endl;
					break;
				}
				mark[i-1]=mark[i]+1;
				que[l]=i-1;
				l++;
			}
			if(i<=100000&&mark[2*i]<0)
			{
				if(2*i==k)
				{
					cout<<mark[i]+1<<endl;
					break;
				}
				mark[2*i]=mark[i]+1;
				que[l]=2*i;
				l++;
			}
		}
	}
	system("pause");
	return 0;
}