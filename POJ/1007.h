// 1007 DNA Sorting

#include<stdio.h>
//#include<iostream>

int n,m;
char dnas[110][60];
struct
{
	int Index;
	int Value;
}arr[110],temp;

int CountValue(char *str)
{
	int value=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(str[i]>str[j])
			{
				value++;
			}
		}
	}
	return value;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%s",dnas[i]);
		arr[i].Index=i;
		arr[i].Value=CountValue(dnas[i]);
	}
	for(int i=1;i<m;i++)
	{
		for(int j=i;j>0&&arr[j].Value<arr[j-1].Value;j--)
		{
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
		}
	}
	for(int i=0;i<m;i++)
	{
		printf("%s\n",dnas[arr[i].Index]);
	}
	//system("pause");
	return 0;
}