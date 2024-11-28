#include <bits/stdc++.h>
#define MAXN 1000003
#define inf 1e18+3
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int m;
struct QUE{
    int type;
    int K;
}Q[MAXN];
struct PA{
    long long K;
    int id;
}P[MAXN];
bool cmp1(PA A,PA B){
    return A.K<B.K;
}
int cnt;
int t[MAXN];
int lowbit(int x) {return x&-x;}
void add(int x,int y){
    for (int p=x;p<=cnt;p+=lowbit(p)) t[p]+=y;
    return;
}
int sum(int x){
    int res=0;
    for (int p=x;p>=1;p-=lowbit(p)) res+=t[p];
    return res;
}
bool isc[MAXN];
bool iss[MAXN];
bool ED;
int main(){
    freopen("thread.in","r",stdin);
    freopen("thread.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // cerr<<(&ED-&ST)/1024.0/1024.0<<"MB\n";
    cin>>m;
    for (int i=1;i<=m;i++){
        cin>>Q[i].type>>P[i].K;
        P[i].id=i;
    }
    sort(P+1,P+1+m,cmp1);
    cnt=0; P[0].K=-inf; int zf=-1; bool z=0;
    for (int i=1;i<=m;i++){
        if (P[i-1].K!=P[i].K) cnt++;
        Q[P[i].id].K=cnt;
        if (P[i].K==0) {zf=cnt; z=1;}
        else if (P[i].K>=0&&P[i-1].K<0) zf=cnt;
    }
    if (zf==-1){
        if (P[m].K<0) zf=cnt+1;
        if (P[1].K>0) zf=0;
    }
    bool zero=0,p=0;
    for (int i=1;i<=m;i++){
        if (Q[i].type==1){
            add(Q[i].K,1); isc[Q[i].K]=1;
        } else if (Q[i].type==2){
            add(Q[i].K,1); iss[Q[i].K]=1;
        } else if (Q[i].type==3){
            if (Q[i].K<zf) p=!p;
            else if (z&&Q[i].K==zf) zero=1;
        } else {
            if (iss[Q[i].K]) {cout<<"!\n"; continue;}
            if (zero) {cout<<"=\n"; continue;}
            if (isc[Q[i].K]) {cout<<"=\n"; continue;}
            int suf=sum(cnt)-sum(Q[i].K);
            if (p){
                if (suf&1) cout<<">\n";
                else cout<<"<\n";
            } else {
                if (suf&1) cout<<"<\n";
                else cout<<">\n";
            }
        }
    }
    return 0;
}