#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1000000007;
long long binpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1)
		{
			res=res*a;
			res=res%mod;
		}
		a=a*a;
		a=a%mod;
		b=b>>1;
	}
	return res;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
{
	
	ll n,w;
	cin>>n>>w;
	ll ans=0;
	for(ll i=0;i<10;i++)
	{
		for(ll j=1;j<10;j++)
		{
			if(i-j==w)
			{
			
				ans++;
			}
		}
	}

	ans=ans*binpow(10,n-2);
	ans=ans%mod;
	cout<<ans<<endl;
}
	
}
