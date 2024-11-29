#include <bits/stdc++.h>
#define MAXN 3003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,m;
char a[MAXN];
char b[MAXN];
struct S{
	int val;
	int p;
};
S dp[MAXN][MAXN];
bool ED;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a+1; n=strlen(a+1);
	cin>>b+1; m=strlen(b+1);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i]==b[j]) {dp[i][j].val=dp[i-1][j-1].val+1; dp[i][j].p=2; continue;}
			dp[i][j].val=max(dp[i-1][j].val,dp[i][j-1].val);
			if (dp[i-1][j].val>=dp[i][j-1].val){
				dp[i][j].p=0;
			} else {
				dp[i][j].p=1;
			}
		}
	}
	int ni=n,nj=m;
	char ans[MAXN]; int cnt=0;
	while (ni&&nj){
		if (a[ni]==b[nj]) {ans[++cnt]=a[ni];}
		if (dp[ni][nj].p==0) ni--;
		else if (dp[ni][nj].p==1) nj--;
		else {ni--; nj--;}
	}
	for (int i=cnt;i>=1;i--) cout<<ans[i];
	cout<<'\n';
	return 0;
}