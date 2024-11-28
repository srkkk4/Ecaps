#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
const int T=100001;
const int F=-100001;
const int U=0;
int id,t;
int n,m;
int fa[MAXN];
void inFa(int x){
    for (int i=1;i<=x;i++) fa[i]=i;
    return;
}
int ton[MAXN*2];
int find(int x){
    if (x==F||x==T) return x;
    else if (ton[-x+n]||x==U) return U; //ton[-x+n]判断与其冲突的值是否早已存在
    else if (ton[x+n]) return T;
    else {
        if (x>0){
            if (x==fa[x]) return x;
            else {
                ton[x+n]=1;
                int res=fa[x]=find(fa[x]);
                ton[x+n]=0;
                return res;
            }
        } else {
            if (-x==fa[-x]) return x; //终止find()
            else {
                ton[x+n]=1;
                int res=fa[-x]=find(-fa[-x]);
                ton[x+n]=0;
                return res;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>id>>t;
    while (t--){
        cin>>n>>m;
        inFa(n);
        for (int i=1;i<=m;i++){
            char type; cin>>type;
            if (type=='T'){
                int x; cin>>x;
                fa[x]=T;
            } else if (type=='F'){
                int x; cin>>x;
                fa[x]=F;
            } else if (type=='U'){
                int x; cin>>x;
                fa[x]=U;
            } else {
                int x,y; cin>>x>>y;
                if (type=='+') fa[x]=fa[y];
                else fa[x]=-fa[y];
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++){
            if (find(i)==U) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}