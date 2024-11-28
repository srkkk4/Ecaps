#include <bits/stdc++.h>
#define MAXN 2000003
#define MAXM 3000003
#define ull unsigned long long
using namespace std;
int c;
int T;
int n,m;
ull Hash[MAXN<<2],tag[MAXN<<2];
const int b=127;
ull B[MAXM];
void init(){
    B[0]=1;
    for (int i=1;i<=MAXM-2;i++){
        B[i]=B[i-1]*b;
    }
    return;
}
void pushup(int x){
    Hash[x]=Hash[x<<1]+Hash[x<<1|1];
    return;
}
void pushdown(int x,int l,int r,int mid){
    if (!tag[x]) return;
    tag[x<<1]=tag[x<<1]+tag[x]; tag[x<<1|1]=tag[x<<1|1]+tag[x];
    Hash[x<<1]=Hash[x<<1]+tag[x];
    Hash[x<<1|1]=Hash[x<<1|1]+tag[x];
    tag[x]=0;
    return;
}
void modi(int tr,int l,int r,int x,int y,ull z){
    if (x<=l&&r<=y){
        Hash[tr]=Hash[tr]+z;
        tag[tr]=tag[tr]+z;
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) modi(tr<<1,l,mid,x,y,z);
    if (y>mid) modi(tr<<1|1,mid+1,r,x,y,z);
    return;
}
ull query(int tr,int l,int r,int x){
    if (l==r&&l==x){
        return Hash[tr];
    }
    int mid=(l+r)>>1; ull res;
    pushdown(tr,l,r,mid);
    if (x<=mid) res=query(tr<<1,l,mid,x);
    else res=query(tr<<1|1,mid+1,r,x);
    return res;
}
ull cha[MAXN];
ull h[MAXN];
int main(){
    // freopen("ex_set3.in","r",stdin);
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c;
    init();
    h[0]=-1;
    cin>>T;
    while (T--){
        cin>>n>>m;
        for (int i=1;i<=m;i++){
            int K; cin>>K;
            for (int j=1;j<=K;j++){
                int l,r; cin>>l>>r;
                cha[l]+=B[i];
                cha[r+1]-=B[i];
            }
        }
        ull now=0;
        for (int i=1;i<=n;i++){
            now+=cha[i];
            h[i]=now;
        }
        int ans=0;
        sort(h+1,h+1+n); h[n+1]=-1;
        for (int i=1;i<=n;i++){
            if (h[i-1]!=h[i]&&h[i]!=h[i+1]) ans++;
        }
        cout<<ans<<endl;
        for (int i=1;i<=n+1;i++){
            cha[i]=0;
            h[i]=0;
        }
    }
    return 0;
}
/*
0
1
3 2
1 1 3
1 1 2
*/