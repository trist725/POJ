// 1018 »¬Ñ©

#include<iostream>
using namespace std;

class Ski
{

public:
	Ski(int r,int c)
	{
		this->r=r;
		this->c=c;
	}

	void ReadData()
	{
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>h[i][j];
				l[i][j]=NOT_SEARCHED;
			}
		}
	}
	
	int GetMaxLength()
	{
		int max=0;
		int length;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				length=Search(i,j);
				if(length>max)
				{
					max=length;
				}
			}
		}
		return max;
	}
	

private:
	int r;
	int c;
	int h[110][110];
	int l[110][110];
	static const int NOT_SEARCHED=-1;

	int Search(int i,int j)
	{
		if(i<0||j<0||i>=r||j>=c)
		{
			return 0;
		}
		if(l[i][j]!=NOT_SEARCHED)
		{
			return l[i][j];
		}
		int maxLength=1;
		int length;
		if(h[i][j]>h[i-1][j])
		{
			length=Search(i-1,j)+1;
			if(length>maxLength)
			{
				maxLength=length;
			}
		}
		if(h[i][j]>h[i+1][j])
		{
			length=Search(i+1,j)+1;
			if(length>maxLength)
			{
				maxLength=length;
			}
		}
		if(h[i][j]>h[i][j-1])
		{
			length=Search(i,j-1)+1;
			if(length>maxLength)
			{
				maxLength=length;
			}
		}
		if(h[i][j]>h[i][j+1])
		{
			length=Search(i,j+1)+1;
			if(length>maxLength)
			{
				maxLength=length;
			}
		}
		l[i][j]=maxLength;
		return maxLength;
	}

};

int main()
{
	int r,c;
	cin>>r>>c;
	Ski ski(r,c);
	ski.ReadData();
	cout<<ski.GetMaxLength()<<endl;
	return 0;
}

//#include<stdio.h>
//
//#define NOT_SEARCHED -1
//int r;
//int c;
//int h[11000];
//int l[11000];
//int d[4];
//int total;
//int max_r;
//int max_c;
//
//int Search(int i)
//{
//	int maxLength=1;
//	int length;
//	int currHeight=h[i];
//	int ri=i/c;
//	int ci=i%c;
//	if(l[i]!=NOT_SEARCHED)
//	{
//		return l[i];
//	}
//	if(ri>0&&currHeight>h[i-c])
//	{
//		length=Search(i-c)+1;
//		if(length>maxLength)
//		{
//			maxLength=length;
//		}
//	}
//	if(ri<max_r&&currHeight>h[i+c])
//	{
//		length=Search(i+c)+1;
//		if(length>maxLength)
//		{
//			maxLength=length;
//		}
//	}
//	if(ci>0&&currHeight>h[i-1])
//	{
//		length=Search(i-1)+1;
//		if(length>maxLength)
//		{
//			maxLength=length;
//		}
//	}
//	if(ci<max_c&&currHeight>h[i+1])
//	{
//		length=Search(i+1)+1;
//		if(length>maxLength)
//		{
//			maxLength=length;
//		}
//	}
//	l[i]=maxLength;
//	return maxLength;
//}
//
//int main()
//{
//	int max=0;
//	int length;
//	int i;
//	scanf("%d%d",&r,&c);
//	d[0]=-c;
//	d[1]=1;
//	d[2]=c;
//	d[3]=-1;
//	max_r=r-1;
//	max_c=c-1;
//	total=r*c;
//	for(i=0;i<total;i++)
//	{
//		scanf("%d",&h[i]);
//		l[i]=NOT_SEARCHED;
//	}
//	for(i=0;i<total;i++)
//	{
//		length=Search(i);
//		if(length>max)
//		{
//			max=length;
//		}
//	}
//	printf("%d\n",max);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//#define NOT_SEARCHED -1
//int r;
//int c;
//int h[11000];
//int l[11000];
//int d[4];
//int total;
//int max_r;
//int max_c;
//
//int Search(int i)
//{
//	if(l[i]!=NOT_SEARCHED)
//	{
//		return l[i];
//	}
//	int maxLength=1;
//	int length;
//	int currHeight=h[i];
//	int ri=i/c;
//	int ci=i%c;
//	if(ri>0&&currHeight>h[i-c])
//	{
//		length=Search(i-c)+1;
//		if(length>maxLength)
//		{
//			maxLength=length;
//		}
//	}
//	if(ri<max_r&&currHeight>h[i+c])
//	{
//		length=Search(i+c)+1;
//		if(length>maxLength)
//		{
//			maxLength=length;
//		}
//	}
//	if(ci>0&&currHeight>h[i-1])
//	{
//		length=Search(i-1)+1;
//		if(length>maxLength)
//		{
//			maxLength=length;
//		}
//	}
//	if(ci<max_c&&currHeight>h[i+1])
//	{
//		length=Search(i+1)+1;
//		if(length>maxLength)
//		{
//			maxLength=length;
//		}
//	}
//	l[i]=maxLength;
//	return maxLength;
//}
//
//int main()
//{
//	cin>>r>>c;
//	d[0]=-c;
//	d[1]=1;
//	d[2]=c;
//	d[3]=-1;
//	max_r=r-1;
//	max_c=c-1;
//	total=r*c;
//	for(int i=0;i<total;i++)
//	{
//		cin>>h[i];
//		l[i]=NOT_SEARCHED;
//	}
//	int max=0;
//	int length;
//	for(int i=0;i<total;i++)
//	{
//		length=Search(i);
//		if(length>max)
//		{
//			max=length;
//		}
//	}
//	cout<<max<<endl;
//	//system("pause");
//	return 0;
//}