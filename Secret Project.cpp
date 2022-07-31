#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
{
	
	ll n,mod;
	cin>>n>>mod;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll sum=a[0]%mod;
	for(ll i=1;i<n;i++)
	{
		a[i]=a[i]%mod;
		sum=((sum+a[i])%mod)+((sum*a[i])%mod);
		sum=sum%mod;
	}
	cout<<sum<<endl;
}
}
