#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int T,n;
int a[MAXN];
int ton[MAXN],ton2[MAXN];
int b[MAXN];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            if (!ton[a[i]]) ton[a[i]]=1,b[a[i]]=i;
            else ton2[i]=1;
        }
        int q[MAXN],tot=0,cnt=n,ans=0;
        for (int i=1;i<=n;i++){
            if (!ton2[i]) q[++tot]=a[i],ans++;
            else {
                while (ton[cnt]) cnt--;
                q[++tot]=cnt;
                cnt--;
            }
        }
        cout<<ans<<endl;
        for (int i=1;i<=tot;i++){
            if (q[i]==i){
                // cout<<q[i]<<" "<<a[i]<<endl;
                swap(q[i],q[b[a[i]]]);
            }
        }
        for (int i=1;i<=tot;i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
        for (int i=1;i<=n;i++) a[i]=0,ton[i]=0,ton2[i]=0,b[i]=0;
        // memset(a,0,sizeof a);
        // memset(ton,0,sizeof ton);
        // memset(ton2,0,sizeof ton2);
        // memset(b,0,sizeof b);
    }
    return 0;
}