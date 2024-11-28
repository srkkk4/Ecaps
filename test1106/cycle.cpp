#include <bits/stdc++.h>
#define MAXN 2000003
#define MAXK 2000103
using namespace std;
int T;
int n,m;
vector <int> b;
int to[MAXN<<1][26];
struct lines{
    int l;
    int r;
    bool operator <(const lines &B)const{
        if (l==B.l) return r>B.r;
        else return l<B.l;
    }
}line[MAXK]; int cntl;
int main(){
    // freopen("ex_cycle2.in","r",stdin);
    freopen("cycle.in","r",stdin);
    freopen("cycle.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n>>m;
        cntl=0;
        for (int i=1;i<=m;i++){
            int cnt; cin>>cnt;
            for (int j=1;j<=cnt;j++){
                int tz; cin>>tz;
                b.push_back(tz);
            }
            for (int j=0;j<cnt-1;j++){
                line[++cntl].l=b[j]+1;
                line[cntl].r=b[j+1];
                line[++cntl].l=b[j]+n+1;
                line[cntl].r=b[j+1]+n;
            }
            line[++cntl].l=1,line[cntl].r=b[0];
            line[++cntl].l=b[cnt-1]+1,line[cntl].r=b[0]+n;
            line[++cntl].l=b[cnt-1]+n+1,line[cntl].r=n*2;
            b.clear();
        }
        sort(line+1,line+1+cntl);
        for (int i=1,j=1,l=0;i<=n*2;i++){
            while (j<=cntl&&line[j].l<=i) l=max(l,line[j++].r);
            to[i][0]=l;
        }
        for (int i=1;i<=20;i++){
            for (int j=1;j<=n*2;j++){
                to[j][i]=to[to[j][i-1]][i-1];
            }
        }
        for (int i=1;i<=n;i++){
            int s,t;
            int res=0;
            s=i+1,t=n+i;
            if (s==t){
                cout<<0<<" ";
                continue;
            }
            for (int j=20;j>=0;j--){
                if (to[s][j]<t){
                    s=to[s][j];
                    res+=(1<<j);
                }
            }
            s=to[s][0]; res++;
            if (s<t) cout<<-1<<" ";
            else cout<<res<<" ";
        }
        cout<<'\n';
        for (int i = 1; i <= cntl; i++) line[i].l = line[i].r = 0;
        // for (int i=0;i<=20;i++){
        //     for (int j=1;j<=n*2;j++){
        //         to[j][i]=0;
        //     }
        // }
    }
    return 0;
}