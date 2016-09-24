// 1308	Is It A Tree?

#include<stdio.h>
#include<iostream>
#include<set>

using namespace std;

int father[1100];
set<int> node;

int main()
{
	int k=0;
	int src,dest;
	int num=0;
	bool isTree=true;
	memset(father,-1,sizeof(father));
	scanf("%d%d",&src,&dest);
	while(src>=0&&dest>=0)
	{
		num++;
		if(src==0&&dest==0)
		{
			k++;
			isTree=isTree&&(num==node.size()||num==1);
			for(set<int>::iterator itr=node.begin();itr!=node.end()&&isTree;itr++)
			{
				int start=*itr;
				int curr=father[start];
				if(curr!=-1)
				{
					while(father[curr]>0&&curr!=start)
					{
						curr=father[curr];
					}
				}
				if(curr==start)
				{
					isTree=false;
				}
			}
			if(isTree)
			{
				printf("Case %d is a tree.\n",k);
			}
			else
			{
				printf("Case %d is not a tree.\n",k);
			}
			memset(father,-1,sizeof(father));
			node.clear();
			num=0;
			isTree=true;
		}
		else
		{
			if(isTree)
			{
				if(src==dest)
				{
					isTree=false;
				}
				else
				{
					if(father[dest]==-1)
					{
						node.insert(src);
						node.insert(dest);
						father[dest]=src;
					}
					else
					{
						isTree=false;
					}
				}
			}
		}
		scanf("%d%d",&src,&dest);
	}
	//system("pause");
	return 0;
}