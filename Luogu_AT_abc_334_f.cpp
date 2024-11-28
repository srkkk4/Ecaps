#include <bits/stdc++.h>
#define MAXN 200003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,k;
int sx,sy;
struct D{
    int x; int y;
}a[MAXN];
double ds[MAXN];
double dsum[MAXN];
int inx;
struct DP{
    double val;
    int id;
}dp[MAXN];
DP q[MAXN]; int hand=1,tail=1;
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    cin>>sx>>sy;
    for (int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    for (int i=1;i<=n;i++){
        ds[i]=sqrt(1ll*(a[i].x-sx)*(a[i].x-sx)+1ll*(a[i].y-sy)*(a[i].y-sy));
    }
    for (int i=2;i<=n;i++){
        double dis=sqrt(1ll*(a[i].x-a[i-1].x)*(a[i].x-a[i-1].x)+1ll*(a[i].y-a[i-1].y)*(a[i].y-a[i-1].y));
        dsum[i]=dsum[i-1]+dis;
    }
    // for (int i=1;i<=n;i++) cerr<<dsum[i]<<' ';
    // cerr<<'\n';
    for (int i=1;i<=n;i++) dp[i].id=i;
    for (inx=1;inx<=n;inx++){
        while (q[tail].id<inx-k) tail++;
        dp[inx].val=dp[q[tail].id].val+ds[q[tail].id+1]+(dsum[inx]-dsum[q[tail].id+1])+ds[inx];
        while (hand>=tail&&q[hand].val>=dp[inx].val+ds[inx+1]-dsum[inx+1]) hand--;
        q[++hand].val=dp[inx].val+ds[inx+1]-dsum[inx+1]; q[hand].id=inx;
    }
    printf("%0.15lf\n",dp[n].val);
    return 0;
}