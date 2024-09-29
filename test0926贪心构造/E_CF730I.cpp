//https://www.luogu.com.cn/article/xyilo2dv
#include <bits/stdc++.h>
#define MAXN 3003
using namespace std;
int n,x,y;
struct person{
    int a;
    int b;
    int id;
}p[MAXN];
struct person1{
    int val;
    int id;
    bool operator<(const person1 &B)const{
        return val<B.val;
    }
};
int vis[MAXN];
bool vis1[MAXN],vis2[MAXN];
int main(){
    cin>>n>>x>>y;
    for (int i=1;i<=n;i++) cin>>p[i].a;
    for (int i=1;i<=n;i++) cin>>p[i].b;
    for (int i=1;i<=n;i++) p[i].id=i;
    int ans=0;
    priority_queue <person1> q1,q2,q3;
    for (int i=1;i<=n;i++) q1.push({p[i].a,i});
    for (int i=1;i<=n;i++) q2.push({p[i].b,i});
    // for (int i=1;i<=n;i++) q3.push({p[i].b-p[i].a,i});
    for (int i=1;i<=x;i++){
        ans+=q1.top().val; vis[q1.top().id]=1;
        q3.push({p[q1.top().id].b-p[q1.top().id].a,q1.top().id});
        vis1[q1.top().id]=1;
        q1.pop();
    }
    for (int i=1;i<=y;i++){
        while (vis[q2.top().id]) q2.pop();
        while (vis[q1.top().id]) q1.pop();
        person1 now1=q1.top(),now2=q2.top(),now3=q3.top();
        if (now2.val>now3.val+now1.val){
            ans+=now2.val;
            vis[now2.id]=1;
            vis2[now2.id]=1;
            q2.pop();
        } else {
            ans+=now3.val+now1.val;
            vis[now1.id]=1;
            vis1[now3.id]=0; vis1[now1.id]=1; vis2[now3.id]=1;
            q3.push({p[now1.id].b-p[now1.id].a,now1.id});
            q3.pop(); q1.pop();
        }
    }
    cout<<ans<<endl;
    for (int i=1;i<=n;i++) if (vis1[i]) cout<<i<<" ";
    cout<<endl;
    for (int i=1;i<=n;i++) if (vis2[i]) cout<<i<<" ";
    cout<<endl;
    return 0;
}