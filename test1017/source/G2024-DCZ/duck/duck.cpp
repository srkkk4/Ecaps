#include <bits/stdc++.h>
#define MAXN 5003
using namespace std;
int n,m;
int a[MAXN*2];
bool is_sub2=1;
int dp[MAXN][MAXN];
int main(){
	freopen("duck.in","r",stdin);
	freopen("duck.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*2;i++) {cin>>a[i]; if (a[i]!=0) is_sub2=0;}
	if (n==1){
		cout<<(a[1]+a[2])%m<<endl;
		return 0;
	}
	if (m==1){
		cout<<0<<endl;
		return 0;
	}
	if (is_sub2){
		cout<<0<<endl;
		return 0;
	}
	int ans=INT_MAX;
	for (int i=1;i<=n;i+=2){
		ans=min(ans,(a[i]+a[i+1])%m);
	}
	cout<<ans<<endl;
	return 0;
}