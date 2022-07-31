#include <bits/stdc++.h>
using namespace std;
class graph{
	int V;
	list<int> *l;
	graph(int v){
		V=v;
		l=new list<int>[V];
	}
	void addedge(int i,int j,bool undir=true)
	{
		l[i].push_back(j);
		if(undir)
		{
			l[j].push_back(i);
		}
	}
	void bfs(int source)
	{
		queue<int> q;
		bool *vis=new bool[V]{0};
		q.push(source);
		vis[source]=1;
		while(q.size()!=0)
		{
			int f=q.front();
			cout<<f<<" ";  
			q.pop();
			for(auto i:l[f])
			{
				if(!vis[i])
				{
					q.push(i);
					vis[i]=true; 
				}
			
			}
		}
		
	}
	void dfshelper(int node,bool *vis)
	{
		vis[node]=true;
		cout<<node<<" ";
			for(auto i:l[node])
			{
				if(!vis[i])
				{
					dfshelper(i,vis);
				}
			}
	}
	
	void dfs(int source)
	{
		stack<int> s;
		bool *vis=new bool[V]{0};
		dfshelper(source,vis);
	}
	
	void printadjlist()
	{
		for(int i=0;i<V;i++)
		{
			cout<<i<<"--> ";
			for(auto j:l[i])
			{
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}
};

