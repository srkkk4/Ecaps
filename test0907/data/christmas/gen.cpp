#include<bits/stdc++.h>
using namespace std;
mt19937 myrand(time(0));
int rd(int l,int r)
{
	return l+myrand()%(r-l+1);
}
int a[1000001],b[1000001],nown;
int main()
{
	freopen("10.in","w",stdout);
	cout<<10<<endl;
	int T=10;
	while(T--)
	{
		int n=rd(198912,200000),m=rd(12345,150000);
		nown=n;
		cout<<n<<" "<<m<<endl;
		for(int i=1;i<=n;i++)a[i]=i;
		for(int i=1;i<n;i++)
		{
			int x=rd(1,nown);
			while(a[x]==i)x=rd(1,nown);
			b[i]=a[x];swap(a[x],a[nown]);
			nown--; 
		}
		if(n==a[1])
		{
			b[n]=b[n-1];
			b[n-1]=a[1];
		}
		else b[n]=a[1];
		for(int i=1;i<=n;i++)cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
} 

