#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n,tag[100005];
ll f[100005],c[100005];
vector<int> ins[100005];
signed main(){
	freopen("rumia.in","r",stdin);
	freopen("rumia.out","w",stdout);
	cin>>n;f[n]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+i;j<=n;j+=i) ins[j].push_back(i);
	}
	for(int i=n;i>=1;i--){
		int l=i,r=i;
		ll I=1ull*i*i;
		while(r<=n){
			if(l==I) r=n;
			for(int u=l;u<=r;u++){
				int tii=u/i-(u/(i+1));
				c[i]+=1ull*tag[u]*tii;
			}
			l+=i,r+=i+1;
		}
		c[i]+=c[i+1];
		c[i]=(c[i]%mod+mod)%mod;
		f[i]+=f[i+1]+c[i];
		while(f[i]>=mod) f[i]-=mod;
		for(int u:ins[i]){
			f[u]+=f[i]*2;
			tag[u]-=f[i];
			if(tag[u]<0) tag[u]+=mod;
		}
		l=1,r=0;
		for(int j=0;j<(int)ins[i].size();j++){
			int R=ins[i][j],siz=ins[i].size()-j;
			int tii=1ull*f[i]*siz%mod;
			while(l<R){
				int val=(i-1)/l;
				r=min(R-1,(i-1)/val);
				ll C=1ull*tii*val;
				c[l-1]-=C,c[r]+=C;
				l=r+1;
			}
		}
	}
	cout<<f[1];
}
