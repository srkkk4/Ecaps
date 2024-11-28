#include <bits/stdc++.h>
#define MAXN 303
#define mod 1000000007
using namespace std;
int n,m;
int a[MAXN];
long long f[MAXN][MAXN][MAXN][2];
long long fac[MAXN];
void init(){
    fac[0]=fac[1]=1;
    for (int i=2;i<=n;i++){
        fac[i]=fac[i-1]*i%mod;
    }
}
int cnt1,cnt2;
int main(){
    freopen("2475.in","r",stdin);
    freopen("2475.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    init();
    for (int i=1;i<=n;i++) {cin>>a[i]; if (a[i]!=0) {if (a[i]%2) cnt2++; else cnt1++;}}
    if (a[1]!=0){
        if (a[1]%2) f[1][1][0][1]=1;
        else f[1][1][1][0]=1;
    } else {
        f[1][1][1][0]=f[1][1][0][1]=1;
    }
    for (int i=2;i<=n;i++){
        for (int j=1;j<=i;j++){
            for (int k=0;k<=i;k++){
                if (((!a[i])||(a[i]%2==0))&&k>0) f[i][j][k][0]=(f[i-1][j][k-1][0]+f[i-1][j-1][k-1][1])%mod;
                if ((!a[i])||(a[i]%2==1)) f[i][j][k][1]=(f[i-1][j-1][k][0]+f[i-1][j][k][1])%mod;
            }
        }
        // for (int j=1;j<=n;j++){
        //     for (int k=0;k<=n;k++){
        //         cout<<f[i][j][k][0]<<" ";
        //     }
        //     cout<<" ";
        //     for (int k=0;k<=n;k++){
        //         cout<<f[i][j][k][1]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    if (a[n]!=0){
        if (a[n]%2){
            cout<<f[n][m][n/2][1]*fac[n/2-cnt1]%mod*fac[n-n/2-cnt2]%mod<<endl;
        } else {
            cout<<f[n][m][n/2][0]*fac[n/2-cnt1]%mod*fac[n-n/2-cnt2]%mod<<endl;
        }
    } else {
        cout<<(f[n][m][n/2][0]*fac[n/2-cnt1]%mod*fac[n-n/2-cnt2]%mod+f[n][m][n/2][1]*fac[n/2-cnt1]%mod*fac[n-n/2-cnt2]%mod)%mod<<endl;
    }
    return 0;
}