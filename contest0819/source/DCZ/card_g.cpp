#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int n,m;
int a[MAXN];
int cnt[MAXN];
int tot[MAXN];
int ans=0;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cnt[a[i]]++;
        if (a[i]>=cnt[a[i]]){
            if (!tot[a[i]-cnt[a[i]]+1]) ans++;
            tot[a[i]-cnt[a[i]]+1]++;
        }
    }
    while (m--){
        int x,y;
        cin>>x>>y;
        if (a[x]>=cnt[a[x]]){
            tot[a[x]-cnt[a[x]]+1]--;
            if (!tot[a[x]-cnt[a[x]]+1]) ans--;
        }
        cnt[a[x]]--;
        cnt[y]++;
        if (y>=cnt[y]){
            if (!tot[y-cnt[y]+1]) ans++;
            tot[y-cnt[y]+1]++;
        }
        a[x]=y;
        cout<<n-ans<<endl;
    }
    return 0;
}