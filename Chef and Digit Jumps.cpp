#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	set<int> indices[10];
	for(int i=0;i<n;i++)
	{
		indices[s[i]-'0'].insert(i);
	}
	queue<int> q;
	q.push(0);
	
	int vis[n]={1},explored[10]={0},dis[n]={0};
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		if(explored[s[f]-'0']==0)
		{
			for(auto neighbour:indices[s[f]-'0'])
			{
				if(!vis[neighbour])
				{
					vis[neighbour]=1;
				
					dis[neighbour]=dis[f]+1;
					q.push(neighbour);
				}
			}
			explored[s[f]-'0']=1;
		}
		
		if(f>0)
		{
			int neighbour=f-1;
			if(!vis[neighbour] && !explored[s[neighbour]-'0']) 
			{
				 vis[neighbour]=1;
			
				 dis[neighbour]=dis[f]+1;
				 
				 q.push(neighbour);
			}
		}
		if(f<n-1)
		{
			int neighbour=f+1;
			if(!vis[neighbour] && !explored[s[neighbour]-'0']) 
			{
				 vis[neighbour]=1;
				
				 dis[neighbour]=dis[f]+1;
				 q.push(neighbour);
			}
		}
		
	}
	cout<<dis[n-1]<<endl;
}
