#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#define MAXN 1000003
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int T;
char s[6][MAXN];
int nxt[21][MAXN];
vector <int> e[MAXN];
int dep[MAXN]; int mxdep;
queue <int> q;
void gd(int s){
    q.push(s);
    while (!q.empty()){
        int u=q.front(); q.pop();
        for (int v:e[u]){
            dep[v]=dep[u]+1; mxdep=(dep[v]>mxdep?dep[v]:mxdep);
            q.push(v);
        }
    }
    return;
}
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    for (int i=1;i<=T;i++) cin>>s[i]+1;
    for (int i=1;i<=T;i++){
        int p=0; nxt[0][1]=0; int n=strlen(s[i]+1);
        for (int i=1;i<=n;i++) e[i].clear();

        e[0].pb(1);
        for (int j=2;j<=n;j++){
            while (p>0&&s[i][p+1]!=s[i][j]) p=nxt[0][p];
            if (s[i][p+1]==s[i][j]) p=p+1;
            nxt[0][j]=p;
            e[p].pb(j);
        }
        mxdep=0; gd(0);
        int LOG=log(mxdep)/log(2)+0.5;
        for (int j=1;j<=LOG;j++){
            for (int k=1;k<=n;k++){
                nxt[j][k]=nxt[j-1][nxt[j-1][k]];
            }
        }

        long long ans=1;
        for (int j=1;j<=n;j++){
            p=j;
            for (int k=LOG;k>=0;k--){
                if ((nxt[k][p]<<1)<=j) continue;
                p=nxt[k][p];
            }
            p=nxt[0][p];
            ans=ans*(dep[p]+1)%mod;
        }
        cout<<ans<<'\n';
    }
    return 0;
}