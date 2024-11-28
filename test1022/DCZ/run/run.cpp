#include <bits/stdc++.h>
#define MAXN 5003
using namespace std;
int n,m;
bool a[MAXN][MAXN];
int up[MAXN][MAXN];
struct line{
    int pos,pos2;
    int high;
};
line q[MAXN];
int cnt;
int ans[MAXN*2];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char ch; cin>>ch;
            if (ch=='#') a[i][j]=1;
        }
    }
    for (int j=1;j<=m;j++){
        int last=0;
        for (int i=1;i<=n;i++){
            if (a[i][j]) last=i;
            up[i][j]=last;
        }
    }
    for (int i=1;i<=n;i++){
        cnt=0; q[0].pos=20000; q[0].pos2=0; q[0].high=-1;
        for (int j=1;j<=m;j++){
            if (a[i][j]){
                cnt=0; q[0].pos=20000; q[0].pos2=j; q[0].high=-1;
                // cout<<setw(3)<<0;
                continue;
            }
            int high=i-up[i][j];
            while (high<=q[cnt].high){
                cnt--;
            }
            // if (a[i][j]) cout<<cnt<<endl;
            if (high-(q[cnt].pos2+1)>q[cnt].high-q[cnt].pos){
                // if (i==46&&j==23) cerr<<"ok\n";
                cnt++; q[cnt].pos=q[cnt-1].pos2+1; q[cnt].high=high;
            }
            q[cnt].pos2=j;
            // if (i==46&&j==27){
            //     cerr<<q[cnt].pos<<" "<<q[cnt].pos2<<" "<<q[cnt].high<<endl;
            // }
            ans[q[cnt].high+j-q[cnt].pos+1]++;
            // cout<<setw(3)<<q[cnt].high+j-q[cnt].pos+1;
        }
        // cout<<endl;
    }
    for (int i=1;i<=n+m;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
/*
2 3 0 2 0 0 
3 0 2 3 4 5 
0 2 3 0 0 3 
2 3 4 0 2 4 
0 4 5 4 4 4 
0 5 6 0 4 6 
*/