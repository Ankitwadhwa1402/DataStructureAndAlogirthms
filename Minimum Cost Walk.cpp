#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pr;
ll n;
void dijkstra(ll source,vector<pr> *adj,vector<ll> &cost)
{
	vector<ll> vis(n+1);
	
	priority_queue<pr,vector<pr>,greater<pr>> pq;
	
	pq.push({0,source});
	cost[source]=0;
	while(!pq.empty())
	{
		pr f;
		f=pq.top();
		pq.pop();
		ll c=f.first,node=f.second;
		for(auto i:adj[node])
		{
			if(!vis[i.second] && cost[i.second]>i.first+c)
			{
				cost[i.second]=i.first+c;
				pq.push({cost[i.second],i.second});
			}
		}
		vis[node]=1;
	}
	return;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
{
	
	ll m;
	cin>>n>>m;
	ll s,t,v;
	cin>>s>>t>>v;
	s--;t--;v--;
	vector<pr> adj[n+1];
	for(ll i=0;i<m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}
	vector<ll> diss(n,LLONG_MAX),disv(n+1,LLONG_MAX),dist(n+1,LLONG_MAX);
	dijkstra(s,adj,diss);
	dijkstra(t,adj,dist);
	dijkstra(v,adj,disv);
	ll ans=LLONG_MAX;
	for(ll i=0;i<n;i++)
	{
	
		ans=min(ans,diss[i]+disv[i]+dist[i]);
	}
	cout<<ans<<endl;
}
	
}
