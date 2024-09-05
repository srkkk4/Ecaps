#include <bits/stdc++.h>
#define mod 1000000007
#define MAXN 10000003
using namespace std;
int l,r;
int n,k;
bool vis[MAXN];
int main(){
    cin>>l>>r;
    n=r-l+1;
    for (int i=l;i<=r;i++){
        if (vis[i]) continue;
        k++;
        for (int j=i;j<=r;j+=i){
            vis[j]=1;
        }
    }
    long long ans=k;
    for (int i=1;i<=n+1;i++){
        if (i==k+1) continue;
        ans=(ans*i)%mod;
    }
    cout<<ans<<endl;
    return 0;
}