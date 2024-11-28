#include <iostream>
#include <vector>
// #include <cstring>
#define MAXN 50001
#define pb push_back
using namespace std;
bool ST;
int n,m;
int cnt[MAXN<<2];
struct LRS{
    int l; int r;
};
vector <LRS> lrs[MAXN<<2];
vector <unsigned int> tree[MAXN<<2];
vector <int> tag[MAXN<<2];
void pushup(int inx,int x){
    int LS=lrs[inx][x].l, RS=lrs[inx][x].r;
    tree[inx][x]=tree[inx][LS]+tree[inx][RS];
    return;
}
void pushdown(int inx,int tr,int l,int r,int mid){
    if (!lrs[inx][tr].l){
        lrs[inx][tr].l=++cnt[inx]; lrs[inx].pb((LRS){0,0});
        tree[inx].pb(0); tag[inx].pb(0);
    }
    if (!lrs[inx][tr].r){
        lrs[inx][tr].r=++cnt[inx]; lrs[inx].pb((LRS){0,0});
        tree[inx].pb(0); tag[inx].pb(0);
    }
    if (!tag[inx][tr]) return;
    int LS=lrs[inx][tr].l, RS=lrs[inx][tr].r;
    tree[inx][LS]+=(mid-l+1)*tag[inx][tr]; tree[inx][RS]+=(r-mid)*tag[inx][tr];
    tag[inx][LS]+=tag[inx][tr]; tag[inx][RS]+=tag[inx][tr];
    tag[inx][tr]=0;
    return;
}
void add(int inx,int tr,int l,int r,int x,int y,int z){
    if (x<=l&&r<=y){
        tree[inx][tr]+=(r-l+1)*z;
        tag[inx][tr]+=z;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(inx,tr,l,r,mid);
    if (x<=mid) add(inx,lrs[inx][tr].l,l,mid,x,y,z);
    if (y>mid) add(inx,lrs[inx][tr].r,mid+1,r,x,y,z);
    pushup(inx,tr);
    return;
}
long long query(int inx,int tr,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[inx][tr];
    }
    int mid=(l+r)>>1;
    pushdown(inx,tr,l,r,mid); long long res=0;
    if (x<=mid) res+=query(inx,lrs[inx][tr].l,l,mid,x,y);
    if (y>mid) res+=query(inx,lrs[inx][tr].r,mid+1,r,x,y);
    return res;
}
void ADD(int inx,int l,int r,int x,int ql,int qr){
    if (l==r){
        add(inx,1,1,n,ql,qr,1);
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) ADD(inx<<1,l,mid,x,ql,qr);
    else ADD(inx<<1|1,mid+1,r,x,ql,qr);
    add(inx,1,1,n,ql,qr,1);
    return;
}
bool ED;
int main(){
    // freopen("P3332_10.in","r",stdin);
    // freopen("P3332_10.ans","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    // cerr<<abs(&ED-&ST)/1024.0/1024.0<<"MB\n";



    cin>>n>>m;
    if (n==1&&m==2) {cout<<-1<<'\n'; return 0;}
    for (int i=1;i<=n*4;i++){
        cnt[i]=1;
        lrs[i].pb((LRS){0,0}); lrs[i].pb((LRS){0,0});
        tree[i].pb(0); tree[i].pb(0);
        tag[i].pb(0); tag[i].pb(0);
    }
    for (int i=1;i<=m;i++){
        int type,l,r; long long c; cin>>type>>l>>r>>c;
        if (type==1){
            ADD(1,1,n,c,l,r);
        } else {
            long long mx=query(1,1,1,n,l,r);
            c=mx-c+1;
            int L=1,R=n; long long lf=0; int inx=1;
            while (L<R){
                int mid=(L+R)>>1;
                long long ylf=lf;
                lf+=query(inx<<1,1,1,n,l,r);
                if (lf<c){
                    inx=inx<<1|1; L=mid+1;
                } else {
                    lf=ylf;
                    inx=inx<<1; R=mid;
                }
            }
            cout<<R<<'\n';
        }
    }
    
    // FILE* fp = fopen("/proc/self/status", "r");
    // char line[128];
    // while (fgets(line, 128, fp) != NULL)
    // {
    //     if (strncmp(line, "VmRSS:", 6) == 0)
    //     {
    //         cerr<<"当前进程占用内存大小为"<<atoi(line + 6)/1024.0<<"MB\n";
    //         break;
    //     }
    // }
    // fclose(fp);

    return 0;
}