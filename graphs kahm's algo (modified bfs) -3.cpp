#include <bits/stdc++.h>
using namespace std;	
vector<int> degr(6,0);
class graph{
	int V;
	list<int> *l;
	public:
	graph(int v){
		V=v;
		l=new list<int>[V];
	}
	void addedge(int i,int j)
	{
		l[i].push_back(j);
	
		
	}
	void topological_sort()
	{
		queue<int> q;
		bool vis[V]{0};
		for(int i=0;i<V;i++)
		{
			if(degr[i]==0)
			{
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int f=q.front();
			cout<<f<<" ";
			q.pop();
			for(auto i:l[f])
			{
				if(degr[i]>0)
				{
					degr[i]--;
				}
				if(degr[i]==0)
				{
					q.push(i);
					
				}
			}
		}
	}
};


int main()
{
	graph g(6);
	for(int i=0;i<6;i++)
	{
		int x,y;
		cin>>x>>y;
		g.addedge(x,y);
		degr[y]++;
	}
	g.topological_sort();
}
