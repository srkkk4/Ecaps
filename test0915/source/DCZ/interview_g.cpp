//Bitset: https://blog.csdn.net/haokan123456789/article/details/138976064
#include <bits/stdc++.h>
#define MAXN 300003
using namespace std;
int n,k;
int a[MAXN];
struct HR{
    long long time;
    int id;
    bool operator<(const HR &b)const {
        return time > b.time;
    } 
};
priority_queue <HR> q; 
vector <bitset<MAXN>> eve; 
signed main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=k;i++) q.push({a[i],i});
    int w=k;
    while (w<=n){
        HR now = q.top(); long long t = q.top().time;
        q.pop();
        q.push({t+a[++w],now.id});
        if (q.top().time == t && w <= n){
            eve.emplace_back();
            eve.back().set(now.id); //第now.id位设置为1
        }
        while (q.top().time == t && w <= n){
            now = q.top();
            q.pop();
            q.push({now.time+a[++w],now.id});
            eve.back().set(now.id);
        }
    }
    int x = q.top().id; long long t = q.top().time;
    cout<<t<<endl;
    reverse(eve.begin(),eve.end()); //翻转
    bitset<MAXN> ans; ans.set(x);
    for (const bitset<MAXN> i : eve) if ((ans & i).any()) ans|=i;
    for (int i=1;i<=k;i++) cout<<ans[i];
    cout<<endl;
    return 0;
}