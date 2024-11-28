#include <bits/stdc++.h>
#define MAXN 503
#define inf 0x3f3f3f3f
using namespace std;
int n;
int dis[17][MAXN][MAXN];
vector <int> p[MAXN<<2];
void add(int tr,int l,int r,int x,int y,int z){
    if (x<=l&&r<=y){
        p[tr].push_back(z);
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) add(tr<<1,l,mid,x,y,z);
    if (y>mid) add(tr<<1|1,mid+1,r,x,y,z);
    return;
}
long long ans=0;
void query(int tr,int l,int r,int c){
    memcpy(dis[c],dis[c-1],sizeof dis[c-1]);
    for (int u:p[tr]){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dis[c][i][j]=min(dis[c][i][j],dis[c][i][u]+dis[c][u][j]);
            }
        }
    }
    if (l==r){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (dis[c][i][j]==inf) ans--;
                else ans+=dis[c][i][j];
            }
        }
        return;
    }
    int mid=(l+r)>>1;
    query(tr<<1,l,mid,c+1); query(tr<<1|1,mid+1,r,c+1);
    return;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int tmp; cin>>tmp;
            if (tmp==-1) dis[0][i][j]=inf;
            else dis[0][i][j]=tmp;
        }
    }
    for (int i=1;i<=n;i++){
        if (i>1) add(1,1,n,1,i-1,i);
        if (i<n) add(1,1,n,i+1,n,i);
    }
    query(1,1,n,1);
    cout<<ans<<endl;
    return 0;
}