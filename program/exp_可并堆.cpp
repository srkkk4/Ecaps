// luogu 3377
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define MAXN 100003
using namespace std;
using namespace __gnu_pbds;
int n,m;
int a[MAXN];
int fa[MAXN],vis[MAXN];
int find(int x){
    while (fa[x]!=x) x=fa[x]=fa[fa[x]];
    return x;
}
struct Pair{
    int num;
    int id;
    bool operator<(const Pair b)const{
        if (num==b.num) return id>b.id;
        else return num>b.num;
    }
};
__gnu_pbds::priority_queue <Pair> q[MAXN];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i]; fa[i]=i; q[i].push((Pair){a[i],i});
    }
    for (int i=1;i<=m;i++){
        int tpye; cin>>tpye;
        if (tpye==1){
            int x,y; cin>>x>>y;
            int rtx=find(x),rty=find(y);
            if (rtx==rty||vis[x]||vis[y]) continue;
            q[rtx].join(q[rty]); fa[rty]=rtx;
        } else {
            int x; cin>>x;
            if (vis[x]){
                cout<<-1<<endl;
                continue;
            }
            int rt=find(x);
            Pair TOP=q[rt].top();
            q[rt].pop();
            vis[TOP.id]=1;
            cout<<TOP.num<<endl;
        }
    }
    return 0;
}