#include <bits/stdc++.h>
#define MAXN 1000003
using namespace std;
int n,m;
int a[MAXN];
struct Q{
    int l;
    int r;
    int id;
    int ans;
}q[MAXN];
bool cmp1(Q A,Q B){
    // if (A.r==B.r) return A.l<B.l; l可以无序
    return A.r<B.r;
}
bool cmp2(Q A,Q B){
    return A.id<B.id;
}
int vis[MAXN];
int t[MAXN];
int lowbit(int x){
    return x&-x;
}
int sum(int x){
    int res=0;
    for (int p=x;p>=1;p-=lowbit(p)){
        res+=t[p];
    }
    return res;
}
void add(int x,int y){
    for (int p=x;p<=MAXN-1;p+=lowbit(p)){
        t[p]+=y;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m;
    for (int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    std::sort(q+1,q+1+m,cmp1);
    for (int i=1,j=1;i<=n&&j<=m;i++){
        if (vis[a[i]]) add(vis[a[i]],-1);
        vis[a[i]]=i;
        add(i,1);
        while (q[j].r==i){
            q[j].ans=sum(q[j].r)-sum(q[j].l-1);
            j++;
        }
    }
    std::sort(q+1,q+1+m,cmp2);
    for (int i=1;i<=m;i++) cout<<q[i].ans<<endl;
    return 0;
}