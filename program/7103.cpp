#include <bits/stdc++.h>
#define MAXN 5000003
using namespace std;
int n,m;
int head[MAXN]; int tot;
/*-----------------FIO------------------*/
inline int read()
{
	char ch = getchar();
	int res = 0;
	while (!isdigit(ch))
	{
		ch = getchar();
	}
	while (isdigit(ch))
	{
		res = res * 10 + ch - '0';
		ch = getchar();
	}
	return res;
}

void write(int x)
{
	if (x < 10)
	{
		putchar(x + '0');
		return;
	}
	write(x / 10);
	putchar((x % 10) + '0');
}
/*--------------------------------------*/
struct edge{
    int to;
    // int val;
    int net;
};
edge e[MAXN];
inline void add(int u,int v){
    e[++tot].to=v;
    e[tot].net=head[u];
    head[u]=tot;
    return;
}
int len[MAXN],dep[MAXN];
inline int dfs(int u){
    if (!head[u]){
        dep[u]=len[u];
        return len[u];
    }
    int mxdep=0;
    for (int i=head[u];i;i=e[i].net){
        int v=e[i].to;
        len[v]=len[u]+1;
        mxdep=max(mxdep,dfs(v));
    }
    dep[u]=mxdep;
    return mxdep;
}
int ans[MAXN]; int cnt=1;
inline void dfs2(int u){
    if (!head[u]) return;
    int mxdep=0,w,mxdep2=0;
    for (int i=head[u];i;i=e[i].net){
        int v=e[i].to;
        if (dep[v]>mxdep){
            mxdep=dep[v];
            w=i;
        }
    }
    for (int i=head[u];i;i=e[i].net){
        if (i==w) continue;
        int v=e[i].to;
        mxdep2=max(mxdep2,dep[v]);
    }
    for (;cnt<=mxdep2;cnt++){
        ans[cnt]=u;
    }
    for (int i=head[u];i;i=e[i].net){
        int v=e[i].to;
        dfs2(v);
    }
    return;
}
struct node{
    int val;
    int u;
};
node cnt1[MAXN];
int main(){
    cin>>n>>m;
    for (int v=1;v<=n;v++){
        int u;
        u=read();
        add(u,v);
    }
    dfs(0);
    dfs2(1);
    for (int i=1;i<=n;i++){
        cnt1[len[i]].val++;
        cnt1[len[i]].u=i;
    }
    for (int i=1;i<=n;i++){
        if (cnt1[i].val==1){
            ans[i]=cnt1[i].u;
        }
    }
    for (int i=1;i<=m;i++){
        int k;
        k=read();
        write(ans[k]);putchar('\n');
    }
    return 0;
}