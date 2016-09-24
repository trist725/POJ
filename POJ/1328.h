// 1328 Radar Installation

#include<iostream>

using namespace std;

#include<cmath>
#include<vector>
#include<algorithm>

struct Line
{
	double start;
	double end;
};

inline bool compare(const Line&left,const Line&right)
{
	return left.start<right.start;
}

int main()
{
	int cases=0;
	int n,d;
	cin>>n>>d;
	while(!(n==0&&d==0))
	{
		vector<Line> lines;
		cases++;
		bool fail=false;
		for(int i=0;i<n;i++)
		{
			double x,y;
			cin>>x>>y;
			if(y>d)
			{
				fail=true;
			}
			if(!fail)
			{
				double dx=sqrt(d*d-y*y);
				Line line;
				line.start=x-dx;
				line.end=x+dx;
				lines.push_back(line);
			}
		}
		if(!fail)
		{
			sort(lines.begin(),lines.end(),compare);
			vector<Line>::iterator itr;
			int num=0;
			double right=-10000.0;
			for(itr=lines.begin();itr!=lines.end();itr++)
			{
				if(itr->start>right)
				{
					num++;
					right=itr->end;
				}
				else
				{
					if(itr->end<right)
					{
						right=itr->end;
					}
				}
			}
			cout<<"Case "<<cases<<": "<<num<<endl;
		}
		else
		{
			cout<<"Case "<<cases<<": "<<-1<<endl;
		}
		cin>>n>>d;
	}
	//system("pause");
	return 0;
}