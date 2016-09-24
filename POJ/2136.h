// 2136 Vertical Histogram

#include<stdio.h>
#include<iostream>

int stat[30];
char str[100];

int main()
{
	memset(stat,0,sizeof(stat));
	for(int i=0;i<4;i++)
	{
		gets(str);
		for(int j=0;str[j]!='\0';j++)
		{
			if(str[j]>='A'&&str[j]<='Z')
			{
				stat[str[j]-'A']++;
			}
		}
	}
	int max=-1;
	for(int i=0;i<26;i++)
	{
		if(stat[i]>max)
		{
			max=stat[i];
		}
		//printf("%d ",stat[i]);
	}
	//printf("\n");
	for(int i=max;i>0;i--)
	{
		int spaces=0;
		bool first=true;
		for(int j=0;j<26;j++)
		{
			if(stat[j]>=i)
			{
				for(int k=0;k<spaces;k++)
				{
					printf("  ");
				}
				if(!first)
				{
					printf(" ");
				}
				printf("*");
				spaces=0;
				first=false;
			}
			else
			{
				spaces++;
			}
		}
		printf("\n");
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
	//system("pause");
	return 0;
}