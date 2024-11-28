#include <bits/stdc++.h>
#define MAXN 53
#define MAXP 53
#define ull unsigned long long
using namespace std;
int n;
ull a[MAXN];
ull p[MAXP];
void insert(ull x){
    for (int i=50;i>=0;i--){
        if (!(x>>i)) continue;
        if (!p[i]){
            p[i]=x;
            break;
        }
        x=x^p[i];
    }
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        insert(a[i]);
    }
    ull ans=0;
    for (int i=50;i>=0;i--){
        // if (p[i]&&!(ans&(1<<i))) ans^=p[i];
        ans=max(ans,ans^p[i]);
    }
    cout<<ans<<'\n';
    return 0;
}