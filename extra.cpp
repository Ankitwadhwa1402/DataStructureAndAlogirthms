#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pr; 
int main()
{
	ll t;
	cin>>t;
	while(t--)
{
	
	ll n;
	cin>>n;
	set<pr> s;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(ll i=0;i<n;i++)
	{
		auto ele=s.lower_bound({a[i],0});
		if(ele == s.end() || ele->first != a[i]) s.insert({a[i], 1});
		else {
			s.insert({a[i], ele->second + 1});
			s.erase(ele);
		}
	}
	ll sum=0;
	for(auto i:s){
		sum=sum+i.second-1;
	}
	cout<<sum<<endl;
}
}
