#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int n,m;
int a[MAXN];
int cnt[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cnt[a[i]]++;
    }
    while (m--){
        int x,y;
        cin>>x>>y;
        cnt[a[x]]--; cnt[y]++;
        a[x]=y;
        // for (int i=1;i<=n;i++) cout<<cnt[i]<<" ";
        // cout<<endl;
        int ans=0;
        int last=n;
        for (int i=n;i>=0;i--){
            if (cnt[i]||i==0){
                ans+=max(last-i-cnt[last],0);
                last=i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}