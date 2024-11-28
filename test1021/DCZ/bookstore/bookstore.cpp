#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int T;
int n,m;
struct set{
    int x;
    int y;
    int is_del;
    int is_tr;
}a[MAXN];
struct edge{
    int v;
    int id;
};
vector <edge> e[MAXN];
int du[MAXN];
int vis[MAXN];
void clean(int u){
    du[u]--;
    vis[u]=1;
    for (edge ed:e[u]){
        a[ed.id].is_del=1;
        du[ed.v]--;
    }
    for (edge ed:e[u]){
        if (du[ed.v]==1) clean(ed.v);
    }
    return;
}
int root;
int dep[MAXN]; int fa[MAXN][20]; int faid[MAXN];
void dfs(int u,int f){
    vis[u]=1;
    dep[u]=dep[f]+1;
    fa[u][0]=f;
    for (int i=1;(1<<i)<=dep[u];i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for (edge ed:e[u]){
        if (vis[ed.v]) continue;
        faid[ed.v]=ed.id;
        a[ed.id].is_tr=1;
        dfs(ed.v,u);
    }
    return;
}
int LCA(int u,int v){
    if (dep[u]<dep[v]) swap(u,v);
    int cha=dep[u]-dep[v];
    for (int i=0;(1<<i)<=cha;i++){
        if (cha&(1<<i)) u=fa[u][i];
    }
    if (u==v) return v;
    for (int i=log(dep[u])/log(2)+0.5;i>=0;i--){
        if (fa[u][i]==fa[v][i]) continue;
        u=fa[u][i]; v=fa[u][i];
    }
    return fa[u][0];
}
int ji[MAXN],cnt_ji;
int COL[MAXN],cnt1;
int ans1[MAXN],ans2[MAXN];
int main(){
    freopen("bookstore_big2.in","r",stdin);
    freopen("bookstore.out","w",stdout);
    cin>>T;
    int cnt5=0;
    while (T--){cnt5++;
        cin>>n>>m;
        for (int i=1;i<=n;i++) {e[i].clear(); du[i]=0; vis[i]=0;}
        for (int i=1;i<=n;i++) for (int j=1;j<=20;j++) fa[i][j]=0;
        for (int i=1;i<=m;i++) {cin>>a[i].x>>a[i].y; a[i].is_del=a[i].is_tr=0;}
        for (int i=1;i<=m;i++){
            e[a[i].x].push_back({a[i].y,i});
            e[a[i].y].push_back({a[i].x,i});
            du[a[i].x]++; du[a[i].y]++;
        }
        for (int i=1;i<=n;i++){
            if (du[i]==1) clean(i);
        }
        for (int i=1;i<=n;i++){
            if (vis[i]) continue;
            root=i;
            dfs(root,0);
        }
        cnt_ji=0; int is_ou=0;
        for (int i=1;i<=m;i++){
            if (a[i].is_tr||a[i].is_del) continue;
            if (dep[a[i].x]<dep[a[i].y]) swap(a[i].x,a[i].y);
            if (dep[a[i].x]-dep[a[i].y]&1){
                int lca=LCA(a[i].x,a[i].y);
                int col=(dep[a[i].x]+dep[a[i].y]-2*dep[lca]+1)/2;
                cout<<col<<" "<<col<<endl;
                int u=a[i].x,v=a[i].y;
                cout<<i<<" ";
                u=fa[u][0]; while (dep[u]>dep[lca]) {cout<<faid[u]<<" "; u=fa[u][1];}
                v=fa[v][0]; while (dep[v]>dep[lca]) {cout<<faid[v]<<" "; v=fa[v][1];}
                cout<<endl;
                u=a[i].x,v=a[i].y;
                while (dep[u]>dep[lca]) {cout<<faid[u]<<" "; u=fa[u][1];}
                while (dep[v]>dep[lca]) {cout<<faid[v]<<" "; v=fa[v][1];}
                cout<<endl;
                is_ou=1;
                break;
            } else {
                ji[++cnt_ji]=i;
            }
        }
        if (is_ou) continue;
        if (cnt_ji>=2){
            int x=ji[1],y=ji[2];
            if (dep[a[x].y]<dep[a[y].y]) swap(x,y);
            int lcax=LCA(a[x].x,a[y].x);
            cnt1=0;
            if (dep[a[x].y]>=dep[lcax]){
                // cerr<<cnt5<<" 1"<<endl;
                int etr1=a[x].y,etr2; if (dep[a[y].y]<dep[lcax]) etr2=lcax; else etr2=a[y].y; int etr3=etr1,etr4=etr2;
                int color=1,color2; if ((dep[etr1]+dep[etr2]-2*dep[lcax])&1) color2=-1; else color2=1;
                while (etr1!=lcax) {COL[++cnt1]=color*faid[etr1]; color=-color; etr1=fa[etr1][0];}
                if (!((dep[etr2]-dep[lcax])&1)) color=-color;
                while (etr2!=lcax) {COL[++cnt1]=color*faid[etr2]; color=-color; etr2=fa[etr2][0];}
                color=-1; COL[++cnt1]=color*x; color=-color;
                int u=a[x].x; while (u!=a[x].y) {COL[++cnt1]=color*faid[u]; color=-color; u=fa[u][0];}
                color=color2;
                if (dep[a[y].y]<dep[lcax]){
                    u=lcax; while (u!=a[y].y) {COL[++cnt1]=color*faid[u]; color=-color; u=fa[u][0];}
                }
                COL[++cnt1]=color*y; color=-color;
                u=a[y].x; while (u!=etr4) {COL[++cnt1]=color*faid[u]; color=-color; u=fa[u][0];}
                int cnt2=0,cnt3=0;
                for (int j=1;j<=cnt1;j++){
                    if (COL[j]>0) ans1[++cnt2]=COL[j];
                    else ans2[++cnt3]=-COL[j];
                }
                cout<<cnt2<<" "<<cnt3<<endl;
                for (int j=1;j<=cnt2;j++) cout<<ans1[j]<<" ";
                cout<<endl;
                for (int j=1;j<=cnt3;j++) cout<<ans2[j]<<" ";
                cout<<endl;
            } else {
                // cerr<<cnt5<<" 2"<<endl;
                int color=1;
                int u=a[x].y; while (u!=a[y].y) {COL[++cnt1]=color*faid[u]; color=-color; u=fa[u][0];}
                COL[++cnt1]=color*y; color=-color;
                u=a[y].x; while(u!=lcax) {COL[++cnt1]=color*faid[u]; color=-color; u=fa[u][0];}
                if (!((dep[a[x].x]-dep[lcax])&1)) {COL[++cnt1]=color*x; color=-color;} else COL[++cnt1]=-color*x;
                u=a[x].x; while (u!=lcax) {COL[++cnt1]=color*faid[u]; color=-color; u=fa[u][0];}
                COL[++cnt1]=-x;
                int cnt2=0,cnt3=0;
                for (int j=1;j<=cnt1;j++){
                    if (COL[j]>0) ans1[++cnt2]=COL[j];
                    else ans2[++cnt3]=-COL[j];
                }
                cout<<cnt2<<" "<<cnt3<<endl;
                for (int j=1;j<=cnt2;j++) cout<<ans1[j]<<" ";
                cout<<endl;
                for (int j=1;j<=cnt3;j++) cout<<ans2[j]<<" ";
                cout<<endl;
            }
            continue;
        }
        // cerr<<cnt5<<endl;
        cout<<-1<<endl;
    }
    return 0;
}
/*
1
5 6
1 2
2 3
3 4
4 1
2 4
4 5

1
3 2
1 2
2 3

2
5 6
1 2
2 3
3 4
4 1
2 4
4 5
3 2
1 2
2 3

*/