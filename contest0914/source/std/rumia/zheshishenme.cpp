#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define mod 998244353
using namespace std;
int n;
ll f[100005],c[100005];
vector<int> ins[100005];
int tag[100005];
vector<int>vec[100005];
signed main(){
	freopen("rumia.in","r",stdin);
	freopen("rumia.out","w",stdout);
	cin>>n;
	f[n]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+i;j<=n;j+=i) ins[j].push_back(i);
	}
	int S=0; 
	for(int i=1;i<=n;i++){
		int l=1,r;
		while(l<=i){
			r=min(i,i/(i/l));
			vec[r].push_back(i);
			l=r+1;
			S++;
		}
	}
	for(int i=n;i>=1;i--){
		int L=i,R=i;
		while(R<=n){
			for(int u=L;u<=R;u++){
				int tii=u/i-(u/(i+1));
				c[i]+=1ll*tag[u]*tii%mod;
			}
			L+=i,R+=i+1;
		}
//		for(int u:vec[i]){
//			int tii=u/i-(u/(i+1));
//			c[i]+=1ll*tag[u]*tii%mod;
//		}
		c[i]+=c[i+1];
		c[i]=(c[i]%mod+mod)%mod;
		f[i]=(f[i]+f[i+1]+c[i])%mod;
		for(int u:ins[i]){
			f[u]+=f[i]*2;
			tag[u]-=f[i];
			if(tag[u]<0) tag[u]+=mod;
		}
		int l=1,r;
		for(int j=0;j<(int)ins[i].size();j++){
			int R=ins[i][j],siz=ins[i].size()-j;
			int tii=1ll*f[i]*siz%mod;
			while(l<R){
				int val=(i-1)/l;
				r=min(R-1,(i-1)/val);
				c[l-1]-=1ll*tii*val%mod;
				c[r]+=1ll*tii*val%mod;
				l=r+1;
			}
		}
	}
	cout<<f[1];
}
/*
100
100000
 */ 
