#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int n,m,k;
struct node{
    int num;
    int id;
};
node nx[MAXN],ny[MAXN];
int tree[MAXN];
int lowbit(int x){
    return x&-x;
}
int SUM(int x){
    int res=0;
    for (int p=x;p>=1;p-=lowbit(p)){
        res+=tree[p];
    }
    return res;
}
void ADD(int x,int y,int tot){
    for (int p=x;p<=tot;p+=lowbit(p)){
        tree[p]+=y;
    }
    return;
}
bool cmp(node A,node B){
    if (A.num==B.num) return A.id>B.id;
    return A.num>B.num;
}
bool cmp2(node A,node B){
    return A.id<B.id;
}
int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) nx[i].num=n+1,nx[i].id=i;
    for (int i=1;i<=n;i++) ny[i].num=m+1,ny[i].id=i;
    for (int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        nx[y].num=min(nx[y].num,x);
        ny[x].num=min(ny[x].num,y);
    }
    long long ans=1;
    for (int i=2;i<=ny[1].num-1;i++){
        ans+=nx[i].num-1;
    }
    for (int i=2;i<=nx[1].num-1;i++){
        ans+=ny[i].num-1;
    }
    // for (int i=1;i<=m;i++) cout<<nx[i].num<<" ";
    // cout<<endl;
    // for (int i=1;i<=n;i++) cout<<ny[i].num<<" ";
    // cout<<endl;
    // cout<<ans<<endl;
    sort(nx+2,nx+1+m,cmp);
    for (int i=2;i<=m;i++){
        if (nx[i].id<ny[1].num) ADD(nx[i].id,1,m);
        // cout<<"nx[i].num:"<<nx[i].num<<" "<<nx[i+1].num<<endl;
        for (int j=nx[i].num;j>=nx[i+1].num+1&&j>=2;j--){
            // cout<<j<<" "<<SUM(ny[j].num-1)<<endl;
            if (j>=nx[1].num) continue;
            ans-=SUM(ny[j].num-1);
        }
    }
    sort(nx+2,nx+1+m,cmp2);
    // memset(tree,0,sizeof tree);
    // sort(ny+2,ny+1+n,cmp);
    // for (int i=2;i<=n;i++){
    //     if (ny[i].id>=nx[1].num) continue;
    //     ADD(ny[i].id,1,n);
    //     for (int j=ny[i].num;j>=ny[i+1].num+1&&j>=2;j--)
    //         ans-=SUM(nx[j].num-1);
    // }
    // sort(ny+2,ny+1+n,cmp2);
    cout<<ans<<endl;
    return 0;
}