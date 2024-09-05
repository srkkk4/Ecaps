#include <bits/stdc++.h>
#define MAXN 1000003
using namespace std;
int n;
int tot=1;
struct edge{
    int to;
    long long val;
    int net;
};
edge e[MAXN<<1];
int head[MAXN];
void add(int u,int v,int w){
    e[++tot].to=v;
    e[tot].val=w;
    e[tot].net=head[u];
    head[u]=tot;

    e[++tot].to=u;
    e[tot].val=w;
    e[tot].net=head[v];
    head[v]=tot;
    return;
}
int vis[MAXN],vise[MAXN<<1];
struct cir_edge{
    int id;
    long long val;
};
vector <cir_edge> cir[MAXN]; int cntc;
int dfs(int u){
    if (vis[u]==1){
        vis[u]=2;
        cntc++;
        return 1;
    }
    vis[u]=1;
    for (int i=head[u];i;i=e[i].net){
        if (vise[i]||vise[i^1]) continue;
        vise[i]=vise[i^1]=1;
        int v=e[i].to;
        if (dfs(v)){
            cir[cntc].push_back({u,e[i].val});
            if (vis[u]!=2){
                vis[u]=2;
                return 1;
            }
            break;
        }
    }
    return 0;
}
int vist[MAXN];
void dfs2(int u){
    vist[u]=1;
    for (int i=head[u];i;i=e[i].net){
        if (vist[e[i].to]) continue;
        dfs2(e[i].to);
    }
    return;
}
int visb[MAXN]; long long d[MAXN],l[MAXN];
long long res=0;
void dfs3(int u){
    int mxs;
    for (int i=head[u];i;i=e[i].net){
        int v=e[i].to;
        if (visb[v]) continue;
        visb[v]=1;
        dfs3(v);
        if (d[v]+e[i].val>d[u]){
            d[u]=d[v]+e[i].val;
            mxs=v;
        }
    }
    for (int i=head[u];i;i=e[i].net){
        int v=e[i].to;
        if (v==mxs||vis[v]==2) continue;
        l[u]=max(l[u],d[u]+d[v]+e[i].val);
    }
    res=max(res,l[u]);
    return;
}
long long q[MAXN<<1];
struct dot{
    int id;
    long long val;
};
long long c[MAXN<<1];
dot Q[MAXN<<1]; int L,R;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        int v,w;
        scanf("%d %d",&v,&w);
        add(i,v,w);
    }
    for (int i=1;i<=n;i++){
        if (vist[i]) continue;
        dfs(i);
        dfs2(i);
    }
    for (int i=1;i<=n;i++) if (vis[i]==2) visb[i]=1;
    long long ans=0;
    for (int i=1;i<=cntc;i++){
        res=0;
        for (auto s:cir[i]){
            dfs3(s.id);
        }
        int cnt=0;
        for (auto s:cir[i]){
            cnt++;
            q[cnt]=q[cnt-1]+s.val;
            c[cnt]=d[s.id];
        }
        for (auto s:cir[i]){
            cnt++;
            q[cnt]=q[cnt-1]+s.val;
            c[cnt]=d[s.id];
        }
        for (int j=2;j<=cnt;j++){
            q[j]-=q[1];
        }
        q[1]=0;
        int len=cir[i].size();
            L=1; R=0;
            for (int j=2;j<=cnt;j++){
                while (L<=R&&c[j-1]-q[j-1]>Q[R].val){
                    R--;
                }
                Q[++R].val=c[j-1]-q[j-1];
                Q[R].id=j-1;
                while (L<=R&&Q[L].id<j-len+1){
                    L++;
                }
                res=max(res,Q[L].val+c[j]+q[j]);
            }
        ans+=res;
    }
    cout<<ans<<endl;
    return 0;
}