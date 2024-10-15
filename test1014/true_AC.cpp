//Luogu P9108
#include <bits/stdc++.h>
#define MAXNM 10000003
using namespace std;
int n,m,p;
vector <int> f[2],g[2],sum1[2],sum2[2];
int main(){
	cin>>n>>m>>p; bool pos=0;
    for (int i=0;i<=m+1;i++) f[pos].push_back(0);
    for (int i=0;i<=m+1;i++) g[pos].push_back(0);
    for (int i=0;i<=m+1;i++) sum1[pos].push_back(0);
    for (int i=0;i<=m+1;i++) sum2[pos].push_back(0);
    for (int i=0;i<=m+1;i++) f[!pos].push_back(0);
    for (int i=0;i<=m+1;i++) g[!pos].push_back(0);
    for (int i=0;i<=m+1;i++) sum1[!pos].push_back(0);
    for (int i=0;i<=m+1;i++) sum2[!pos].push_back(0);
    for (int i=1;i<=m;i++) f[pos][i]=m-i+1;
    for (int i=1;i<=m;i++) g[pos][i]=i;
    for (int i=1;i<=m;i++) f[pos][i]=(0ll+f[pos][i-1]+f[pos][i])%p;
    for (int i=1;i<=m;i++) g[pos][i]=(0ll+g[pos][i-1]+g[pos][i])%p;
    for (int i=m;i>=1;i--) sum1[pos][i]=(0ll+sum1[pos][i+1]+(0ll+f[pos][m]-f[pos][i])+p)%p;
    for (int i=1;i<=m;i++) sum2[pos][i]=(0ll+sum2[pos][i-1]+g[pos][i-1])%p;
    for (int i=2;i<=n;i++){
        pos=!pos;
        for (int j=1;j<=m;j++){
            f[pos][j]=(1ll*(m-j+1)*((f[!pos][m]-g[!pos][j-1]+p)%p)-sum1[!pos][j]+p)%p;
            g[pos][j]=(1ll*j*((g[!pos][m]-(f[!pos][m]-f[!pos][j]+p)%p+p)%p)-sum2[!pos][j]+p)%p;
        }
        for (int j=1;j<=m;j++) f[pos][j]=(0ll+f[pos][j-1]+f[pos][j])%p;
        for (int j=1;j<=m;j++) g[pos][j]=(0ll+g[pos][j-1]+g[pos][j])%p;
        for (int j=m;j>=1;j--) sum1[pos][j]=(0ll+sum1[pos][j+1]+(f[pos][m]-f[pos][j]+p)%p+p)%p;
        for (int j=1;j<=m;j++) sum2[pos][j]=(0ll+sum2[pos][j-1]+g[pos][j-1])%p;
    }
    cout<<f[pos][m]<<endl;
	return 0; 
}