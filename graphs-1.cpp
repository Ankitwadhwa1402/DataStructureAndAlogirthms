#include <bits/stdc++.h>
using namespace std;
class graph{
	int V;
	list<int> *l;
	public:
		graph(int v){
			V=v;
			l=new list<int>[v];
		}
		void addedge(int i,int j,bool undir=true)
		{
			l[i].push_back(j);
			if(undir)
			{
				l[j].push_back(i);
			}
		}
		void printadjlist()
		{
			for(int i=0;i<V;i++)
			{
				cout<<i<<"---> ";
				for(auto j:l[i])
				{
					 	cout<<j<<" ";
				}
				cout<<endl;
			}
		}
};
int main()
{
	cout<<"hello"<<endl;
	graph g(6);
	g.addedge(1,2);
	g.addedge(3,2);
	g.addedge(4,1);
	g.printadjlist();
	cout<<"hello"<<endl;
}
