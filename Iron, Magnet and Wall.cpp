#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
{
	
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<vector<ll>> magnets,irons;	
	vector<ll> mag,ir;
	ll j=0;
	for(ll i=0;i<n;i++)
	{
	
		if(s[i]=='M')
		{
			mag.push_back(j);
		}	
		else if(s[i]=='I')
		{
			ir.push_back(j);
		}
		else if(s[i]==':')
		{
			j++;
		}
		else if(s[i]=='X')
		{
			magnets.push_back(mag);
			irons.push_back(ir);
			mag.clear();
			ir.clear();
		}
		j++;
	}
	magnets.push_back(mag);
	irons.push_back(ir);
	ll cnt=0;
	for(ll i=0;i<magnets.size();i++)
	{
		if(magnets[i].empty() || irons.empty())
		{
			continue;
		}
		ll mt=0,ir=0;
		
		while(mt<magnets[i].size() && ir<irons[i].size())
		{
			if(abs(magnets[i][mt]-irons[i][ir])<=k)
			{
				mt++;
				ir++;
				cnt++;
			}
			else 
			{
				if(irons[i][ir]<magnets[i][mt])
				{
					ir++;
				}
				else
				{
					mt++;		 
				}				
			}
		}
	}
	cout<<cnt<<endl;
}
}
