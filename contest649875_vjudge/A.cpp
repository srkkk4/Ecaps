#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define MAXN 100003
using namespace std;
using namespace __gnu_pbds;
int n,m;
int s[MAXN];
int fa[MAXN];
__gnu_pbds::priority_queue <int> q[MAXN];
int find(int x){
    while (fa[x]!=x) x=fa[x]=fa[fa[x]];
    return x;
}
int main(){
    while (cin>>n){
        for (int i=1;i<=n;i++) cin>>s[i];
        for (int i=1;i<=n;i++) {fa[i]=i; q[i].clear(); q[i].push(s[i]);}
        cin>>m;
        for (int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            int rootu=find(u),rootv=find(v);
            if (rootu!=rootv){
                int topu=q[rootu].top(); q[rootu].pop(); topu/=2; q[rootu].push(topu);
                int topv=q[rootv].top(); q[rootv].pop(); topv/=2; q[rootv].push(topv);
                fa[rootu]=rootv;
                q[rootv].join(q[rootu]);
                cout<<q[rootv].top()<<endl;
            } else {
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}