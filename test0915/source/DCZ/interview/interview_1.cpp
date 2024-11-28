#include <bits/stdc++.h>
#define MAXN 300003
#define int long long
using namespace std;
int n,k;
int t[MAXN];
struct HR{
    long long time;
    int id;
    int to;
    bool operator<(const HR B)const{
        return time>B.time;
    }
};
priority_queue <HR> q; 
queue <HR> q2;
int q3[MAXN]; int cnt;
bool cmp(int a,int b) {return a>b;}
bool AC[MAXN];
HR q4[MAXN]; int cnt2;
bool cmp2(HR a,HR b) {return a.id<b.id;}
// vector <int> e[MAXN];
int find(int x){
    while (q4[x].to!=x) x=q4[x].to=q4[q4[x].to].to;
    return x;
}
signed main(){
    // freopen("interview.in","r",stdin);
    // freopen("interview.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>t[i];
    for (int i=1;i<=k;i++) q.push({t[i],i,i});
    for (int i=1;i<=k;i++) q4[++cnt2]={t[i],i,i};
    // cout<<q.top().time<<endl;
    int w=k;
    while (w+1<=n){
        // while (!q2.empty()) q2.pop();
        cnt=0;
        w++; q3[++cnt]=t[w];
        HR now=q.top(); q.pop();
        q2.push(now);
        int cnt3=1;
        while ((q.top().time==now.time)&&(cnt3<k)){
            cnt3++;
            w++; q3[++cnt]=t[w];
            now=q.top(); q.pop();
            q2.push(now);
        }
        sort(q3+1,q3+1+cnt,cmp);
        // for (int i=1;i<=cnt;i++) cout<<q3[i]<<" "; cout<<endl;
        int id=q2.front().id;
        while (!q2.empty()){
            HR tmp=q2.front(); q2.pop();
            if (tmp.time+q3[cnt]<q4[find(tmp.id)].time) {q4[find(tmp.id)].to=id; q4[tmp.id].to=id; q4[tmp.id].time+=q3[cnt]; tmp.to=id; tmp.time+=q3[cnt];}
            else {q4[tmp.id].to=id; q4[tmp.id].time+=q3[cnt]; tmp.to=id; tmp.time+=q3[cnt];}
            cnt--;
            q.push(tmp);
        }
    }
    HR ac=q.top(); cout<<ac.time<<endl;
    // cout<<q4[find(1)].time<<endl;
    for (int i=1;i<=k;i++){
        if (q4[find(i)].time==ac.time){
            q4[find(i)].to=ac.id;
        }
    }
    // for (int i=1;i<=k;i++) cout<<q4[i].to<<" "; cout<<endl;
    for (int i=1;i<=k;i++){
        if (i==ac.id){
            AC[i]=1;
        }
    }
    for (int i=1;i<=k;i++) if (AC[i]) cout<<1; else cout<<0;
    cout<<endl;
    return 0;
}