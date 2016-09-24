// 1018 Communication System

#include<iostream>
#include<iomanip>
using namespace std;

#include<set>

#define MAX_INT 0xfffffff

struct Device
{
	int Price;
	int Band;
};

double Work(int count,int dNum[100],Device d[100][100])
{
	int maxBand[100];
	for(int i=0;i<count;i++)
	{
		maxBand[i]=d[i][0].Band;
		for(int j=1;j<dNum[i];j++)
		{
			if(d[i][j].Band>maxBand[i])
			{
				maxBand[i]=d[i][j].Band;
			}
		}
	}
	int band;
	band=maxBand[0];
	for(int i=1;i<count;i++)
	{
		if(maxBand[i]<band)
		{
			band=maxBand[i];
		}
	}
	set<int> bands;
	for(int i=0;i<count;i++)
	{
		for(int j=0;j<dNum[i];j++)
		{
			if(d[i][j].Band<=band)
			{
				bands.insert(d[i][j].Band);
			}
		}
	}
	double minValue=0;
	int currBand;
	int price;
	int minPrice;
	set<int>::iterator itr;
	for(itr=bands.begin();itr!=bands.end();itr++)
	{
		currBand=*itr;
		price=0;
		for(int i=0;i<count;i++)
		{
			minPrice=MAX_INT;
			for(int j=0;j<dNum[i];j++)
			{
				if(d[i][j].Band>=currBand&&d[i][j].Price<=minPrice)
				{
					minPrice=d[i][j].Price;
				}
			}
			price+=minPrice;
		}
		if((double)currBand/(double)price>minValue)
		{
			minValue=(double)currBand/(double)price;
		}
	}
	return minValue;
}

int main()
{
	int total;
	int count;
	int dNum[100];
	Device d[100][100];
	cin>>total;
	for(int i=0;i<total;i++)
	{
		cin>>count;
		for(int j=0;j<count;j++)
		{
			cin>>dNum[j];
			for(int k=0;k<dNum[j];k++)
			{
				cin>>d[j][k].Band>>d[j][k].Price;
			}
		}
		cout<<setprecision(3)<<setiosflags(ios::fixed)<<Work(count,dNum,d)<<endl;
	}
	return 0;
}