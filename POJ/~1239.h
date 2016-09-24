// 1239 Increasing Sequences

#include<iostream>

using namespace std;

#include<cstring>

#define MAX_INT 0xffffff

char seq[100];
__int64 num[100];
int index;

__int64 stoi(int ri,int l)
{
	__int64 n=0;
	__int64 p=1;
	char*s=&seq[ri];
	while(l>0)
	{
		n+=(*s-'0')*p;
		s--;
		p*=10;
		l--;
	}
	return n;
}


bool check(li,max)
{

}

int main()
{
	scanf("%s",seq);
	while(strcmp(seq,"0")!=0)
	{
		index=0;
		check(strlen(seq)-1,MAX_INT);
		for(int i=index-1;i>0;i--)
		{
			printf("%I64d,",num[i]);
		}
		printf("%I64d\n",num[i]);
		scanf("%s",seq);
	}
	system("pause");
	return 0;
}