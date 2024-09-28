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
        return val>B.val;
    }
};
int vis[MAXN];
int main(){
    cin>>n>>x>>y;
    for (int i=1;i<=n;i++) cin>>p[i].a;
    for (int i=1;i<=n;i++) cin>>p[i].b;
    for (int i=1;i<=n;i++) p[i].id=i;
    int ans=0;
    priority_queue <person1> q1,q2,q3;
    for (int i=1;i<=n;i++) q1.push({p[i].a,i});
    for (int i=1;i<=n;i++) q2.push({p[i].b,i});
    for (int i=1;i<=n;i++) q3.push({p[i].b-p[i].a,i});
    int ans=0;
    for (int i=1;i<=x;i++){
        ans+=q1.top().val; vis[q1.top().id]=1;
        q1.pop();
    }
    for (int i=1;i<=y;i++){
        person1 now2=q2.top(),now3=q3.top();

    }
    return 0;
}