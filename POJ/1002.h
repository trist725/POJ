// 1002 487-3279

#include<iostream>

using namespace std;

#include<cstdio>
#include<string>
#include<set>

int nummap[10000000];

int main()
{
	int n;
	scanf("%d",&n);
	char ch;
	int num;
	int power;
	set<int> dictSet;
	set<int>::iterator setitr;
	memset(nummap,0,sizeof(nummap));
	for(int i=0;i<n;i++)
	{
		num=0;
		power=1000000;
		for(int j=0;j<7;j++)
		{
			while(scanf("%c",&ch)!=EOF&&(((ch<'0'||ch>'9')&&(ch<'A'||ch>='Z'))||(ch=='Q')))
			{
				;
			}
			if(ch>='A'&&ch<'Q')
			{
				ch=(ch-'A')/3+'2';
			}
			else if(ch>'Q'&&ch<='Z')
			{
				ch=(ch-'B')/3+'2';
			}
			ch-='0';
			num+=ch*power;
			power/=10;

		}
		nummap[num]++;
		dictSet.insert(num);
	}
	int output=0;
	int count;
	for(setitr=dictSet.begin();setitr!=dictSet.end();setitr++)
	{
		count=nummap[*setitr];
		if(count>1)
		{
			printf("%03d-%04d %d\n",*setitr/10000,*setitr%10000,count);
			output++;
		}
	}
	if(output==0)
	{
		printf("No duplicates.\n");
	}
	//system("pause");
	return 0;
}