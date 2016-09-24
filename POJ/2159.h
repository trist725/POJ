// 2159 Ancient Cipher

#include <iostream>

using namespace std;

#include<cstring>

bool check(int*a,int*b)
{
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(a[i]==b[j])
			{
				a[i]=-1;
				b[j]=-1;
				break;
			}
		}
		if(a[i]!=-1)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	char a[128];
	char b[128];
	cin>>a>>b;
	int len=strlen(a);
	if(len==strlen(b))
	{
		int acount[26];
		int bcount[26];
		memset(acount,0,sizeof(acount));
		memset(bcount,0,sizeof(bcount));
		for(int i=0;i<len;i++)
		{
			acount[a[i]-'A']++;
			bcount[b[i]-'A']++;
		}
		if(check(acount,bcount))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	else
	{
		cout<<"NO"<<endl;
	}
	//system("pause");
	return 0;
}