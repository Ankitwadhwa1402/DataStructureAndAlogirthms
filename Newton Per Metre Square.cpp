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
	vector<ll> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	if(n==1)
	{
		cout<<1<<endl;
		continue;
	}

	cout<<1<<endl;
	cout<<1<<" "<<1<<endl;	
	if(n==2)
	{
		continue;
	}
	cout<<1<<" "<<2<<" "<<1<<endl;
	for(ll i=3;i<n;i++)
	{
		vector<ll> temp(i+1);
		temp[0]=1;
		temp[i]=1;
	
		for(ll j=1;j<i;j++)
		{
		
			temp[j]=v[j]+v[j-1];
		
		}
		v=temp;
		for(ll j=0;j<v.size();j++)
		{
			cout<<v[j]<<" ";
		}
		cout<<endl;
	}
}
}
