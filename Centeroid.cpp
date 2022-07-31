#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
{
	
	int n,b;
	cin>>n>>b;
	if(n==2)
	{
		if(b==1)
		{
			cout<<"YES"<<endl<<"1 2"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		continue;
	}
	if(n<(4*b))
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=(2*b);i++)
		{
			cout<<i<<" "<<i+1<<endl;
		}
		for(int i=(2*b)+2;i<=(n);i++)
		{
			cout<<(2*b)+1<<" "<<i<<endl;
		}
	}
}
}
