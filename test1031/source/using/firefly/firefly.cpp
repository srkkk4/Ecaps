#include<bits/stdc++.h>
using namespace std;
int read(){
	int x,c;
	while((c=getchar())<'0'||c>'9');
	x=c^48;
	while((c=getchar())>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48);
	return x;
}
typedef long long ll;
const int maxn=1000020;
int n;
struct BIT{
	int c[maxn];
	void change(int x,int y){
		x++;
		while(x<=n+1){
			c[x]+=y;
			x+=x&-x;
		}
	}
	int query(int x){
		x++;
		int ans=0;
		while(x){
			ans+=c[x];
			x-=x&-x;
		}
		return ans;
	}
}T;
const int node=maxn<<2;
int fix[node],sex[node],cnt[node];
#define ls p<<1
#define rs (p<<1)|1
#define mid ((l+r)>>1)
void init(int p,int l,int r){
	fix[p]=0;sex[p]=1000000000;cnt[p]=r-l+1;
	if(l==r)return;
	init(ls,l,mid);init(rs,mid+1,r);
}
void update(int p){
	if(fix[ls]==fix[rs]){
		fix[p]=fix[ls];cnt[p]=cnt[ls]+cnt[rs];
		sex[p]=min(sex[ls],sex[rs]);
	}
	else if(fix[ls]<fix[rs]){
		fix[p]=fix[ls];cnt[p]=cnt[ls];
		sex[p]=min(sex[ls],fix[rs]);
	}
	else{
		fix[p]=fix[rs];cnt[p]=cnt[rs];
		sex[p]=min(fix[ls],sex[rs]);
	}
}
void make(int p,int l,int r,int x){
	if(x<=fix[p])return;
	if(x<sex[p]){fix[p]=x;return;}
	make(ls,l,mid,x);make(rs,mid+1,r,x);
	update(p);
}
void down(int p,int l,int r){
	if(l!=r){
		make(ls,l,mid,fix[p]);
		make(rs,mid+1,r,fix[p]);
	}
}
int cv[maxn],ud[maxn],cr[maxn],ci;
void c_check(int x){if(ud[x]==0){ud[x]=1;cr[++ci]=x;cv[x]=0;}}
void change(int p,int l,int r,int L,int R,int x){
	down(p,l,r);
	if(L<=l&&r<=R){
		if(x<=fix[p])return;
		if(x<sex[p]){
			c_check(fix[p]);
			c_check(x);
			cv[fix[p]]-=cnt[p];
			cv[x]+=cnt[p];
			fix[p]=x;
			return;
		}
	}
	if(L<=mid)change(ls,l,mid,L,R,x);
	if(mid<R)change(rs,mid+1,r,L,R,x);
	update(p);
}
vector<int> ch[maxn];
vector<pair<int,int>> qr[maxn];int ans[maxn];
int main(){
	freopen("firefly.in","r",stdin);
	freopen("firefly.out","w",stdout);
	read();n=read();
	int m=read(),q=read(),x,y;
	for(int i=1;i<=m;i++){
		x=read();y=read();
		ch[y].push_back(x);
	}
	for(int i=1;i<=q;i++){
		x=read();y=read();
		qr[y].emplace_back(x,i);
	}
	for(int i=1;i<=n;i++)
		ud[i]=T.c[i]=0;
	init(1,1,n);T.change(0,n);
	for(int i=1;i<=n;i++){
		for(auto j:ch[i]){
			ci=0;change(1,1,n,j,i,j);
			for(int k=1;k<=ci;k++){
				T.change(cr[k],cv[cr[k]]);
				ud[cr[k]]=0;
			}
		}
		for(auto j:qr[i])
			ans[j.second]=n-T.query(j.first-1);
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
