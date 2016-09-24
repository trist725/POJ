// 2141 Message Decowding

#include<stdio.h>
//#include<iostream>

char letter[30];
int convert[30];
char str[100];
const char UPPER_TO_LOWER='a'-'A';

int main()
{
	gets(letter);
	gets(str);
	for(int i=0;i<26;i++)
	{
		if(letter[i]>='A'&&letter[i]<='Z')
		{
			letter[i]+=UPPER_TO_LOWER;
		}
		convert[i]=letter[i]-'a'-i;
	}
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			str[i]+=convert[str[i]-'a'];
		}
		else
		{
			if(str[i]>='A'&&str[i]<='Z')
			{
				str[i]+=convert[str[i]-'A'];
			}
		}
	}
	printf("%s\n",str);
	//system("pause");
	return 0;
}