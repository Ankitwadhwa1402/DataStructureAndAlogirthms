#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1000000007;
bool loop(vector<vector<ll>> v,ll row,vector<ll> &vis,ll &cnt)
{
	if(row>=v.size())
	{
		cnt=cnt+1;
		cnt=cnt%mod;
		return true;
	}
	for(ll i=0;i<chk.size();i++)
	{
		if(chk)
	
	}
	return false;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
{
	
	ll n;
	cin>>n;
	vector<vector<ll>> v(n),vis(n,vector<ll>(101));
	string g;
	getline(cin,g);
	for(ll i=0;i<n;i++)
	{
		string temp,s="";
		getline(cin,temp);
		istringstream ss(temp);
		string word;
		while(ss>>word){
			vis[i][stoi(word)]=1;
			v[i].push_back(stoi(word));
		}
	
	}
	ll cnt=cnt;
	vector<ll> chk;
	loop(v,1,vis,cnt,chk);
	cout<<cnt<<'\n' ;
	
}
}
