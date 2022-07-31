#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,mod;
	cin>>n>>mod;
	ll ans=6;
	for(ll i=4;i<=n;i++)
	{
		ans=((ans*i)%mod)-(((ans*i-1)/2)%mod);
		ans=ans%mod;
	}
	cout<<ans<<endl;
}
