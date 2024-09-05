#include <bits/stdc++.h>
#define MAXN 500003
using namespace std;
/* FIO */
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
/* FIO */
int n,m;
int a[MAXN];
int tot=0; int root[MAXN];
int lson[MAXN<<5],rson[MAXN<<5],sum[MAXN<<5];
int build(int l,int r){
    int rt=++tot;
    sum[rt]=0;
    if (l<r){
        int mid=(l+r)>>1;
        lson[rt]=build(l,mid);
        rson[rt]=build(mid+1,r);
    }
    return rt;
}
int update(int p,int l,int r,int x){
    int rt=++tot;
    sum[rt]=sum[p]+1;
    if (l<r){
        int mid=(l+r)>>1;
        if (x>mid) {lson[rt]=lson[p]; rson[rt]=update(rson[p],mid+1,r,x);}
        else       {rson[rt]=rson[p]; lson[rt]=update(lson[p],l,mid,x);}
    }
    return rt;
}
struct RES{
    int val;
    int num;
};
RES query(int u,int v,int l,int r,int x){
    if (l==r){
        return (RES){sum[v]-sum[u],l};
    }
    int mid=(l+r)>>1;
    RES Lres={0,0},Rres={0,0};
    if (2*(sum[lson[v]]-sum[lson[u]])>x) Lres=query(lson[u],lson[v],l,mid,x);
    if (2*(sum[rson[v]]-sum[rson[u]])>x) Rres=query(rson[u],rson[v],mid+1,r,x);
    if (Lres.val>Rres.val) return Lres;
    else                   return Rres;
}
int main(){
    n=read(); m=read();
    root[0]=build(1,n);
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++){
        root[i]=update(root[i-1],1,n,a[i]);
    }
    for (int i=1;i<=m;i++){
        int l,r;
        l=read(); r=read();
        RES res=query(root[l-1],root[r],1,n,r-l+1);
        write(res.num);
        putchar('\n');
    }
    return 0;
}