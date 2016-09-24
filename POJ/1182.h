// 1028  ≥ŒÔ¡¥

#include <iostream>
using namespace std;

#include<stdio.h>

struct Node
{
	int relate;
	int parent;
	int deep;
};

class Zoo
{

public:

	Zoo(int count)
	{
		n=count;
		//forest=new Node(n);
		for(int i=1;i<=n;i++)
		{
			forest[i].parent=UNKNOW;
			forest[i].relate=UNKNOW;
			forest[i].deep=0;
		}
	}
	
	~Zoo()
	{
		//delete forest;
	}

	bool AddEqual(int a,int b)
	{
		if(a>n||b>n||a<=0||b<=0)
		{
			return false;
		}
		if(a==b)
		{
			return true;
		}
		Node ap,bp;
		ap=findParent(a);
		bp=findParent(b);
		if(ap.parent==bp.parent)
		{
			return ap.relate==bp.relate;
		}
		else
		{
			Merge(ap,bp,EQUAL);
			return true;
		}
	}

	bool AddEat(int a,int b)
	{
		if(a==b||a>n||b>n||a<=0||b<=0)
		{
			return false;
		}
		Node ap,bp;
		ap=findParent(a);
		bp=findParent(b);
		if(ap.parent==bp.parent)
		{
			int r=bp.relate-ap.relate;
			return r==2||r==-1;
		}
		else
		{
			Merge(ap,bp,EAT);
			return true;
		}
	}

private:

	Node findParent(int i)
	{
		Node p;
		p.parent=i;
		p.relate=EQUAL;
		while(forest[p.parent].parent!=UNKNOW)
		{
			if(forest[p.parent].relate!=UNKNOW)
			{
				p.relate+=forest[p.parent].relate;
			}
			p.parent=forest[p.parent].parent;
		}
		p.relate=p.relate%3;
		return p;
	}

	void Merge(Node a,Node b,int r)
	{
		if(forest[a.parent].deep<forest[b.parent].deep)
		{
			forest[a.parent].parent=b.parent;
			int rp=(r+b.relate-a.relate)%3;
			if(rp<0)
			{
				rp+=3;
			}
			forest[a.parent].relate=rp;
			forest[b.parent].deep++;
		}
		else
		{
			forest[b.parent].parent=a.parent;
			int rp=(a.relate-r-b.relate)%3;
			if(rp<0)
			{
				rp+=3;
			}
			forest[b.parent].relate=rp;
			forest[a.parent].deep++;
		}
	}

	int n;
	Node forest[50010];
	const static int UNKNOW=-1;
	const static int EQUAL=0;
	const static int EAT=1;
	const static int BEATE=2;

};

int main()
{
	int n;
	//cin>>n;
	scanf("%d",&n);
	Zoo zoo(n);
	int k;
	//cin>>k;
	scanf("%d",&k);
	int lies=0;
	int op,a,b;
	for(int i=0;i<k;i++)
	{
		//cin>>op>>a>>b;
		scanf("%d%d%d",&op,&a,&b);
		if(op==1)
		{
			if(!zoo.AddEqual(a,b))
			{
				lies++;
			}
		}
		else
		{
			if(!zoo.AddEat(a,b))
			{
				lies++;
			}
		}
	}
	//cout<<lies<<endl;
	printf("%d\n",lies);
	//system("pause");
	return 0;
}