#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n;
int a[MAXN];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long ans=0; int mx=0;
    cin>>n;
    for (int i=1;i<=n;i++) {cin>>a[i]; mx=max(mx,a[i]); ans+=a[i];}
    ans-=mx;
    for (int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        ans+=max(a[x],a[y]);
    }
    cout<<ans<<endl;
    return 0;
}