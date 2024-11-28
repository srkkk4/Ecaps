#include <bits/stdc++.h>
#define MAXN 1000003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
#define int long long 
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,m;
struct OB{
    int a; int b;
}ob[MAXN];
struct TK{
    int a; int b;
    bool operator<(const TK &B)const{
        if (b==B.b) return a>B.a;
        return b<B.b;
    }
}tk[MAXN];
bool cmp1(OB A,OB B){
    return A.a<B.a;
}
bool cmp2(TK A,TK B){
    return A.a<B.a;
}
priority_queue <TK> q;
bool ED;
signed main(){
    freopen("buy6.in","r",stdin);
    freopen("buy.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        int tmp1,tmp2; cin>>tmp1>>tmp2;
        ob[i].a=tmp1; ob[i].b=tmp1-tmp2;
    }
    for (int i=1;i<=m;i++){
        cin>>tk[i].a>>tk[i].b;
    }
    for (int i=1;i<=n;i++){
        tk[m+i].a=ob[i].a; tk[m+i].b=ob[i].b;
    }
    m+=n;
    sort(ob+1,ob+1+n,cmp1);
    sort(tk+1,tk+1+m,cmp2);
    long long ans=0;
    int j=1;
    for (int i=1;i<=n;i++){
        while (tk[j].a<=ob[i].a&&j<=m) {q.push(tk[j]); j++;}
        if (q.empty()) {ans+=ob[i].a-ob[i].b; continue;}
        TK now=q.top();
        q.pop();
        if (ob[i].b>=now.b) ans+=ob[i].a-ob[i].b;
        else ans+=ob[i].a-now.b;
    }
    cout<<ans<<'\n';
    return 0;
}