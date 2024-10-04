#include <bits/stdc++.h>
#define MAXN 500003
using namespace std;
int n,m;
vector <int> e[MAXN];
int du[MAXN];
int main(){
    freopen("fleury.in","r",stdin);
    freopen("fleury.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        e[v].push_back(u);
        e[u].push_back(v);
        du[v]++; du[u]++;
    }
    bool is_sub3=1;
    for (int i=1;i<=n;i++){
        if (du[i]!=2){
            is_sub3=0;
            break;
        }
    }
    if (is_sub3){
        cout<<1<<endl;
        return 0;
    }
    return 0;
}