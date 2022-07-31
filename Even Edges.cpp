#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
{
	
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];	
	int x,y;
	for(int i=0;i<m;i++)
	{
	
		cin>>x>>y;
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}

	if(m%2==0)
	{
		cout<<1<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<1<<" ";
		}
		cout<<endl;
	}
	else
	{
		int pos=-1;
		for(int i=0;i<n;i++)
		{
			if(adj[i].size()%2!=0)
			{
			
				pos=i;
				break;
			}
		}
		if(pos!=-1)
		{
			cout<<2<<endl;
			for(int i=0;i<n;i++)
			{
				if(pos==i)
				{
					cout<<2<<" ";
					continue;
				}
				cout<<1<<" ";
			}
		}
		else
		{ 
		    cout<<3<<endl;
			
		
			for(int i=0;i<n;i++)
			{		
				if(x-1==i)
				{
					cout<<"2 ";
				}
				else if(y-1==i)
				{
					cout<<"3 ";
				}
				else
				{
					cout<<1<<" ";
				}
					
			}
				cout<<endl;
		
		}
	}
}
}
