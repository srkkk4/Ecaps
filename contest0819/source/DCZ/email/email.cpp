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
    freopen("email.in","r",stdin);
    freopen("email.out","w",stdout);
    cin>>T;
    while (T--){
        cin>>m>>n>>K;
        for (int i=1;i<=m;i++) e[i]=0;
        for (int i=1;i<=n;i++){
            cin>>f[i];
            e[f[i]]++;
        }
        // for (int i=1;i<=m;i++) cout<<e[i]<<" ";
        // cout<<endl;
        l=1; r=K; p=1; L=1; cnt=0;
        while (r<=m){
            for (int i=cnt;i>=L;i--){
                if (f[stk[i]]>=l&&f[stk[i]]<=r){
                    e[f[stk[i]]]--;
                    for (int j=i+1;j<=cnt;j++) stk[j-1]=stk[j];
                    cnt--;
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
            if (p>n){
                for (int i=cnt;i>=L;i--){
                    if (f[stk[i]]>=l&&f[stk[i]]<=r){
                        for (int j=i+1;j<=cnt;j++) stk[j-1]=stk[j];
                        cnt--;
                    }
                }
                // cout<<L<<" "<<cnt<<endl;
                int P=L-1;
                while (e[l]&&P>=1){
                    if (f[stk[P]]>=l&&f[stk[P]]<=r){
                        e[f[stk[P]]]--;
                        for (int j=P+1;j<=cnt;j++) stk[j-1]=stk[j];
                    } else {
                        stk[--L]=P;
                        if (cnt-L+1>K) break;
                    }
                    P--;
                }
                // L=1;
                // for (int i=cnt;i>=L;i--){
                //     if (f[stk[i]]>=l&&f[stk[i]]<=r) cnt--;
                // }
            }
            // cout<<l<<" "<<r<<" "<<L<<" "<<cnt<<endl;
            l++; r++;
        }
        if (cnt) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}