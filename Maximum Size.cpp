#include <bits/stdc++.h>
using namespace std;	
int n,m;
bool isValid(int x,int y)
{
	return (x>=0 && y>=0 && x<n && y<m);
}
void dfs(int x,int y,int &dis,vector<vector<int>> &vis,vector<vector<char>> &a)
{

	dis++;
	vis[x][y]=1;
	int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
	for(int i=0;i<4;i++)
	{
		int newx=x+dx[i];
		int newy=y+dy[i];
		if(isValid(newx,newy) && !vis[newx][newy] && a[newx][newy]=='1')
		{
			dfs(newx,newy,dis,vis,a);
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
{
	
	cin>>n>>m;
	vector<vector<char>> a(n,vector<char>(m,'0'));
	vector<vector<int>> vis(n,vector<int>(m,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j] && a[i][j]=='1')
			{
				int dis=0;
				dfs(i,j,dis,vis,a);
				ans.push_back(dis);
			}
			
		}
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	int sum=0;	
	for(int i=1;i<ans.size();i+=2)
	{
		sum=sum+ans[i];
	}
	cout<<sum<<endl;
}
}
