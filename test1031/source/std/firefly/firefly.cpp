#include<bits/stdc++.h>

#define vc vector
#define db double
#define fi first
#define se second
#define ll long long
#define mk make_pair
#define pb push_back
#define RI register int
#define PI pair<int,int>
#define ull unsigned long long
#define err cerr << "   -_-   " << endl
#define debug cerr << " ------------------- " << endl

#define input(x) freopen(#x".in","r",stdin)
#define output(x) freopen(#x".out","w",stdout)

#define NO puts("No")
#define YES puts("Yes")

//#define OccDreamer
//#define int long long

using namespace std;

namespace IO{
	inline int read(){
		int X=0, W=0; char ch=getchar();
		while(!isdigit(ch)) W|=ch=='-', ch=getchar();
		while(isdigit(ch)) X=(X<<1)+(X<<3)+(ch^48), ch=getchar();
		return W?-X:X;
	}
	inline void write(int x){
		if(x<0) x=-x, putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	inline void sprint(int x){write(x), putchar(32);}
	inline void eprint(int x){write(x), putchar(10);}
}using namespace IO;

const int MAXN = 1e6+5;
const int mod = 998244353;

int dep[MAXN<<2], seg[MAXN], topf, cnt;
int c, n, m, q, sum[MAXN<<2], le[MAXN<<2], ri[MAXN<<2];
int ans[MAXN], f[30][MAXN], lmin[MAXN<<2], rmax[MAXN<<2];

bool mark[MAXN];

struct segment{
	int l, r;
	inline bool friend operator < (const segment &x, const segment &y){
		return x.l>y.l;
	}
}s[MAXN], stk[MAXN];

struct ask{
	int l, r, id;
	inline bool friend operator < (const ask &x, const ask &y){
		return x.l>y.l;
	}
}Q[MAXN];

inline void pushup(int p){
	int d=dep[p], las=0;
	int mid=(le[p]+ri[p])>>1;
	for(int i=le[p];i<=mid;++i){
		if(f[d+1][i]==las+1 && i<lmin[p]) sum[p]++;
		f[d][i]=sum[p]; las=f[d+1][i];
	}
	las=0;
	for(int i=mid+1;i<=ri[p];++i){
		if(f[d+1][i]==las+1 && i>rmax[p]) sum[p]++;
		f[d][i]=sum[p]; las=f[d+1][i];
	}
	return ; 
}

inline void insert(int p, int l, int r, int L, int R){
	if(L==R || l==r) return ;
	int mid=(l+r)>>1;
	if(L<=mid && R>mid) return lmin[p]=min(lmin[p],L), rmax[p]=max(rmax[p],R), void();
	if(L<=mid) insert(p<<1,l,mid,L,R);
	else insert(p<<1|1,mid+1,r,L,R);
	return ;
}

inline void build(int p, int l, int r, int d){
	dep[p]=d; le[p]=l, ri[p]=r;
	if(l==r){
		sum[p]=!mark[l];
		if(!mark[l]) f[d][l]=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid,d+1); build(p<<1|1,mid+1,r,d+1);
	return pushup(p);
}

inline void upd(int p, int l, int r, int pos, int minL){
	if(minL<l) lmin[p]=min(lmin[p],minL), rmax[p]=max(rmax[p],pos);
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(pos<=mid) upd(p<<1,l,mid,pos,minL);
	else upd(p<<1|1,mid+1,r,pos,minL);
	return ;
}

inline void ask(int p, int l, int r, int L, int R){
	if(L<=l && r<=R) return seg[++cnt]=p, void();
	int mid=(l+r)>>1;
	if(L<=mid) ask(p<<1,l,mid,L,R);
	if(R>mid) ask(p<<1|1,mid+1,r,L,R);
	return ;
}

inline bool crs(int a, int b, int c, int d){
	if(a>b) return 0;
	return a<=d;
}

inline void solve(int L, int R, int id){
	ans[id]=R-L+1; cnt=0;
	//if(id==242) cout << "range:" << L << ' ' << R << endl;
	ask(1,1,m,L,R); topf=0; int nowl, nowr;
	for(int i=1;i<=cnt;++i){
		nowl=lmin[seg[i]], nowr=rmax[seg[i]]; 
		//if(id==242) cout << le[seg[i]] << ' ' << ri[seg[i]] << ' ' << nowl << ' ' << nowr << endl;
		if(nowl>nowr) continue;
		while(topf && crs(nowl,nowr,stk[topf].l,stk[topf].r)){
			nowl=min(stk[topf].l,nowl);
			--topf;
		} 
		if(nowl<=nowr) stk[++topf]=segment{nowl,nowr};
	}
	int lr, rr;
	int now=1, node, d;
	//if(id==242){
	//	for(int i=1;i<=topf;++i) cout << stk[i].l << ' ' << stk[i].r << endl;
	//}
	for(int i=1;i<=cnt;++i){
		node=seg[i]; rr=ri[node]; lr=le[node];
		while(now<=topf && stk[now].r<lr) ++now;
		if(now<=topf && stk[now].l<le[node]) lr=max(stk[now].r+1,lr); 
		if(now<=topf && stk[now].r>ri[node]) rr=min(rr,stk[now].l-1);
		if(now+1<=topf && stk[now+1].r>ri[node]) rr=min(rr,stk[now+1].l-1);
		//if(id==242) cerr << "contri:" << le[node] << ' ' << ri[node] << ' ' << lr << ' ' << rr << endl;
		if(lr>rr) continue;
		if(lr==le[node]) d=0;
		else d=f[dep[node]][lr-1];  
		ans[id]-=f[dep[node]][rr]-d;
	}
	return ;
}

signed main(){
	freopen("firefly.in","r",stdin);
	freopen("firefly.out","w",stdout);
	c=read(); m=read(), n=read(), q=read();
	memset(lmin,127/3,sizeof lmin);
	for(int i=1;i<=n;++i) s[i].l=read(), s[i].r=read(), mark[s[i].l]|=s[i].l==s[i].r;
	for(int i=1;i<=q;++i) Q[i].l=read(), Q[i].r=read(), Q[i].id=i;
	sort(s+1,s+1+n); sort(Q+1,Q+1+q); int now=1, cur=1;
	for(int i=1;i<=n;++i) insert(1,1,m,s[i].l,s[i].r); build(1,1,m,1);
	memset(lmin,127/3,sizeof lmin); memset(rmax,0,sizeof rmax);
	for(int i=m;i>=1;--i){
		while(cur<=n && s[cur].l==i){
			upd(1,1,m,s[cur].r,s[cur].l);
			++cur;
		}
		while(now<=q && Q[now].l==i){
			solve(Q[now].l,Q[now].r,Q[now].id);
			++now;
		}
	}
	//eprint(ans[q]);
	for(int i=1;i<=q;++i) eprint(ans[i]);
	return 0;
}
