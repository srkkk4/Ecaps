#include <bits/stdc++.h>
#define MAXN 100003
#define inf 1000000003
#define minn -1000000100
using namespace std;
int T;
int n,K;
int a[MAXN];
vector <int> q[MAXN];
int main(){
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n>>K;
        for (int i=1;i<=n;i++){
            char ch=getchar(); while (!(ch=='?'||ch=='-'||(ch>='0'&&ch<='9'))) {ch=getchar();}
            if (ch=='?'){
                a[i]=-inf;
            } else {
                int tmp=0;
                if (ch=='-'){
                    cin>>tmp;
                    // cout<<">:"<<tmp<<'\n';
                    a[i]=-tmp;
                } else {
                    tmp=int(ch-'0');
                    char ch2=getchar(); while (ch2>='0'&&ch2<='9') {tmp=tmp*10+(ch2-'0'); ch2=getchar();}
                    a[i]=tmp;
                }
            }
        }
        // for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        // cout<<endl;
        int flag=0;
        for (int i=1;i<=K;i++){
            q[i].clear();
            q[i].push_back(minn);
            for (int j=i;j<=n;j+=K){
                q[i].push_back(a[j]);
            }
            q[i].push_back(-minn);
            int sz=q[i].size(); int l=0;
            // cerr<<">:";
            // for (int j=0;j<=sz-1;j++) cerr<<q[i][j]<<" ";
            // cerr<<'\n';
            for (int j=1;j<=sz-1;j++){
                int cnt=0;
                while (q[i][j]==-inf&&j<=sz-2) {j++; cnt++;}
                // cerr<<j<<" ";
                if (q[i][j]-q[i][l]-1>=cnt){
                    if (q[i][l]<=0&&q[i][j]<=0){
                        for (int k=j-1,num=q[i][j]-1;k>=l+1;k--,num--) q[i][k]=num;
                    } else if (q[i][l]<0&&q[i][j]>0){
                        int num=min(q[i][j]-cnt,max(q[i][l]+1,-(cnt/2)));
                        for (int k=l+1;k<=j-1;k++,num++) q[i][k]=num;
                    } else if (q[i][j]>=0&&q[i][j]>=0){
                        for (int k=l+1,num=q[i][l]+1;k<=j-1;k++,num++) q[i][k]=num;
                    }
                } else {
                    cout<<"Incorrect sequence\n";
                    flag=1;
                    break;
                }
                // cerr<<'\n';
                l=j;
            }
            if (flag) break;
            for (int j=1,k=i;j<=sz-2;j++,k+=K) a[k]=q[i][j];
        }
        if (flag) continue;
        for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<'\n';
    }
    return 0;
}