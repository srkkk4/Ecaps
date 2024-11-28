#include <bits/stdc++.h>
#define MAXN 1000003
using namespace std;
int n;
int a[MAXN];
struct shoe{
    int size;
    int p;
};
vector <shoe> s[MAXN];
int b[MAXN];
int t[MAXN];
int lowbit(int x){
    return x&-x;
}
void add(int x,int y){
    for (int p=x;p<=n*2;p+=lowbit(p)){
        t[p]+=y;
    }
    return;
}
int sum(int x){
    if (x==0) return 0;
    int res=0;
    for (int p=x;p>=1;p-=lowbit(p)){
        res+=t[p];
    }
    return res;
}
int vis[MAXN];
int main(){
    cin>>n;
    for (int i=1;i<=n*2;i++){
        cin>>a[i];
        s[abs(a[i])].push_back({a[i],i});
    }
    long long ans=0;
    for (int i=1;i<=n;i++){
        if (!s[i].size()) continue;
        queue <shoe> q;
        for (vector<shoe>::iterator pos=s[i].end()-1;pos!=s[i].begin()-1;pos--){
            shoe now=*pos;
            if (q.empty()) q.push(now);
            else {
                shoe last=q.front();
                if (last.size!=now.size){
                    b[now.p]=last.p;
                    q.pop();
                } else {
                    q.push(now);
                }
            }
        }
    }
    for (int i=1;i<=n*2;i++) add(i,1);
    for (int i=1;i<=n*2;i++){
        if (vis[i]) continue;
        vis[i]=vis[b[i]]=1;
        ans+=sum(b[i]-1)-sum(i);
        if (a[i]>0&&a[b[i]]<0) ans++;
        add(i,-1); add(b[i],-1);
    }
    cout<<ans<<endl;
    return 0;
}