#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	string s[n];
	for(ll i=0;i<n;i++)
	{
		cin>>s[i];
	}
	vector<string> v;
	for(ll i=0;i<n;i++)
	{
		for(ll j=1;j<=s[i].size();j++)
		{
			string temp=s[i].substr(0,j);
			v.push_back(temp);
		}
	}
	sort(v.begin(),v.end());
	for(ll i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	
}
