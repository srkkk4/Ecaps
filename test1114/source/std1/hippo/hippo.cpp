#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5,mod=998244353;
const int inf=2e18;
int qpow(int a,int b,int p=mod){
	int ans=1,base=a;
	while(b){
		if(b&1) ans=ans*base%p;
		base=base*base%p;
		b>>=1;
	}
	return ans;
}
int n,m,k;
int b[MAXN],c[MAXN],d[MAXN];
int fac[MAXN],inv[MAXN],dp[60],pw[60];
void init(){
	fac[0]=1;
	for(int i=1;i<=m;i++) fac[i]=fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=m;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*m;
	dp[0]=1;
	for(int i=1;i<=n;i++)
		dp[i]=qpow(dp[i-1],m)*qpow(fac[m],qpow(m,i-1,mod-1))%mod;
}

int ans[MAXN];
bool vis[MAXN];
void dfs(int dep,vector<int> &pos){
	if(dep==0){
		if(pos.size()>1) ans[pos[1]]=0;
		return ;
	}
	sort(pos.begin(),pos.end(),[&](int x,int y){return b[x]<b[y];});
	int siz=pw[dep-1],pre=0;
	for(int i=1;i<=pos.size();i++){
		if(i==pos.size()||(b[pos[i]]-1)/m!=(b[pos[i-1]]-1)/m){
			int l=pre,r=i-1;
			pre=i;
			sort(pos.begin()+l,pos.begin()+r+1);
			int num=0;
			for(int j=l;j<=r;j++){
				int x=(c[pos[j]]-1)/siz+1;
				if(vis[x]) ans[pos[j]]=0;
				else{
					ans[pos[j]]=(ans[pos[j]]*inv[m-num])%mod;
					num++;
				}
				vis[x]=1;
			}
			for(int j=l;j<=r;j++){
				int x=(c[pos[j]]-1)/siz+1;
				vis[x]=0;
				b[pos[j]]=(b[pos[j]]-1)/m+1;
				d[pos[j]]=(c[pos[j]]-1)/siz+1;
			}
		}
	}
	sort(pos.begin(),pos.end(),[&](int x,int y){return d[x]<d[y];});
	pre=0;
	for(int i=1;i<=pos.size();i++){
		if(i==pos.size()||(c[pos[i]]-1)/siz!=(c[pos[i-1]]-1)/siz){
			int l=pre,r=i-1;
			pre=i;
			vector<int> tmp;
			for(int j=l;j<=r;j++){
				c[pos[j]]=(c[pos[j]]-1)%siz+1;
				tmp.push_back(pos[j]);
			}
			dfs(dep-1,tmp);
		}
	}
}
signed main(){
	
	freopen("hippo.in","r",stdin);
	freopen("hippo.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=k;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=k;i++) scanf("%lld",&c[i]);
	init();
	for(int i=0;i<=k;i++) ans[i]=1;
	ans[0]=dp[n];
	vector<int> tmp;
	for(int i=1;i<=k;i++) tmp.push_back(i);
	dfs(n,tmp);
	printf("%lld\n",ans[0]);
	for(int i=1;i<=k;i++){
		ans[i]=ans[i]*ans[i-1]%mod;
		printf("%lld\n",ans[i]);
	}
	return 0;
}
