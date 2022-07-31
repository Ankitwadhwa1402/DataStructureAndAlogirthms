#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
{
	
	ll n,k,x;
	cin>>n>>k;
	x=k;
	map<ll,ll> m;
	for(ll i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		m[a]++;
	}
	for(ll i=0;i<=(n+x);i++)
	{
		if(!m.count(i))
		{	
			if(k==0)
			{
				cout<<i<<endl;
				break;		
			}
			k--;
		}
	}
}
}
