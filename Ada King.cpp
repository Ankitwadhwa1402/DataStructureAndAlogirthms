#include <bits/stdc++.h>
using namespace std;
int k,viss[9][9];
void dfs(int x,int y,int moves,int (&vis)[9][9][9])
{

	if(x<1 || y<1 || y>8 || x>8 || vis[x][y][moves]==1)
	{
		return;
	}
    vis[x][y][moves]=1;
    viss[x][y]=1;
	if(moves>0)
	{		
	
		dfs(x,y-1,moves-1,vis);
		dfs(x,y+1,moves-1,vis);
		dfs(x+1,y,moves-1,vis);
		dfs(x+1,y-1,moves-1,vis);
		dfs(x+1,y+1,moves-1,vis);
		dfs(x-1,y,moves-1,vis);
		dfs(x-1,y+1,moves-1,vis);
		dfs(x-1,y-1,moves-1,vis);
	}
	return;
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
{
	
	int r,c;
	cin>>r>>c>>k;
	int vis[9][9][9],cnt=0;
	memset(vis,-1,sizeof vis);
	memset(viss,-1,sizeof viss);
	dfs(r,c,k,vis);
	for(int i=1;i<9;i++)
	{
		for(int j=1;j<9;j++)
		{
			if(viss[i][j]==1)
			{
				cnt++;	
			}
			
		}
	}
	cout<<cnt<<endl;
}
}
