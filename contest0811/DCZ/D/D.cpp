#include <bits/stdc++.h>
#define MAXN 300003
using namespace std;
int n,L;
struct sub{
    int a,b;
};
sub a[MAXN];
struct info{
    int from;
    int s;
};
info b[MAXN];
int vis[MAXN];
int dfs(int x){
    vis[x]=1;
    int y;
    if (b[x].s==0){
        y=a[b[x].from].b;
    } else {
        y=a[b[x].from].a;
    }
    if (!b[y].from){
        b[y].from=b[x].from;
        b[y].s=!b[x].s;
        return 1;
    }
    if (vis[y]) return 0;
    if (dfs(y)){
        b[y].from=b[x].from;
        b[y].s=!b[x].s;
        return 1;
    }
    else return 0;
}
int ans[MAXN];
int main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    cin>>n>>L;
    for (int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b;
    }
    for (int i=1;i<=n;i++){
        if (!b[a[i].a].from){
            b[a[i].a].from=i;
            b[a[i].a].s=0;
        } else if (!b[a[i].b].from){
            b[a[i].b].from=i;
            b[a[i].b].s=1;
        } else {
            memset(vis,0,sizeof vis);
            if (dfs(a[i].a)){
                b[a[i].a].from=i;
                b[a[i].a].s=0;
            } else {
                memset(vis,0,sizeof vis);
                if (dfs(a[i].b)){
                    b[a[i].b].from=i;
                    b[a[i].b].s=1;
                }
            }
        }
    }
    for (int i=1;i<=L;i++){
        ans[b[i].from]=1;
    }
    for (int i=1;i<=n;i++){
        if (ans[i]){
            cout<<"LADICA\n";
        } else {
            cout<<"SMECE\n";
        }
    }
    return 0;
}