#include <bits/stdc++.h>
#define MAXN 200003
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define int long long
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,m,q;
char a[MAXN<<1];
int sum[MAXN];
int to[MAXN];
__int128 bf[MAXN][63];
bool ED;
signed main(){
    // freopen("kingdom4.in","r",stdin);
    // freopen("kingdom.in","r",stdin);
    // freopen("kingdom.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;
    cin>>a+1; for (int i=1;i<=n;i++) {a[n+i]=a[i]; sum[i]=sum[i-1]+a[i]-'0';}
    for (int i=1,flag=0;i<=n*2;i++){
        if (a[(i-1)%n+1]=='1') flag=(i-1)%n+1;
        if (!to[(i-1)%n+1]) to[(i-1)%n+1]=flag;
    }
    for (int i=1;i<=n;i++){
        if (m>=n&&sum[n]){
            bf[i][0]=m-(((i+m-1)%n+1+n-to[(i+m-1)%n+1])%n);
        } else if (!sum[n]){
            bf[i][0]=1;
        } else {
            int j=(i+m-1)%n+1;
            if (i>j){
                int chk=sum[n]-sum[i]+sum[j];
                if (chk){
                    bf[i][0]=m-((j-to[j]+n)%n);
                } else {
                    bf[i][0]=1;
                }
            } else {
                int chk=sum[j]-sum[i];
                if (chk){
                    bf[i][0]=to[j]-i;
                } else {
                    bf[i][0]=1;
                }
            }
        }
    }
    for (int i=1;i<=60;i++){
        for (int j=1;j<=n;j++){
            bf[j][i]=bf[j][i-1]+bf[(bf[j][i-1]+j-1)%n+1][i-1];
        }
    }
    while (q--){
        int s,k; cin>>s>>k;
        int res=s; s=(s-1)%n+1;
        for (int i=60;i>=0;i--){
            if (k&(1ll<<i)){
                res=(bf[s][i]+res)%mod;
                s=(bf[s][i]+s-1)%n+1;
            }
        }
        cout<<res%mod<<'\n';
    }
    return 0;
}