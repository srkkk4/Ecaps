#include <bits/stdc++.h>
#define MAXN 300003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n;
struct AR{
    int a; int b; int id;
    bool operator <(const AR &B)const{
        return b-a<B.b-B.a;
    }
}a[MAXN];
struct PA{
    int a; int id;
    bool operator<(const PA &B)const{
        return a>B.a;
    }
};
int check(long long x){
    priority_queue <AR> q; priority_queue <PA> q2;
    for (int i=1;i<=n;i++){
        if (a[i].a>x) q2.push((PA){a[i].a,a[i].id});
        else q.push(a[i]);
    }
    int res=0;
    while (!q.empty()){
        x+=q.top().b-q.top().a; q.pop();
        if (x<0) break;
        else res++;
        while (!q.empty()&&q.top().a>x){
            AR tmp=q.top(); q.pop();
            q2.push((PA){tmp.a,tmp.id});
        }
        while (!q2.empty()&&q2.top().a<=x){
            PA tmp=q2.top(); q2.pop();
            q.push(a[tmp.id]);
        }
    }
    return res;
}
long long ans[MAXN];
void solve(int nl,int nr,long long l,long long r){
    if (nl>nr) return;
    if (l==r){
        for (int i=nl;i<=nr;i++) ans[i]=l;
        return;
    }
    long long mid=(l+r)>>1;
    int nmid=check(mid);
    solve(nl,nmid,l,mid); solve(nmid+1,nr,mid+1,r);
    return;
}
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b; a[i].id=i;
    }
    solve(1,n,1,3e14);
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}