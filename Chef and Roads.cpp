#include <bits/stdc++.h>
using namespace std;
int main()
{
	const int mod=1000000007;
	int n,m;
	cin>>n>>m;
	int p,q;
	cin>>p>>q;
	int indeg[n+1]={0};
	vector<int> adj[n+1],list;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		indeg[y]++;
	}
	queue<int> que;
	for(int i=1;i<n+1;i++)
	{
		if(indeg[i]==0)
		{	
		
			que.push(i);
		}
	}
	int dist[n+1]={0};
	dist[q]=1;
	while(!que.empty())
	{
		int f=que.front();
		que.pop();
		list.push_back(f);
		for(auto i:adj[f])
		{
			indeg[i]--;
			if(indeg[i]==0)
			{
				que.push(i);
			}
		}
	}
	
	for(int i=list.size()-1;i>=0;i--)
	{
		int node=list[i];
		for(auto j:adj[node])
		{
			dist[node]=dist[node]+dist[j];
			dist[node]=dist[node]%mod;
		}
	}
	cout<<dist[p]<<endl;
}
