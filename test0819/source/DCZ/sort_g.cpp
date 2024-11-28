#include <bits/stdc++.h>
#define MAXW 1003
using namespace std;
char a[MAXW]; int n;
int vis[MAXW];
__int128 x=0;
int ok=0; int OUT[MAXW],cnt=0;
bool cmp(char A,char B){
    return A>B;
}
void dfs(int u,int len){
    if (ok) return;
    if (len==n){
        if (x%11==0){
            ok=1;
            while (x){
                OUT[++cnt]=x%10;
                x/=10;
            }
            for (int i=cnt;i>=1;i--){
                cout<<OUT[i];
            }
            cout<<endl;
        }
        return;
    }
    vis[u]=1;
    for (int v=0;v<=n-1;v++){
        if (vis[v]) continue;
        x*=10; x+=int(a[v]-'0');
        dfs(v,len+1);
        x/=10;
    }
    vis[u]=0;
    return;
}
int main(){
    cin>>a;
    n=strlen(a);
    sort(a,a+n,cmp);
    if (n<=1000){
        for (int i=0;i<=n-1;i++){
            x=int(a[i]-'0');
            dfs(i,1);
            if (ok) break;
        }
    }
    return 0;
}