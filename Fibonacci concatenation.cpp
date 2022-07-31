#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=100001,mod=1000000007;
vector<pair<ll,ll>> fibbo(mx,{0,0});
void series()
{
	fibbo[0]={1,0};
	fibbo[1]={1,1};
	for(ll i=2;i<mx;i++)
	{
		ll len=fibbo[i-1].first+fibbo[i-2].first;
		len=len%(mod-1);
		ll ones=fibbo[i-1].second+fibbo[i-2].second;
		ones=ones%mod;
		fibbo[i]={len,ones};
	}
}
ll binpow(ll n,ll p)
{
	ll res=1;
	while(p>0)
	{
		if(p&1)
		{
			res=res*n;
			res=res%mod;
		}
		p=p>>1;
		n=n*n;
		n=n%mod;
	}
	return res;
}
int main()
{
	series();
	ll t;
	cin>>t;
	while(t--)
{
	
	ll n;
	cin>>n;
	ll temp=binpow(2,(fibbo[n].first-1)%(mod-1));
	temp*=fibbo[n].second;
	temp=temp%mod;
	cout<<temp<<endl;
}
}
