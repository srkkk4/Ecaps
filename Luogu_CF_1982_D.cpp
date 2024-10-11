#include <bits/stdc++.h>
#define MAXN 503
using namespace std;
int T;
int n,m,k;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
long long sum[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n>>m>>k;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        long long cha=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                char ch; cin>>ch;
                if (ch=='1') b[i][j]=-1;
                else b[i][j]=1; 
                cha+=a[i][j]*b[i][j];
            }
        }
        cha=abs(cha);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+b[i][j];
            }
        }
        int gcd=0;
        for (int i=1;i<=n-k+1;i++){
            for (int j=1;j<=m-k+1;j++){
                int x=i+k-1,y=j+k-1;
                int p=abs(sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1]);
                if (p) gcd=(gcd)?__gcd(gcd,p):p;
            }
        }
        if (!cha) cout<<"YES\n";
        else {
            if ((gcd!=0)&&(cha%gcd==0)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}