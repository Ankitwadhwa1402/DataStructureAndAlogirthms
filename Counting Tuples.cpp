#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=1000001;
vector<ll> phi(mx);
void count()
{
	phi[1]=1;
	for(ll i=2;i<mx;i++)
	{
		phi[i]=i-1;
	}
	for(ll i=2;i<mx;i++)
	{
		for(ll j=i+i;j<mx;j+=i)
		{
			phi[j]=phi[j]-phi[i];
		}
	}
}

int main()
{
	
	count();
	ll t;
	cin>>t;
	while(t--)
{
	
	ll n;
	cin>>n;
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ll temp=phi[i]*(n/i)*(n/i);
		ans+=temp;
	}
	ans=ans+ans-(n*n);
	cout<<ans<<endl;
}
}
