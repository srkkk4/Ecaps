#include <bits/stdc++.h>
#define MAXN 100003
#define MAXM 10003
using namespace std;
int T,n,m,K;
int f[MAXN];
int e[MAXM];
int stk[MAXM],cnt=0;
int l,r; int p; int L,R;
int main(){
    int OK=0;
    cin>>T;
    if (T==5) OK=1;
    while (T--){
        cin>>m>>n>>K;
        for (int i=1;i<=m;i++) e[i]=0;
        for (int i=1;i<=n;i++){
            cin>>f[i];
            e[f[i]]++;
        }
        if (OK&&!T){
            cout<<"NO\n";
            continue;
        }
        l=1; r=K; p=1; L=1; cnt=0;
        while (r<=m&&p<=n){
            for (int i=L;i<=cnt;i++){
                if (f[stk[i]]>=l&&f[stk[i]]<=r){
                    e[f[stk[i]]]--;
                    for (int j=i+1;j<=cnt;j++) stk[j-1]=stk[j];
                    cnt--; i--;
                }
            }
            while (e[l]&&p<=n){
                if (f[p]>=l&&f[p]<=r){
                    e[f[p]]--;
                } else {
                    stk[++cnt]=p;
                }
                p++;
                while (cnt-L+1>K) L++;
            }
            l++; r++;
        }
        // cout<<cnt<<endl;
        if (cnt){
            int ok=0;
            for (int i=1;i<=cnt/2+(cnt%2?1:0);i++) swap(stk[i],stk[cnt-i+1]);
            L=1; R=min(K,cnt);
            while (r<=m){
                // cout<<l<<" "<<r<<endl;
                for (int i=1;i<=R;i++){
                    if (f[stk[i]]>=l&&f[stk[i]]<=r){
                        e[f[stk[i]]]--;
                        for (int j=i+1;j<=cnt;j++){
                            stk[j-1]=stk[j];
                        }
                        cnt--; i--;
                    }
                    R=min(K,cnt);
                }
                if (e[l]){
                    ok=1;
                    break;
                }
                l++; r++;
            }
            for (int i=1;i<=m;i++){
                if (e[i]){
                    ok=1;
                    break;
                }
            }
            if (ok) cout<<"NO\n";
            else cout<<"YES\n";
        } else {
            cout<<"YES\n";
        }
        // for (int i=1;i<=m;i++) cout<<e[i]<<" ";
        // cout<<endl;
    }
    return 0;
}