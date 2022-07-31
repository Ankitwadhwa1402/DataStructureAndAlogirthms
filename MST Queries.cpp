#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
typedef pair<ll,ll> pr;
const int mx=2001;
ll parent[mx];
ll size[mx];
void initialise(ll n)
{
	for(ll i=1;i<=n;i++)
	{
		parent[i]=i;
		size[i]=1;
	}
}
ll find(ll a)
{
	while(parent[a]!=a)
	{
		parent[a]=parent[parent[a]];
		a=parent[a];
	}
	return a;
}

//ll find(ll a)
//{
//	if(parent[a]!=a)
//	{
//		return parent[a]=find(parent[a]);
//	}
//	return a;
//}

void root(ll x,ll y)
{
	if(find(x)!=find(y))
	{
		if(size[x]<size[y])
		{
			swap(x,y);
		}
		size[x]+=size[y];
		parent[y]=x;
		
	}
	return; 
}
int main()
{
	fast;
	ll n,m,q;
	cin>>n>>m>>q;
	initialise(n);
	vector<pair<ll,pair<ll,ll>>> tree; 
	for(ll i=0;i<m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		tree.push_back({w,{u,v}});
	}
	sort(tree.begin(),tree.end());
	set<pair<ll,pair<ll,ll>>> mst;
	for(ll i=0;i<m;i++)
	{
		ll a=tree[i].second.first;
		ll b=tree[i].second.second;
		ll w=tree[i].first;
		if(find(a)!=find(b))
		{
			root(a,b);
			mst.insert({w,{a,b}});
		}
	}
	for(ll i=0;i<q;i++)
	{
		ll t,u,v;
		cin>>t;
		if(t==3)
		{
			ll ans=0;
			initialise(n);
			for(auto s:mst)
			{
				ll w=s.first,a=s.second.first,b=s.second.second;
				if(find(a)!=find(b))
				{
					ans+=w;
					root(a,b);
				}
			}
			cout<<ans<<'\n';
			continue;
		}

			cin>>u>>v;
			if(t==1)
			{
				mst.insert({0,{u,v}});
			}
			else
			{
				mst.erase({0,{u,v}});
			}
		
	
	}
	
}
