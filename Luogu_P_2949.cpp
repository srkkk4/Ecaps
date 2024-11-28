#include <bits/stdc++.h>
#define MAXN 100003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n;
struct TSK{
    int time; int val;
    bool operator <(const TSK &B)const{
        if (time==B.time) return val>B.val;
        else return time<B.time;
    }
}tsk[MAXN];
priority_queue <int,vector<int>,greater<int> > q;
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>tsk[i].time>>tsk[i].val;
    }
    sort(tsk+1,tsk+1+n);
    long long ans=0;
    for (int i=1,cnt=0;i<=n;i++){
        if (tsk[i].time>cnt){
            ans+=tsk[i].val; cnt++;
            q.push(tsk[i].val);
        } else {
            int now=q.top();
            if (now<tsk[i].val){
                ans-=now; ans+=tsk[i].val;
                q.pop(); q.push(tsk[i].val);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}