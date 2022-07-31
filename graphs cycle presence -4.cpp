#include <bits/stdc++.h>
using namespace std;
class graph{
	int V;
	list<int> *l;
	public:
		graph(int v)
		{
			V=v;
			l=new list<int>[V];
		}
		
		void addedge(int x,int y)
		{
			l[x].push_back(y);
			l[y].push_back(x);
		}
		
		bool dfs(int node,vector<bool> &vis,int parent)
		{
			vis[node]=true;
			for(auto i:l[node])
			{
				
				if(!vis[i])
				{
					bool nbrcycle=dfs(i,vis,node);
					if(nbrcycle)
					{
						return true;
					}
					
					
				}
				else if(i!=parent)
				{
					return true;
				}
				
			}
			return false;
		}
		
		bool contain_cycle()
		{
			vector<bool> vis(V,false);
		
			return dfs(0,vis,-1);
		}
		
};
int main(){
	graph g(4);
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(1,3);
	g.addedge(2,3);
 	if(g.contain_cycle())
 	{
 		cout<<"YES"<<endl;
	 }
	 else
	 {
	 	cout<<"NO"<<endl;
	 }
}
