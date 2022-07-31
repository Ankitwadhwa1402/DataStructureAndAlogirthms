#include  <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
int main()
{
	ll n,m,r,x,y;
	cin>>n>>m>>r>>x>>y;
	x--;
	y--;
	vector<pr> adj[n];
	for(ll i=0;i<r;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}
	
	
	ll cost[n];
	for(int i=0;i<n;i++)
	{
		cost[i]=LLONG_MAX;
	}
	cost[x]=0;
	priority_queue<pr,vector<pr>,greater<pr>> pq;
	pq.push({0,x});
	ll vis[n]={0};
	while(!pq.empty())
	{
		pr f;
		f=pq.top();
		pq.pop();
		for(auto i:adj[f.second])
		{

			if(!vis[i.second] && cost[i.second]>i.first+f.first)
			{
				
				cost[i.second]=i.first+f.first;
		
				pq.push({cost[i.second],i.second});
			}
			
		}

		vis[f.second]=1;
	}
	if(m>=cost[y])
	{
		cout<<"alive "<<cost[y]<<endl;
	}
	else
	{
		cout<<"died"<<endl;
	}
	
}
