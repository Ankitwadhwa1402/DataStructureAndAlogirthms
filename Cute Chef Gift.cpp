#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=100001;
vector<vector<ll>> factors(mx);
void sieve()
{
	vector<ll> sieve(mx);
	sieve[0]=1;
	sieve[1]=1;
	for(ll i=0;i<mx;i++)
	{
		if(sieve[i]==0)
		{
			factors[i].push_back(i);
			for(ll j=i+i;j<mx;j+=i)
			{
				sieve[j]=1;
				factors[j].push_back(i);
			}
		}
	}	
}
int main()
{
	
	sieve();
	ll t;
	cin>>t;
	while(t--)
{
	
	ll n;
	cin>>n;
	vector<ll> a(n);
	map<ll,ll> first,last;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		for(auto fac:factors[a[i]])
		{
		
			if(first[fac]==0)
			{	
				first[fac]=i+1;
			}
			last[fac]=i+1;
		}
	
		
	}
	vector<ll> diff(n+1);
	for(auto i:first)
	{
		diff[i.second]++;
	}
	for(auto i:last)
	{
		diff[i.second]--;
	}

	ll ans=0;
	
	for(ll i=1;i<=n;i++)
	{
		diff[i]+=diff[i-1];
		if(diff[i]==0)
		{
			
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
}
}
