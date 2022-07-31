#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pr;
int main()
{
	ll n,k,p;
	cin>>n>>k>>p;
	vector<pr> a(n+1);
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].first;	
		a[i].second=i;
	}
	sort(a.begin(),a.end());
	map<ll,ll> m;
	for(ll i=1;i<=n;i++)
	{
		m[a[i].second]=i;
	}
	vector<ll> dp(n+1);
	
	for(ll i=2;i<=n;i++)
	{
		if(a[i].first-a[i-1].first<=k)
		{
			dp[i]=dp[i-1]+1;
		}
	}
	for(ll i=0;i<p;i++)
	{
		ll a,b;
		cin>>a>>b;
		ll nx=m[a];
		ll ny=m[b];
		if(ny<nx)
		{
			swap(nx,ny);
		}
		if(ny-nx<=dp[ny])
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
}
