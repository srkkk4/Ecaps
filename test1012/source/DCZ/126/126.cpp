#include <bits/stdc++.h>
#define MAXN 300003
#define mod 1000000007
using namespace std;
int n;
long long a[MAXN];
long long w[MAXN];
long long sum[MAXN];
int main(){
	freopen("126.in","r",stdin);
	freopen("126.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>w[i];
	for (int i=1;i<=n;i++) sum[i]=(sum[i-1]+a[i])%mod;
	long long SUM=0,ans=0;
	for (int i=1;i<=n/2+((n%2)?1:0);i++){
		SUM=(SUM+(sum[n-i+1]-sum[i-1]+mod)%mod)%mod;
		ans=(ans+(SUM*w[i])%mod)%mod;
	}
	if (n%2) SUM=(SUM-a[n/2+1]+mod)%mod;
	for (int i=n/2;i>=1;i--){
		ans=(ans+(SUM*w[n-i+1])%mod)%mod;
		SUM=(SUM-(sum[n-i+1]-sum[i-1]+mod)%mod+mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}