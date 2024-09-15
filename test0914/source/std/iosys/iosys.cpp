#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define pb push_back
using namespace std;
int quickpow(int a,int b){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}return ret;
}
int n,m;
vector<int> e[100005];
int dep[100005],fa[100005],siz[100005],son[100005],id[100005],D,top[100005],wt[100005];
void dfs1(int now,int F){
	fa[now]=F;
	dep[now]=dep[F]+1;
	siz[now]=1;
	for(int u:e[now]){
		if(u==F) continue;
		dfs1(u,now);
		siz[now]+=siz[u];
		if(siz[u]>siz[son[now]]) son[now]=u;
	}
}
void dfs2(int now,int TOP){
	top[now]=TOP;
	id[now]=++D;wt[D]=now;
	if(son[now]) dfs2(son[now],TOP);
	for(int u:e[now]){
		if(u==son[now]||u==fa[now]) continue;
		dfs2(u,u);
	}
}
int lca(int x,int y){
	if(!x||!y) return x^y; 
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}if(dep[x]<dep[y]) return x;
	return y;
}
int val[100005],Val[100005],bitnum[1<<20];
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((l+r)>>1)
int tree[100005<<2],St[100005<<2],tag1[100005<<2],num[100005<<2],tag2[100005<<2];
void build(int now,int l,int r){
	tree[now]=1;
	if(l==r){
		St[now]=val[wt[l]];
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	St[now]=St[ls]*St[rs]%mod;
}
void pushup(int now,int l,int r){
	if(tag1[now]) tree[now]=St[now];
	else if(l==r) tree[now]=1;
	else tree[now]=tree[ls]*tree[rs]%mod;
	if(tag2[now]) num[now]=r-l+1;
	else if(l==r) num[now]=0;
	else num[now]=num[ls]+num[rs];
}
void add(int now,int l,int r,int x,int y,int k1,int k2){
	if(l>=x&&r<=y){
		tag1[now]+=k1;
		tag2[now]+=k2;
		pushup(now,l,r);
		return ;
	}
	if(mid>=x) add(ls,l,mid,x,y,k1,k2);
	if(mid<y) add(rs,mid+1,r,x,y,k1,k2);
	pushup(now,l,r);
}
#undef ls
#undef rs
#undef mid
void add(int x,int y,int k1,int k2){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		add(1,1,n,id[top[x]],id[x],k1,k2);
		x=fa[top[x]];
	}
	if(id[x]<id[y]) add(1,1,n,id[x],id[y],k1,k2);
	else add(1,1,n,id[y],id[x],k1,k2);
}
unordered_map<int,int> f[100005];
int dp(int x,int y){
	if(f[x][y]) return f[x][y];
	int ret=1;
	for(int u:e[y]){
		if(u==x) continue;
		ret=ret*(dp(y,u)+1)%mod;
	}return f[x][y]=ret;
}
int P[100005];
int x[100005],y[100005],L[100005],pre[100005];
signed main(){
	freopen("iosys.in","r",stdin);
	freopen("iosys.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tid;cin>>tid;
	cin>>n>>m;
	P[0]=1;for(int i=1;i<=n;i++) P[i]=P[i-1]*2%mod;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].pb(y);e[y].pb(x);
	}
	dfs1(1,1);
	dfs2(1,1);
	for(int i=1;i<=n;i++){
		for(int u:e[i]) dp(i,u);
	}
	int s=0;
	for(int i=1;i<=n;i++){
		int sum=1;
		for(int u:e[i]){
			if(u==fa[i]) continue;
			sum=sum*(f[i][u]+1)%mod;
		}s+=sum;
	}
	s++;
	s%=mod;
	int ans=s*P[n]%mod;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i];
		L[i]=lca(x[i],y[i]);
	}
	for(int i=1;i<=n;i++){
		val[i]=1;
		for(int u:e[i]){
			val[i]=val[i]*(f[i][u]+1)%mod;
		}
		if(i!=1){
			Val[i]=quickpow((f[i][fa[i]]+1)*(f[fa[i]][i]+1)%mod,mod-2);
		}
		else Val[i]=1;
		val[i]=val[i]*Val[i]%mod;
	}
	int now=0;
	build(1,1,n);
	for(int S=1;S<(1<<m);S++){
		bitnum[S]=bitnum[S>>1]+(S&1);
		int Lca=0;
		bool flag=0;
		for(int i=m-1;~i;i--){
			if(((S>>i)&1)!=(((now>>i)&1))){
				flag=1;
			}
			if(flag){
				if((now>>i)&1){
					add(x[i+1],y[i+1],-1,-1);
					if(pre[i+1]) add(L[i+1],pre[i+1],-1,0);
				}
				if((S>>i)&1){
					int nxt=lca(L[i+1],Lca);
					add(x[i+1],y[i+1],1,1);
					if(Lca) add(L[i+1],Lca,1,0);
					pre[i+1]=Lca;
					Lca=nxt;
				}
			}
			else{
				if(((S>>i)&1)==0) continue;
				Lca=lca(Lca,L[i+1]);
			}
		}
		if(bitnum[S]&1){
			ans-=P[n-num[1]]*tree[1]%mod*quickpow(Val[Lca],mod-2)%mod;
		}
		else{
			ans+=P[n-num[1]]*tree[1]%mod*quickpow(Val[Lca],mod-2)%mod;
		}
		now=S;
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<'\n';
}
