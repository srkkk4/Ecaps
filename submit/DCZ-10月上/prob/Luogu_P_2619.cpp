#include <bits/stdc++.h>
#define MAXV 50003
#define MAXE 100003
using namespace std;
int V,E,need;
struct egde{
    int s,t,val,col;
    bool operator<(const egde &b)const{
        if (val==b.val) return col<b.col;
        else return val<b.val;
    }
}e[MAXE];
int temp,sum;
int f[MAXV];
int find(int x){
    while (x!=f[x]) x=f[x]=f[f[x]];
    return x;
}
void kruskal(){
    sort(e+1,e+1+E);
    for (int i=1,cnt=1;i<=E&&cnt<=V-1;i++){
        int fs=find(e[i].s),ft=find(e[i].t);
        if (fs!=ft){
            cnt++;
            f[fs]=ft;
            sum+=e[i].val;
            if (e[i].col==0){
                temp++;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>V>>E>>need;
    for (int i=1;i<=E;i++){
        cin>>e[i].s>>e[i].t>>e[i].val>>e[i].col;
        e[i].s++; e[i].t++;
    }
    int l=-114,r=114;
    int ans=0;
    while (l<r){
        int mid=(l+r)>>1;
        for (int i=1;i<=E;i++){
            if (e[i].col==0){
                e[i].val+=mid;
            }
        }
        for (int i=1;i<=V;i++) f[i]=i;
        temp=0; sum=0;
        kruskal();
        if (temp>=need){
            l=mid+1;
            ans=sum-mid*need;
        } else {
            r=mid;
        }
        for (int i=1;i<=E;i++){
            if (e[i].col==0){
                e[i].val-=mid;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}