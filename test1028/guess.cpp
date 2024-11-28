#include <bits/stdc++.h>
#define MAXN 3003
using namespace std;
int n,m;
string s[MAXN];
bool is[8388610];
// bool ton[8388610];
long long ans[25];
// long long fac[25];
// void init(){
//     fac[0]=fac[1]=1;
//     for (int i=2;i<=24;i++){
//         fac[i]=fac[i-1]*i;
//     }
//     return;
// }
// long long C(int M,int N){
//     if (N>M) return 0;
//     return fac[M]/(fac[N]*fac[M-N]);
// }
int main(){
    // freopen("guess4.in","r",stdin);
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>s[i];
    // init();
    for (int i=1;i<=n;i++){
        for (int j=1;j<i;j++){
            int now=0;
            for (int k=0;k<=m-1;k++){
                if (s[i][k]==s[j][k]){
                    now=now^(1<<k);
                }
            }
            is[now]=1;
        }
    }
    for (int i=(1<<m)-1;i>=1;i--){
        if (!is[i]) continue;
        for (int j=0;j<=m-1;j++){
            if (i&(1<<j)){
                is[i^(1<<j)]=1;
            }
        }
    }
    for (int i=(1<<m)-1;i>=1;i--){
        if (is[i]) continue;
        int cnt=0;
        for (int j=0;j<=m-1;j++){
            if (i&(1<<j)) cnt++;
        }
        ans[cnt]++;
    }
    // for (int i=1;i<=cnt;i++){
    //     for (int j=0;j<=m-1;j++){
    //         if (pre[i]&(1<<j)) cout<<1;
    //         else cout<<0;
    //     }
    //     cout<<endl;
    // }
    // int now=0;
    // for (int i=1;i<=cnt;i++){
    //     int arg=now&pre[i];
    //     // cout<<">:";
    //     // for (int j=0;j<=m-1;j++){
    //     //     cout<<bool((arg)&(1<<j));
    //     // }
    //     // cout<<endl;
    //     int tot=0;
    //     while (arg) {
    //         if (arg&1) tot++;
    //         arg>>=1;
    //     }
    //     int nowcnt=0,precnt=0;
    //     for (int j=0;j<=m-1;j++){
    //         if (now&(1<<j)) nowcnt++;
    //         if (pre[i]&(1<<j)) precnt++;
    //     }
    //     for (int j=1;j<=m;j++){
    //         ans[j]+=C(precnt,j)-C(tot,j);
    //     }
    //     now=now|pre[i];
    //     // cout<<">:";
    //     // for (int j=0;j<=m-1;j++){
    //     //     if (now&(1<<j)) cout<<1;
    //     //     else cout<<0;
    //     // }
    //     // cout<<endl;
    // }
    // for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
    // cout<<endl;
    // for (int i=1;i<=m;i++){
        // cout<<"->:"<<C(m,i)<<endl;
        // ans[i]=C(m,i)-ans[i];
    // }
    for (int i=1;i<=m;i++){
        if (ans[i]){
            cout<<i<<" "<<ans[i]<<endl;
            break;
        }
    }
    return 0;
}
/*
5 4
abac
caab
bcca
cbaa
acbb
*/