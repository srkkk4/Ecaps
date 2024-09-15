#include<bits/stdc++.h>
using namespace std;
int g[10000001]; 
int main()
{
	freopen("6.in","r",stdin);
	int T,n,m;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m;
		int ans=0;
		for(int j=1;j<=n;j++)g[j]=0;
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			if(g[x]==0)ans++;
			g[x]=1;
			if(x==j)cout<<i<<" "<<j<<" "<<"err"<<endl;
		}
		if(ans!=n)cout<<"err";
	}
	return 0;
} 

