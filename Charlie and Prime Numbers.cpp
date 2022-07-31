#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=5000001;
vector<ll> sum(mx),sieve(mx);
void prime()
{
	sieve[0]=1;
	sieve[1]=1;
	for(ll i=2;i<mx;i++)
	{
		if(sieve[i]==0)
		{
				for(ll j=i*2;j<mx;j+=i)
				{
					sieve[j]=1;
				}
		}
	}
	for(ll i=1;i<mx;i++)
	{
		sum[i]=sum[i-1];
		if(sieve[i]==0)
		{
			
			sum[i]=sum[i]+i;
		
		}	
	
	}
}
int main()
{
	prime();
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,temp=0;
		cin>>m>>n;
		if(sieve[m]==0)
		{
			temp=m;
		}
		cout<<sum[n]-sum[m]+temp<<endl;
	}
}
