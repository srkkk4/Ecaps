#include <bits/stdc++.h>
#define MAXN 3003
using namespace std;
int n;
char a[MAXN][MAXN];
bool is[MAXN][MAXN];
int ans;
void dfs(int x,int y,int res){
    // cout<<x<<" "<<y<<endl;
    if (x==n&&y==n){
        ans=max(ans,res);
        return;
    }
    if (a[x][y]=='X'&&a[x][y+1]=='Y'&&a[x][y+2]=='D'&&(!is[x][y])&&(!is[x][y+1])&&(!is[x][y+2])){
        is[x][y]=is[x][y+1]=is[x][y+2]=1;
        if (y<n) dfs(x,y+1,res+1);
        else dfs(x+1,1,res+1);
        is[x][y]=is[x][y+1]=is[x][y+2]=0;
    }
    if (a[x][y]=='X'&&a[x+1][y]=='Y'&&a[x+2][y]=='D'&&(!is[x][y])&&(!is[x+1][y])&&(!is[x+2][y])){
        // cout<<"ok\n";
        is[x][y]=is[x+1][y]=is[x+2][y]=1;
        if (y<n) dfs(x,y+1,res+1);
        else dfs(x+1,1,res+1);
        is[x][y]=is[x+1][y]=is[x+2][y]=1;
    }
    if (y<n) dfs(x,y+1,res);
    else dfs(x+1,1,res);
    return;
}
int dp[MAXN][3];
int main(){
    // freopen("data.in","r",stdin);
    // freopen("match8.in","r",stdin);
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if (0){
        dfs(1,1,0);
        cout<<ans<<endl;
        return 0;
    } else {
        for (int k=2;k<=2*n;k++){
            memset(dp,0,sizeof dp);
            int i,j;
            for (i=1,j=k-i;i<=n;i++,j--){
                if (j>n||j<1) continue;
                // cerr<<i<<" "<<j<<endl;
                dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
                dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
                if (a[i-1][j]=='X'&&a[i][j]=='Y'&&a[i+1][j]=='D') dp[i][1]+=1;
                dp[i][2]=max(dp[i-1][0],dp[i-1][2]);
                if (a[i][j-1]=='X'&&a[i][j]=='Y'&&a[i][j+1]=='D') dp[i][2]+=1;
            }
            ans+=max(max(dp[min(n,k-1)][0],dp[min(n,k-1)][1]),dp[min(n,k-1)][2]);
        }
        cout<<ans<<endl;
        return 0;
    }
    int ans1=0,ans2=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (a[i][j]=='X'){
                if (a[i][j+1]=='Y'&&a[i][j+2]=='D') ans1++;
                else {
                    if (a[i+1][j]=='Y'&&a[i+2][j]=='D'){
                        if ((!(a[i+1][j-1]=='X'&&a[i+1][j+1]=='D'))&&(!(a[i+2][j-2]=='X'&&a[i+2][j-1]=='Y'))){
                            ans1++;
                        }
                    }
                }
            }
        }
    }
    for (int j=1;j<=n;j++){
        for (int i=1;i<=n;i++){
            if (a[i][j]=='X'){
                if (a[i+1][j]=='Y'&&a[i+2][j]=='D') ans2++;
                else {
                    if (a[i][j+1]=='Y'&&a[i][j+2]=='D'){
                        if ((!(a[i-1][j+1]=='X'&&a[i+1][j+1]=='D'))&&(!(a[i-2][j+2]=='X'&&a[i-1][j+2]=='Y'))){
                            ans2++;
                        }
                    }
                }
            }
        }
    }
    cout<<max(ans1,ans2)<<endl;
    return 0;
}