#include <bits/stdc++.h>
#define MAXN 500003
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,q;
int fa[MAXN];
struct line{
    int l; int r; int c;
}L[MAXN];
int cnt[MAXN];
int find(int x) {while (fa[x]!=x) x=fa[x]=fa[fa[x]]; return x;}
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        fa[i]=i;
        L[i].l=L[i].r=i=L[i].c=i;
        cnt[i]=1;
    }
    while (q--){
        int type; cin>>type;
        if (type==1){
            int x; int c; cin>>x>>c;
            int fax=find(x);
            cnt[L[fax].c]-=L[fax].r-L[fax].l+1;
            L[fax].c=c;
            cnt[L[fax].c]+=L[fax].r-L[fax].l+1;
            if (L[fax].l>1){
                int fal=find(L[fax].l-1);
                if (L[fal].c==c){
                    fa[fal]=fax;
                    L[fax].l=L[fal].l;
                }
            }
            if (L[fax].r<n){
                int far=find(L[fax].r+1);
                if (L[far].c==c){
                    fa[far]=fax;
                    L[fax].r=L[far].r;
                }
            }
        } else {
            int c; cin>>c;
            cout<<cnt[c]<<'\n';
        }
    }
    return 0;
}