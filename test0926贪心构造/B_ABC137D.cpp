#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,m;
struct work{
    int A,B;
    bool operator<(const work &b)const{
        if (A==b.A){
            return B<b.B;
        } else {
            return A>b.A;
        }
    }
}a[MAXN];
struct work2{
    int A,B;
    bool operator<(const work2 &b)const{
        if (B==b.B) return A<b.A;
        return B>b.B;
    }
};
priority_queue<work2>q;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i].A>>a[i].B;
    }
    sort(a+1,a+1+n);
    int sum=0,ans=0;
    for (int i=1;i<=n;i++){
        if(m-q.size()>=a[i].A){
            q.push({a[i].A,a[i].B});
            sum+=a[i].B;
            ans=max(sum,ans);
        } else if (q.size()){
            if(q.top().B>a[i].B) continue;
            sum-=q.top().B;
            q.pop();
            q.push({a[i].A,a[i].B});
            sum+=a[i].B;
            ans=max(sum,ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}