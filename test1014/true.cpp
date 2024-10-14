#include <bits/stdc++.h>
#define MAXN 5003
#define MAXM 5003
#define mod 998244353
using namespace std;
int n,m;
long long g[MAXM][MAXM];
long long sum[MAXM],sum2[MAXM];
long long s[MAXN][MAXM],t[MAXN][MAXM];
int main(){
	// freopen("true.in","r",stdin);
	// freopen("true.out","w",stdout);
	cin>>n>>m;
    for (int l=1;l<=m;l++){
        for (int r=l;r<=m;r++){
            g[l][r]=1;
        }
    }
    for (int l=1;l<=m;l++){
        for (int r=1;r<=m;r++){
            g[l][r]=g[l-1][r]+g[l][r-1]+g[l][r]-g[l-1][r-1];
        }
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=m;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i=1;i<=m;i++) sum[i]=(sum[i-1]+g[i][m])%mod;
    for (int i=1;i<=m;i++) sum2[i]=(sum2[i-1]+g[m][i])%mod;
    for (int r=1;r<=m;r++){
        s[1][r]=s[1][r-1];
        for (int l=1;l<=r;l++) s[1][r]=(s[1][r]+sum[m]*l-sum2[l-1]*r+mod)%mod;
    }
    for (int l=1;l<=m;l++){
        t[1][l]=t[1][l-1];
        for (int r=1;r<=l;r++) {t[1][l]=(t[1][l]+sum[r]*l-sum2[m-1]*r)%mod; cout<<sum[r]*l<<" "<<sum2[m-1]*r<<endl;}
    }
    for (int i=2;i<=n;i++){
        for (int r=1;r<=m;r++) s[i][r]=(s[i][r-1]+s[i-1][m]*r-t[i-1][r-1]*r-t[i-2][r-2])%mod;
        for (int l=1;l<=m;l++) t[i][l]=(t[i][l-1]+s[i-1][l]*l+s[i-2][l-1]-t[i-1][m-1]*l)%mod;
    }
    cout<<s[n][m]<<endl;
	return 0; 
}