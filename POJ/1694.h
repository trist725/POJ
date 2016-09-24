// 1694 An Old Stone Game

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

vector<int> child[210];

int Count(int p)
{
	vector<int> need;
	for(vector<int>::iterator itr=child[p].begin();itr!=child[p].end();itr++)
	{
		need.push_back(Count(*itr));
	}
	sort(need.begin(),need.end(),greater<int>());
	int total=1;
	int left=1;
	for(vector<int>::iterator itr=need.begin();itr!=need.end();itr++)
	{
		int curr=*itr;
		if(left>=curr)
		{
			left--;
		}
		else
		{
			total+=curr-left;
			left=curr-1;
		}
	}
	return total;
}

int main()
{
	int m;
	scanf("%d",&m);
	for(int a=0;a<m;a++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int p;
			int pn;
			scanf("%d%d",&p,&pn);
			child[p].clear();
			for(int j=0;j<pn;j++)
			{
				int c;
				scanf("%d",&c);
				child[p].push_back(c);
			}
		}
		if(n==0)
		{
			printf("0\n",Count(1));
		}
		else
		{
			printf("%d\n",Count(1));
		}
	}
	//system("pause");
	return 0;
}