// 1171 Letter Game

#include<iostream>

using namespace std;

#include<cstdio>
#include<cstring>

int v[30];
int c[30];
int cc[30];
char words[40005][10];
int lens[400005];

int countScore(char*word)
{
	memset(cc,0,sizeof(cc));
	int cv=0;
	int i;
	for(char *pc=word;*pc!='\0';pc++)
	{
		i=*pc-'a';
		cc[i]++;
		if(v[i]<0||cc[i]>c[i])
		{
			return -1;
		}
		else
		{
			cv+=v[i];
		}
	}
	return cv;
}

int main()
{
	int value[]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
	char word[30];
	scanf("%s",word);
	memset(v,-1,sizeof(v));
	memset(c,0,sizeof(c));
	char*pc;
	int maxv=0;
	int idx;
	for(pc=word;*pc!='\0';pc++)
	{
		idx=*pc-'a';
		v[idx]=value[idx];
		maxv+=value[idx];
		c[idx]++;
	}
	int cv;
	int smax=0;
	int i=0;
	char tword[30];
	int len;
	while(scanf("%s",words[i])!=EOF&&words[i][0]!='.')
	{
		if(smax!=maxv)
		{
			len=strlen(words[i]);
			lens[i]=len;
			cv=countScore(words[i]);
			if(cv<0||len<3||len>7)
			{
				continue;
			}
			if(cv>smax)
			{
				smax=cv;
			}
			if(len<=4)
			{
				strcpy(tword,words[i]);
				for(int j=0;j<i;j++)
				{
					if(lens[j]+len<=7)
					{
						strcpy(tword+len,words[j]);
						cv=countScore(tword);
						if(cv>smax)
						{
							smax=cv;
						}
					}
				}
			}
			i++;
		}
	}
	printf("%d\n",smax);
	//system("pause");
	return 0;
}