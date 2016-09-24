// 1068 Parencodings

#include<iostream>

using namespace std;

#include<cstdio>

int main()
{
	int cases;
	scanf("%d",&cases);
	int result[30];
	int seq[60];
	while(cases--)
	{
		int n;
		scanf("%d",&n);
		int l=n*2;
		memset(result,0,sizeof(result));
		memset(seq,0,sizeof(seq));
		for(int i=0;i<n;i++)
		{
			int k;
			scanf("%d",&k);
			seq[k+i]=1;
		}
		bool space=false;
		for(int i=0;i<l;i++)
		{
			if(seq[i]==1)
			{
				int past=1;
				for(int j=i-1;j>=0;j--)
				{
					if(seq[j]==0)
					{
						seq[j]=-1;
						if(space)
						{
							printf(" ");
						}
						space=true;
						printf("%d",past);
						break;
					}
					else
					{
						if(seq[j]==-1)
						{
							past++;
						}
					}
				}
			}
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}