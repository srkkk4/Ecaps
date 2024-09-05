#include <bits/stdc++.h>
#define MAXN 100003
#define MAXM 200003
using namespace std;
int n,m;
vector <int> e[MAXN];
int du[MAXN];
int vistime[MAXN];
int u[MAXM],v[MAXM];
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        scanf("%d %d",&u[i],&v[i]);
        du[u[i]]++; du[v[i]]++;
    }
    for (int i=1;i<=m;i++){
        if (du[u[i]]>du[v[i]]||(du[u[i]]==du[v[i]]&&u[i]>v[i])){
            swap(u[i],v[i]);
        }
        e[u[i]].push_back(v[i]);
    }
    int ans=0;
    for (int u=1;u<=n;u++){
        for (auto v:e[u]){
            vistime[v]=u;
        }
        for (auto v:e[u]){
            for (auto w:e[v]){
                if (vistime[w]==u){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}