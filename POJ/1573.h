// 1573 Robot Motion

#include<iostream>

using namespace std;

#include<cstdio>

int main()
{
	int m[12][12];
	int r,c,e;
	scanf("%d%d%d",&r,&c,&e);
	while(r!=0)
	{
		memset(m,0,sizeof(m));
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				char dir;
				scanf("%c",&dir);
				while(dir!='N'&&dir!='S'&&dir!='E'&&dir!='W')
				{
					scanf("%c",&dir);
				}
				switch(dir)
				{
				case'N':
					m[i][j]=-1;
					break;
				case'S':
					m[i][j]=-2;
					break;
				case'E':
					m[i][j]=-3;
					break;
				case'W':
					m[i][j]=-4;
					break;
				}
			}
		}
		bool succ=false;
		bool rep=false;
		int x=1;
		int y=e;
		int step=0;
		while(!succ&&!rep)
		{
			step++;
			int dir=m[x][y];
			switch(dir)
			{
			case 0:
				succ=true;
				break;
			case -1:
				m[x][y]=step;
				x--;
				break;
			case -2:
				m[x][y]=step;
				x++;
				break;
			case -3:
				m[x][y]=step;
				y++;
				break;
			case -4:
				m[x][y]=step;
				y--;
				break;
			default:
				rep=true;
				break;
			}
		}
		if(succ)
		{
			printf("%d step(s) to exit\n",step-1);
		}
		else
		{
			printf("%d step(s) before a loop of %d step(s)\n",m[x][y]-1,step-m[x][y]);
		}
		scanf("%d%d%d",&r,&c,&e);
	}
	//system("pause");
	return 0;
}