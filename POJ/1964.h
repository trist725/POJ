// 1964 City Game

#include<stdio.h>
#include<iostream>

int m,n;
int width[1010];
int height[2][1010];

int main()
{
	int k;
	scanf("%d",&k);
	for(int a=0;a<k;a++)
	{
		scanf("%d%d",&m,&n);
		int *ch,*lh;
		char c;
		int max=0;
		memset(width,0,sizeof(width));
		memset(height,0,sizeof(height));
		for(int i=0;i<m;i++)
		{
			ch=height[i%2];
			lh=height[(i+1)%2];
			for(int j=0;j<n;j++)
			{
				do
				{
					scanf("%c",&c);
				}while(c!='R'&&c!='F');
				if(c=='F')
				{
					if(j==0)
					{
						width[j]=1;
					}
					else
					{
						width[j]=width[j-1]+1;
					}
					ch[j]=lh[j]+1;
					int maxHeight=ch[j];
					int left=j;
					int s;
					for(int k=width[j];k>0;k--)
					{
						if(ch[left]<maxHeight)
						{
							maxHeight=ch[left];
						}
						s=maxHeight*(j-left+1);
						if(s>max)
						{
							max=s;
						}
						left--;
					}
				}
				else
				{
					width[j]=0;
					ch[j]=0;
				}
			}
		}
		printf("%d\n",max*3);
	}
	//system("pause");
	return 0;
}