#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
{
	
	string s;
	cin>>s;
	ll snk=0,mong=0;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]=='s')
		{
			snk++;
		}
		else
		{
			mong++;
		}
	}
	vector<ll> vis(s.size());
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]=='s')
		{
			if(i>0 && s[i-1]=='m' && vis[i-1]!=1)
			{
				vis[i-1]=1;
				snk--;
			}
			else if(i<s.size() && s[i+1]=='m' && vis[i+1]!=1)
			{
				vis[i+1]=1;
				snk--;
			}
			
				
		}
	}
	if(snk>mong)
	{
		cout<<"snakes"<<endl;
	}
	else if(snk==mong)
	{
		cout<<"tie"<<endl;
	}
	else
	{
		cout<<"mongooses"<<endl;
	}
}
}

