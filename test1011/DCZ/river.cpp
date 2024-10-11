#include <bits/stdc++.h>
#define MAXN 300003
using namespace std;
int n;
struct port{
	int a;
	int id;
	bool operator<(const port &b)const{
		return a>b.a;
	}
}p[MAXN];
int b[MAXN];
vector <int> e[MAXN];
int size[MAXN],dep[MAXN],fa[MAXN],son[MAXN],top[MAXN],id[MAXN];
int bsize[MAXN];
long long tree[MAXN<<2];
void pushup(int x){
	tree[x]=tree[x<<1]+tree[x<<1|1];
}
void build(int tr,int l,int r){
	if (l==r) {tree[tr]=1ll*b[l]*bsize[l]; return;}
	int mid=(l+r)>>1;
	build(tr<<1,l,mid);
	build(tr<<1|1,mid+1,r);
	pushup(tr);
	return;
}
void modify(int tr,int l,int r,int x,int y){
	if (l==r) {tree[tr]=y; return;}
	int mid=(l+r)>>1;
	if (mid>=x) modify(tr<<1,l,mid,x,y);
	if (mid<x) modify(tr<<1|1,mid+1,r,x,y);
	pushup(tr);
	return;
}
long long query(int tr,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		return tree[tr];
	}
	int mid=(l+r)>>1; long long res=0;
	if (mid>=x) res+=query(tr<<1,l,mid,x,y);
	if (mid<y) res+=query(tr<<1|1,mid+1,r,x,y);
	return res;
}
void dfs1(int u,int f){
	size[u]=1;
	dep[u]=dep[f]+1;
	fa[u]=f;
	int mx=0;
	for (int v:e[u]){
		if (v==f) continue;
		dfs1(v,u);
		size[u]+=size[v];
		if (size[v]>mx) {mx=size[v]; son[u]=v;}
	}
	return;
}
int cnt;
int vis[MAXN];
void dfs2(int u,int t){
	vis[u]=1;
	top[u]=t;
	id[u]=++cnt;
	if (son[u]) dfs2(son[u],t);
	for (int v:e[u]){
		if (vis[v]) continue;
		dfs2(v,v);
	}
	return;
}
int to[MAXN];
void DEL(int x){
	p[to[x]].a=0;
	modify(1,1,n,id[x],0);
	return;
}
long long SUM(int x){
	return query(1,1,n,id[x],id[x]+size[x]-1);
}
void CNT(int u,int son,long long &ans,long long &lsize){
	if (u==0) return;
	ans+=SUM(u)-SUM(son)-1ll*p[to[u]].a*size[u];
	CNT(fa[u],u,ans,lsize);
	lsize+=size[u]-size[son];
	ans+=p[to[u]].a*lsize;
	return;
}
bool is_sub4=1;
int main(){
	freopen("river.in","r",stdin);
	freopen("river.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) {cin>>p[i].a; p[i].id=i; if(p[i].a!=i) is_sub4=0;}
	for (int i=1;i<=n-1;i++){
		int pos; cin>>pos;
		if (pos!=i-1) is_sub4=0;
		e[i+1].push_back(pos);
		e[pos].push_back(i+1);
	}
	if (is_sub4){
		long long ans=0;
		for (int i=n-1;i>=1;i--){
			ans+=i*(1ll*(1+(n-i))*(n-i)/2);
		}
		cout<<ans<<endl;
		return 0;
	}
	dfs1(1,0);
	dfs2(1,1);
	for (int i=1;i<=n;i++) {b[id[i]]=p[i].a; bsize[id[i]]=size[i];}
	build(1,1,n);
	long long ans=0;
	sort(p+1,p+1+n);
	for (int i=1;i<=n;i++) to[p[i].id]=i;
	for (int u=1;u<=n;u++){
		DEL(p[u].id);
		for (int v:e[p[u].id]){
			if (fa[p[u].id]==v) continue;
			ans+=SUM(v)*(n-size[v]);
		}
		long long weight_outside=0,lsize=0;
		CNT(fa[p[u].id],p[u].id,weight_outside,lsize);
		ans+=weight_outside*size[p[u].id];
	}
	cout<<ans<<endl;
	return 0;
}