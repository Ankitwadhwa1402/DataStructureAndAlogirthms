#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
class ST{
	
	vector<int> seg,lazy;
	public:
	ST(int n)
	{
		seg.resize(4*n);
		lazy.resize(4*n);
	}
	public:
		void build(int ind,int low,int high,vector<int> &arr)
		{
			if(low==high)
			{
				seg[ind]=arr[low];
				return;
			}
			int mid=(low+high)>>1;
			build(2*ind+1,low,mid,arr);
			build(2*ind+2,mid+1,high,arr);
			seg[ind]=seg[2*ind+1]+seg[2*ind+2];
		}
		void update(int ind,int low,int high,int l,int r,int val)
		{
			if(lazy[ind]!=0)
			{
				seg[ind]+=(high-low+1)*lazy[ind];
				if(low!=high)
				{
					lazy[2*ind+1]+=lazy[ind];
					lazy[2*ind+2]+=lazy[ind];
				
				}	
				lazy[ind]=0;
			}
			if(low>r || high<l)
			{
				return;
			}
			if(low>=l && high<=r)
			{
				seg[ind]+=(high-low+1)*val;
				if(low!=high)
				{
					lazy[2*ind+1]+=val;
					lazy[2*ind+2]+=val;
				}
				return;
				
			}
			else
			{
				int mid=low+(high-low)/2;
				update(2*ind+1,low,mid,l,r,val);
				update(2*ind+1,mid+1,high,l,r,val);
				seg[ind]=seg[2*ind+1]+seg[2*ind+2];
				return; 
			}
		}
		int query(int ind,int low,int high,int  l,int r)
		{
			if(lazy[ind]!=0)
			{
				seg[ind]=(high-low+1)*lazy[ind];
				if(low!=high)
				{
					lazy[2*ind+1]+=lazy[ind];
					lazy[2*ind+2]+=lazy[ind];
				}
				lazy[ind]=0;
			}
			if(low>r || high<l)
			{
				return 0;
			}
			else  if(low>l && high<r)
			{
				return seg[ind];
			}
			else
			{
				int mid=low+(high-low)/2;
				query(2*ind+1,low,mid,l,r);
				query(2*ind+2,mid+1,high,l,r);
			}
		}
		
};
int main()
{
	ll n;
	cin>>n;
	vector<int> a(n);
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ST st(n);
//	st.build(0,0,n-1,a);
	ll q;
	cin>>q;
	while(q--)
	{
		cout<<"ds"<<q<<endl;
		ll type,l,r;
		cin>>type>>l>>r;
		if(type==1)
		{
			ll val;
			cin>>val;
			cout<<"yes"<<endl;
			st.update(0,0,n-1,l,r,val);
		}
		else
		{
			cout<<"no"<<endl;
			cout<<st.query(0,0,0,l,r)<<endl;
		}
	}
	
}
