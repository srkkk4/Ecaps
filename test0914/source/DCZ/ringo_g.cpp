#include <bits/stdc++.h>
#define MAXN 1003
#define mod 998244353
#define MEM(x) memset(x,0,sizeof x);
using namespace std;
int T,id;
int n,m;
int a[MAXN][MAXN];
int toup[MAXN][MAXN],tolf[MAXN][MAXN],todn[MAXN][MAXN],tori[MAXN][MAXN];
long long f[MAXN][MAXN],f2[MAXN][MAXN],fl[MAXN],fh[MAXN];
int main(){
    cin>>T>>id;
    while (T--){
        MEM(a); MEM(toup); MEM(tolf); MEM(todn); MEM(tori); MEM(f); MEM(f2); MEM(fl); MEM(fh);
        cin>>n>>m;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                char ch; cin>>ch;
                if (ch=='#') a[i][j]=1;
            }
        }
        for (int j=1;j<=m;j++){
            int flag=0;
            for (int i=1;i<=n;i++){
                if (a[i][j]){
                    flag=i;
                }
                toup[i][j]=flag;
            }
        }
        for (int j=1;j<=m;j++){
            int flag=n+1;
            for (int i=n;i>=1;i--){
                if (a[i][j]){
                    flag=i;
                }
                todn[i][j]=flag;
            }
        }
        for (int i=1;i<=n;i++){
            int flag=0;
            for (int j=1;j<=m;j++){
                if (a[i][j]){
                    flag=j;
                }
                tolf[i][j]=flag;
            }
        }
        for (int i=1;i<=n;i++){
            int flag=m+1;
            for (int j=m;j>=1;j--){
                if (a[i][j]){
                    flag=j;
                }
                tori[i][j]=flag;
            }
        }
        long long ans=0;
        for (int j=1;j<=m;j++){
            for (int i=1;i<=n;i++){
                fl[j]+=i-toup[i][j];
                f[i][j]=fl[j];
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                fh[i]+=j-tolf[i][j];
                f2[i][j]=fh[i];
            }
        }
        for (int j=1;j<=m;j++){
            for (int i=1;i<=n;i++){
                ans=(ans+(todn[i][j]-i)*f[i-1][j]*2)%mod;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                ans=(ans+(tori[i][j]-j)*f2[i][j-1]*2)%mod;
            }
        }
        for (int j=1;j<=m;j++){
            for (int k=1;k<j;k++){
                ans=(ans+fl[j]*fl[k]*2)%mod;
            }
        }
        for (int i=1;i<=n;i++){
            for (int k=1;k<i;k++){
                ans=(ans+fh[i]*fh[k]*2)%mod;
            }
        }
        long long totl=0,toth=0;
        for (int j=1;j<=m;j++) totl+=fl[j];
        for (int i=1;i<=n;i++) toth+=fh[i];
        ans=ans+totl*toth*2;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                ans-=1ll*(j-tolf[i][j])*(tori[i][j]-j)*(i-toup[i][j])*(todn[i][j]-i)*2;
            }
        }
        cout<<ans%mod<<endl;
    }
    return 0;
}