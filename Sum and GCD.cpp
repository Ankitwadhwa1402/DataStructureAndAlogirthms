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
	vector<ll> a;
	set<ll> b;
	for(ll i=0;i<n;i++)
	{
		ll temp;
		cin>>temp;
		b.insert(temp);
	}
	if(b.size()==1)
	{
		cout<<(*b.begin())*2<<endl;
		continue;
	}
	for(auto i:b)
	{
		a.push_back(i);
	}
	n=a.size();
	sort(a.begin(),a.end());
	vector<ll> pregcd(n),sufgcd(n);
	pregcd[0]=a[0];
	sufgcd[n-1]=a[n-1];
	for(ll i=1;i<n;i++)
	{
		pregcd[i]=__gcd(pregcd[i-1],a[i]);
	}
	for(ll i=n-2;i>=0;i--)
	{
		sufgcd[i]=__gcd(sufgcd[i+1],a[i]);
	}
	ll ans1,ans2=sufgcd[1],ans;
	ans=ans2+a[0];
	for(ll i=1;i<n-1;i++)
	{
		ans1=pregcd[i-1];
		ans2=sufgcd[i+1];
		ans=max(ans,__gcd(ans1,ans2)+a[i]);
	}
	ans=max(ans,pregcd[n-2]+a[n-1]);
	cout<<ans<<endl;
}
}
