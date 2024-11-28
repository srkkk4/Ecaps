#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int n,N,k;
struct E{
    int a,b,c;
    int id,w,ans;
};
E e[MAXN];
bool cmp1(E A,E B){
    if (A.a==B.a){
        if (A.b==B.b){
            return A.c<B.c;
        } else return A.b<B.b;
    } else return A.a<B.a;
    // return A.a<B.a;
}
bool cmp2(E A,E B){
    return A.b<B.b;
}
int t[MAXN];
int lowbit(int x){
    return x&-x;
}
int SUM(int x){
    int res=0;
    while (x>0){
        res+=t[x];
        x-=lowbit(x);
    }
    return res;
}
void ADD(int x,int y){
    while (x<=k){
        t[x]+=y;
        x+=lowbit(x);
    }
    return;
}
int cnt[MAXN];
void cdq(int l,int r){
    if (l==r) return;
    int mid=(l+r)>>1;
    cdq(l,mid); cdq(mid+1,r);
    sort(e+l,e+mid+1,cmp2); sort(e+mid+1,e+r+1,cmp2);
    // cout<<l<<" "<<r<<"-----------------\n";
    // for (int i=1;i<=N;i++) printf("%d ",e[i].a); cout<<endl;
    // for (int i=1;i<=N;i++) printf("%d ",e[i].b); cout<<endl;
    // for (int i=1;i<=N;i++) printf("%d ",e[i].c); cout<<endl;
    int i=l;
    for (int j=mid+1;j<=r;j++){
        while (e[i].b<=e[j].b&&i<=mid){
            // if (e[i].a==e[j].a&&e[i].b==e[j].b&&e[i].c==e[j].c){
                // cout<<"ok "<<i<<" "<<j<<endl;
                // cnt[e[i].id]++;
            // }
            ADD(e[i].c,e[i].w);
            i++;
        }
        e[j].ans+=SUM(e[j].c);
        // cout<<"t[e[j].c]:"<<SUM(e[j].c)-SUM(e[j].c-1)<<endl;
    }
    i--;
    for (;i>=l;i--) ADD(e[i].c,-e[i].w);
    return;
}
int ans[MAXN];
E tmp[MAXN];
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        scanf("%d %d %d",&tmp[i].a,&tmp[i].b,&tmp[i].c);
        tmp[i].id=i;
    }
    sort(tmp+1,tmp+1+n,cmp1);
    int w=0;
    for (int i=1;i<=n;i++){
        w++;
        if (tmp[i].a!=tmp[i+1].a||tmp[i].b!=tmp[i+1].b||tmp[i].c!=tmp[i+1].c){
            N++;
            e[N]=tmp[i];
            e[N].id=N;
            e[N].w=w;
            e[N].ans=w-1;
            w=0;
        }
    }
    cdq(1,N);
    for (int i=1;i<=N;i++){
        ans[e[i].ans]+=e[i].w;
        // printf("%d ",e[i].ans);
    }
    // cout<<endl;
    for (int i=0;i<=n-1;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}