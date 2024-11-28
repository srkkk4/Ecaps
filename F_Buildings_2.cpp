#include <bits/stdc++.h>
#define MAXN 200003
#define inf 0x3f3f3f3f
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,q;
int h[MAXN];
struct QUE{
    int l; int r;
    int id;
    bool operator <(const QUE &B)const{
        return l>B.l;
    }
}Q[MAXN];
int ans[MAXN];
struct BD{
    int p;
    int high;
}sta[MAXN]; int cnt;
struct QS{
    int R;
    int id;
};
vector <QS> qs[MAXN];
bool ED;
int main(){
    // freopen("data.in","r",stdin);
    // freopen("answer.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=q;i++) {cin>>Q[i].l>>Q[i].r; Q[i].id=i; qs[Q[i].l].pb((QS){Q[i].r,i});}
    sort(Q+1,Q+1+q); sta[0].high=inf;
    for (int i=n;i>=1;i--){
        for (QS R:qs[i]){
            int l=1,r=cnt;
            while (l<r){
                int mid=(l+r+1)>>1;
                if (sta[mid].p>R.R) l=mid;
                else r=mid-1;
            }
            if (sta[l].p<=R.R) ans[R.id]=0;
            else ans[R.id]=l;
        }
        while (sta[cnt].high<=h[i]) cnt--;
        sta[++cnt].p=i; sta[cnt].high=h[i];
    }
    for (int i=1;i<=q;i++) cout<<ans[i]<<'\n';
    return 0;
}