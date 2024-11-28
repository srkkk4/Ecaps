#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n;
vector <int> e[MAXN];
int du[MAXN];
int main(){
    freopen("infer.in","r",stdin);
    freopen("infer.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        du[u]++; du[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ok=1;
    for (int i=1;i<=n;i++) if (du[i]!=2) {ok=0; break;}
    if (ok){
        if (!(n%4)){
            cout<<n/2<<endl;
        } else {
            cout<<-1<<endl;
        }
    } else {
        cout<<-1<<endl;
    }
    return 0;
}