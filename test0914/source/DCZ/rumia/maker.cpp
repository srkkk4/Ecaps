#include <bits/stdc++.h>
#define MAXN 100003
#define mod 998244353
using namespace std;
int n; long long cnt=0;
int vis[MAXN];
void dfs(int x,int s){
    if (x==1){
        cnt++;
        return;
    }
    vis[x]=1;
    if (x<n&&s!=2){
        if (!vis[x+1]) dfs(x+1,1);
    }
    if (!vis[x-1]) dfs(x-1,0);
    if (s==1){
        for (int i=2;i<=x/2;i++){
            if (x%i==0){
                if (!vis[i]) dfs(i,2);
            }
        }
        cnt++;
    } else {
        for (int i=2;i<=x/2;i++){
            if (x%i==0){
                if (!vis[i]) dfs(i,0);
            }
        }
        cnt++;
    }
    vis[x]=0;
    return;
}
int main(){
    for (n=251;n<=300;n++){
        memset(vis,0,sizeof vis);
        cnt=0;
        dfs(n,0);
        cout<<cnt<<","<<endl;
    }
    return 0;
}