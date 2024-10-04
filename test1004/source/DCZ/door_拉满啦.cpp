#include <bits/stdc++.h>
#define MAXN 20003
using namespace std;
int n,m;
int T(char c){
    if (c=='*') return 1;
    if (c=='&') return 2;
    if (c=='#') return 3;
    if (c=='$') return 4;
}
struct D{
    bool r;
    vector <int> e;
    int ch[5];
}a[MAXN];
int tot;
int vis[MAXN];
int dep[MAXN]; int fa[MAXN];
void inDep(int u,int d){
    dep[u]=d;
    vis[u]=1;
    for (auto v:a[u].e){
        if (vis[v]) continue;
        fa[v]=u;
        inDep(v,d+1);
    }
    return;
}
void del(int u){
    a[u].r=0;
    for (auto v:a[u].e){
        if (fa[u]==v) continue;
        if (!a[v].r) continue;
        del(v);
    }
    return;
}
void ADD(int u,int v){
    for (int i=1;i<=4;i++){
        if (a[v].ch[i]) a[u].ch[i]=1;
    }
    for (auto v2:a[v].e){
        if (fa[v]==v2) continue;
        if (!a[v].r) continue;
        a[u].e.push_back(v2);
        fa[v2]=u;
    }
    a[v].r=0;
    return;
}
int q[MAXN],cnt;
void find(int u,int t){
    if (a[u].ch[t]) q[++cnt]=u;
    for (auto v:a[u].e){
        if (fa[u]==v) continue;
        if (!a[v].r) continue;
        find(v,t);
    }
    return;
}
int ans[MAXN],cnt2;
int main(){
    freopen("door.in","r",stdin);
    freopen("door.ans","w",stdout);
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    bool flag=1;
    cin>>n; tot=n;
    for (int i=1;i<=n;i++){
        char c; c=getchar();
        while (!((c=='#')||(c=='$')||(c=='*')||(c=='&'))) c=getchar();
        if (c!='$') flag=0;
        a[i].ch[T(c)]=1;
        a[i].r=1;
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=4;j++){
    //         cout<<a[i].ch[j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for (int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        a[u].e.push_back(v);
        a[v].e.push_back(u);
    }
    inDep(1,1);
    cin>>m;
    while (m--){
        int tpye; cin>>tpye;
        if (tpye==1){
            int id; char x; cin>>id;
            x=getchar();
            while (!((x=='#')||(x=='$')||(x=='*')||(x=='&'))) x=getchar();
            // cout<<">:"<<x<<endl;
            tot++;
            a[id].e.push_back(tot); fa[tot]=id;
            a[tot].ch[T(x)]=1;
            dep[tot]=dep[id]+1;
            if (!a[id].r) continue;
            a[tot].r=1; 
        } else if (tpye==2){
            int v,u; cin>>v>>u;
            if ((!a[v].r)||(!a[u].r)) continue;
            if (dep[u]<dep[v]) swap(u,v);
            int V=v,U=u;
            while (dep[U]!=dep[V]) U=fa[U];
            if (U==V) continue;
            while (U!=V){
                ADD(U,V);
                V=fa[V],U=fa[U];
            }
        } else {
            string x; cin>>x;
            if (!a[1].r) {cout<<endl; continue;}
            int len=x.length();
            if (flag){
                for (int i=1;i<=tot;i++){
                    if (a[i].r&&a[i].ch[4]&&dep[i]>=len){
                        cout<<i<<" ";
                    }
                }
                cout<<endl;
                continue;
            }
            cnt=0;
            find(1,T(x[len-1]));
            // for (int i=1;i<=tot;i++){
            //     if (a[i].ch[T(x[len-1])]){
            //         q[++cnt]=i;
            //     }
            // }
            cnt2=0;
            for (int i=1;i<=cnt;i++){
                // if (flag&&dep[q[i]]>=len){
                //     ans[++cnt2]=q[i];
                //     continue;
                // }
                int p=fa[q[i]],ok=1;
                for (int j=len-2;j>=0;j--){
                    if (!a[p].ch[T(x[j])]){
                        ok=0;
                        break;
                    }
                    p=fa[p];
                }
                if (ok) ans[++cnt2]=q[i];
            }
            std::sort(ans+1,ans+1+cnt2);
            for (int i=1;i<=cnt2;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
/*
10
# $ * & * # $ $ * &
1 2
2 3
1 4
4 6
4 5
2 7
7 8
7 9
7 10
4
1 8 *
3 $$*
2 5 11
3 &$&
*/