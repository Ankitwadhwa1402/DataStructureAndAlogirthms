#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	ll t[n][n];
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cin>>t[i][j];
		}
	}
	ll m;
	cin>>m;
	ll s[m],g[m],d[m];
	for(ll i=0;i<m;i++)
	{
		cin>>s[i]>>g[i]>>d[i];
	}
	for(ll k=0;k<n;k++)
	{
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
			}
		}
	}
	
	for(ll i=0;i<m;i++)
	{
		ll temp1,temp2;
		temp1=t[s[i]][g[i]]+t[g[i]][d[i]];
		temp2=temp1-t[s[i]][d[i]];
		cout<<temp1<<" "<<temp2<<endl;
	}
}
