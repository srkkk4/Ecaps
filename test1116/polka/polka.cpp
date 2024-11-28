#include <bits/stdc++.h>
#define MAXN 5000003
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 998244353
using namespace std;
bool ST;
int c,T;
int n;
int a[MAXN];
long long tree[MAXN<<2]; int tag[MAXN<<2]; long long t[MAXN<<2]; int cnt;
void pushup(int x){
    tree[x]=tree[x<<1]+tree[x<<1|1];
    return;
}
void pushdown(int x,int l,int r,int mid){
    if (!tag[x]) return;
    tree[x<<1]=1ll*(mid-l+1)*t[tag[x]];
    tree[x<<1|1]=1ll*(r-mid)*t[tag[x]];
    tag[x<<1]=max(tag[x<<1],tag[x]);
    tag[x<<1|1]=max(tag[x<<1|1],tag[x]);
    tag[x]=0;
    return;
}
void cover(int tr,int l,int r,int x,int y,int z){
    if (x<=l&&r<=y){
        tree[tr]=1ll*(r-l+1)*z;
        t[++cnt]=z;
        tag[tr]=cnt;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(tr,l,r,mid);
    if (x<=mid) cover(tr<<1,l,mid,x,y,z);
    if (y>mid) cover(tr<<1|1,mid+1,r,x,y,z);
    pushup(tr);
}
long long query(int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[tr];
    }
    int mid=(l+r)>>1; long long res=0;
    pushdown(tr,l,r,mid);
    if (x<=mid) res=res+query(tr<<1,l,mid,x,y);
    if (y>mid) res=res+query(tr<<1|1,mid+1,r,x,y);
    return res;
}
struct C{
    int s;
    int val;
}cov[MAXN]; int cntcov;
void clear(){
    cnt=0; cntcov=0;
    for (int i=1;i<=4*n;i++){
        tree[i]=-inf;
        tag[i]=0;
    }
    return;
}
bool ED;
int main(){
    // freopen("sample1.in","r",stdin);
    freopen("polka.in","r",stdin);
    freopen("polka.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // cerr<<(&ED-&ST)/1024.0/1024.0<<"MB\n";
    cin>>c>>T;
    while (T--){
        cin>>n;
        clear();
        for (int i=1;i<=n;i++) cin>>a[i];
        long long ans=0;
        cov[++cntcov]={1,a[1]};
        for (int i=2;i<=n;i++){
            // cerr<<"i="<<i<<":\n";
            // cerr<<"max2:";
            // for (int i=1;i<=n;i++) cerr<<query(1,1,n,i,i)<<" ";
            // cerr<<'\n';
            int l=1,r=i-1,res;
            while (l<=r){
                int mid=(l+r)>>1;
                if (a[i]>=query(1,1,n,mid,mid)) r=mid-1;
                else l=mid+1;
            }
            // cerr<<l<<'\n';
            res=l;
            // cerr<<res<<" "<<i-1<<'\n';
            if (res<=i-1) cover(1,1,n,res,i-1,a[i]);

            l=1,r=cntcov;
            while (l<=r){
                int mid=(l+r)>>1;
                if (a[i]>=cov[mid].val) r=mid-1;
                else l=mid+1;
            }
            // cerr<<l<<'\n';
            res=l;
            for (int j=res;j<=cntcov;j++){
                if (j<cntcov) cover(1,1,n,cov[j].s,cov[j+1].s-1,cov[j].val);
                else cover(1,1,n,cov[j].s,i-1,cov[j].val);
            }
            // cerr<<"max2:";
            // for (int i=1;i<=n;i++) cerr<<query(1,1,n,i,i)<<" ";
            // cerr<<'\n';
            ans=(ans+query(1,1,n,1,i-1)%mod+mod)%mod;
            if (res==cntcov+1){
                cov[++cntcov]={i,a[i]};
            } else {
                cntcov=res;
                cov[cntcov]={cov[cntcov].s,a[i]};
            }
            // for (int i=1;i<=cntcov;i++){
            //     cerr<<">:"<<cov[i].s<<" "<<cov[i].val<<'\n';
            // }
        }
        cout<<ans<<'\n';
    }
    return 0;
}