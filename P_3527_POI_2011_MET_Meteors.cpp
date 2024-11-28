#include <bits/stdc++.h>
#define MAXN 300003
using namespace std;
int n,m,k;
int O[MAXN*2];
vector <int> stt[MAXN];
unsigned long long P[MAXN];
struct rain{
    int l;
    int r;
    int a;
}R[MAXN];
int to[MAXN];
int ans[MAXN];
unsigned long long t[MAXN*2];
int lowbit(int x) {return x&-x;}
void add(int x,int y) {for (int p=x;p<=m*2;p+=lowbit(p)) t[p]+=y; return;}
unsigned long long sum(int x) {unsigned long long res=0; for (int p=x;p>=1;p-=lowbit(p)) res+=t[p]; return res;}
void solve(int ln,int rn,int lk,int rk){
    if (lk==rk){
        for (int i=ln;i<=rn;i++){
            int cty=to[i];
            ans[cty]=lk;
        }
        return;
    }
    int mid=(lk+rk)>>1;
    for (int i=lk;i<=mid;i++) {add(R[i].l,R[i].a); add(R[i].r+1,-R[i].a);}
    vector <int> q1,q2;
    for (int i=ln;i<=rn;i++){
        int cty=to[i]; unsigned long long cnt=0;
        for (int pos:stt[cty]){
            cnt+=sum(pos); cnt+=sum(pos+m);
        }
        if (P[cty]<=cnt) q1.push_back(cty);
        else {q2.push_back(cty); P[cty]-=cnt;}
    }
    for (int i=lk;i<=mid;i++) {add(R[i].l,-R[i].a); add(R[i].r+1,R[i].a);}
    int inx=ln;
    for (int cty:q1) to[inx++]=cty;
    for (int cty:q2) to[inx++]=cty;
    solve(ln,ln+q1.size()-1,lk,mid); solve(ln+q1.size(),rn,mid+1,rk);
    return;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>O[i];
    for (int i=1;i<=m;i++){
        stt[O[i]].push_back(i);
    }
    for (int i=1;i<=n;i++) cin>>P[i];
    cin>>k;
    for (int i=1;i<=k;i++){
        int l,r,a; cin>>l>>r>>a;
        if (l<=r) {R[i].l=l; R[i].r=r; R[i].a=a;}
        else {R[i].l=l; R[i].r=r+m; R[i].a=a;}
    }
    for (int i=1;i<=n;i++) to[i]=i;
    solve(1,n,1,k+1);
    for (int i=1;i<=n;i++){
        if (ans[i]==k+1) cout<<"NIE\n";
        else cout<<ans[i]<<'\n';
    }
    return 0;   
}