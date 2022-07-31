#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
{
	
	ll n;
	cin>>n;
	map<ll,ll> m;
	for(ll i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		m[a]++;
	}
	
	ll sum=0;
	for(auto i:m)
	{
		sum=sum+i.second-1;
	}
	cout<<sum<<endl; 
}
}
