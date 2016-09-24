// 1001 Exponentiation

#include<iostream>

using namespace std;

void multiply(int rlt[],int a[],int b[])
{
	int carry=0;
	int i;
	int j;
	for(i=0;b[i]>=0;i++)
	{
		for(j=0;a[j]>=0;j++)
		{
			if(rlt[i+j]<0)
			{
				rlt[i+j]=0;
			}
			rlt[i+j]+=a[j]*b[i]+carry;
			carry=rlt[i+j]/10;
			rlt[i+j]%=10;
		}
		if(carry>0)
		{
			rlt[i+j]=carry;
			carry=0;
		}
	}
}

int main()
{
	char r[8];
	int num[26][200];
	int n;
	int dp;
	while(cin>>r>>n)
	{
		if(n==0)
		{
			cout<<1<<endl;
			continue;
		}
		memset(num,-1,sizeof(num));
		dp=-1;
		bool zero=true;
		int j=0;
		int len=0;
		for(int i=5;i>=0;i--)
		{
			if(r[i]=='0'&&zero)
			{
				j++;
			}
			else if(r[i]=='.')
			{
				dp=5-i-j;
				zero=false;
			}
			else
			{
				if(dp>=0)
				{
					num[1][4-i-j]=r[i]-'0';
				}
				else
				{
					num[1][5-i-j]=r[i]-'0';
				}
				zero=false;
				len++;
			}
		}
		for(int i=len-1;i>=dp;i--)
		{
			if(num[1][i]==0)
			{
				num[1][i]=-1;
				len--;
			}
			else
			{
				break;
			}
		}
		if(num[1][0]<0)
		{
			cout<<0<<endl;
			continue;
		}
		if(dp<0)
		{
			dp=0;
		}
		for(int i=2;i<=n;i++)
		{
			multiply(num[i],num[1],num[i-1]);
		}
		dp*=n;
		int rltLen=0;
		while(rltLen<dp||num[n][rltLen]>=0)
		{
			if(num[n][rltLen]<0)
			{
				num[n][rltLen]=0;
			}
			rltLen++;
		}
		for(int i=rltLen-1;i>=0;i--)
		{
			if(i==(dp-1))
			{
				cout<<".";
			}
			cout<<num[n][i];
		}
		cout<<endl;
	}
	return 0;
}