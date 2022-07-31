#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll ans=0;
	ll dp[n];
	dp[0]=(a[0]*1)+(a[1]*2);
	for(ll i=1;i<n;i++)
	{
		ll temp1=(a[i]*i)+(a[i-1]*(i+1));
		ll temp2=(a[i+1]*(i+1))+(a[i]*(i+2));
		if(dp[0]+temp1)
	}
}
