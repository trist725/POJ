// 1708 Game

#include<stdio.h>
#include<iostream>

int n,l,k,q;
int circle[110];
bool line[110][110][110];
struct
{
	int First;
	int Second;
	int Step;
}queue[10000];
bool mark[110][110];

int main()
{
	scanf("%d%d%d%d",&n,&l,&k,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&circle[i]);
	}
	int m;
	memset(line,false,sizeof(line));
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		line[a][b][c]=true;
	}
	memset(mark,false,sizeof(mark));
	for(int i=0;i<=n;i++)
	{
		mark[i][i]=true;
	}
	int qi=0;
	int ql=1;
	queue[0].First=l;
	queue[0].Second=k;
	queue[0].Step=0;
	mark[l][k]=true;
	mark[k][l]=true;
	bool find=false;
	while(qi<ql&&!find)
	{
		int first=queue[qi].First;
		int second=queue[qi].Second;
		int step=queue[qi].Step+1;
		qi++;
		for(int i=1;i<=n;i++)
		{
			if(line[first][i][circle[second]]&&!mark[i][second])
			{
				if(i==q)
				{
					printf("YES\n%d\n",step);
					find=true;
				}
				queue[ql].First=i;
				queue[ql].Second=second;
				queue[ql].Step=step;
				mark[i][second]=true;
				mark[second][i]=true;
				ql++;
			}
			if(line[second][i][circle[first]]&&!mark[first][i])
			{
				if(i==q)
				{
					printf("YES\n%d\n",step);
					find=true;
				}
				queue[ql].First=first;
				queue[ql].Second=i;
				queue[ql].Step=step;
				mark[first][i]=true;
				mark[i][first]=true;
				ql++;
			}
		}
	}
	if(!find)
	{
		printf("NO\n");
	}
	system("pause");
	return 0;
}