#include <bits/stdc++.h>
#define MAXN 300003
#define MAXM 1000003
#define mod 1000000007
#define int long long
using namespace std;
int n,m;
struct T{
    int num;
    int val;
    bool operator<(const T &b)const{
        return val<b.val;
    }
}a[MAXN];
long long tree[MAXM<<2],tag[MAXM<<2];
void pushup(int x){
    tree[x]=(tree[x<<1]+tree[x<<1|1])%mod;
    return;
}
void pushdown(int x,int l,int r,int mid){
    if (!tag[x]) return;
    tag[x<<1]=(tag[x<<1]+tag[x])%mod;
    tag[x<<1|1]=(tag[x<<1|1]+tag[x])%mod;
    tree[x<<1]=(tree[x<<1]+tag[x]*(mid-l+1)%mod)%mod;
    tree[x<<1|1]=(tree[x<<1|1]+tag[x]*(r-mid)%mod)%mod;
    tag[x]=0;
    return;
}
void add(int tr,int l,int r,int x,int y,long long z){
    if (x<=l&&r<=y){
        tree[tr]=(tree[tr]+z*(r-l+1)%mod)%mod;
        tag[tr]=(tag[tr]+z)%mod;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(tr,l,r,mid);
    if (x<=mid) add(tr<<1,l,mid,x,y,z);
    if (y>mid) add(tr<<1|1,mid+1,r,x,y,z);
    pushup(tr);
    return;
}
long long query(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[tr];
    }
    int mid=(l+r)>>1; long long res=0;
    pushdown(tr,l,r,mid);
    if (x<=mid) res=(res+query(tr<<1,l,mid,x,y))%mod;
    if (y>mid) res=(res+query(tr<<1|1,mid+1,r,x,y))%mod;
    return res;
}
signed main(){
    // freopen("sample4.in","r",stdin);
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].val;
    }
    sort(a+1,a+1+n);
    int inx=0;
    long long ans=0;
    // bool flag=0;
    for (int i=1;i<=n;i++){
        int K=a[i].num/m,w=a[i].num%m;
        // if (w==0) {cerr<<a[i].num<<" "<<m<<endl; flag=1;}
        long long time=query(1,1,m,1,m);
        // cout<<K<<" "<<w<<" "<<inx<<" ";
        ans=(ans+time*K%mod)%mod;
        if (K>=1) ans=(ans+1ll*(1+K-1)*(K-1)/2%mod*a[i].val%mod*m%mod)%mod;
        if (inx<m&&w!=0){
            time=query(1,1,m,inx+1,min(inx+w,m));
            ans=(ans+time)%mod;
            ans=(ans+1ll*K*a[i].val%mod*(min(inx+w,m)-inx)%mod)%mod;
        }
        if (inx+w>m){
            time=query(1,1,m,1,inx+w-m);
            ans=(ans+time)%mod;
            ans=(ans+1ll*K*a[i].val%mod*(inx+w-m)%mod)%mod;
        }

        add(1,1,m,1,m,1ll*K*a[i].val%mod);
        // cout<<query(1,1,m,1,m)<<" ";
        if (inx<m&&w!=0) {/*cout<<"ok "<<inx+1<<" "<<min(inx+w,m)<<" | ";*/ add(1,1,m,inx+1,min(inx+w,m),a[i].val);}
        if (inx+w>m){
            add(1,1,m,1,inx+w-m,a[i].val);
        }
        // cout<<query(1,1,m,1,m)<<endl;
        inx=(inx+w-1)%m+1;
    }
    // if (flag) cerr<<"NB\n";
    cout<<ans%mod<<endl;
    return 0;
}