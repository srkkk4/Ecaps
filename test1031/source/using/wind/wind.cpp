#include<bits/stdc++.h>
using namespace std;
int read(){
	int x,c;
	while((c=getchar())<'0'||c>'9');
	x=c^48;
	while((c=getchar())>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48);
	return x;
}
typedef long long ll;
const ll mod=998244353;
ll Pow(ll x,ll y){
	ll s=1;
	while(y){
		if(y&1)s=s*x%mod;
		x=x*x%mod;y>>=1;
	}
	return s;
}
const int maxn=8020;
ll jc[maxn],nc[maxn];
int dp[maxn][maxn];
int n,tmp[maxn];ll a[maxn];
int main(){
	freopen("wind.in","r",stdin);
	freopen("wind.out","w",stdout);
	read();n=read();
	jc[0]=nc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
		nc[i]=Pow(jc[i],mod-2);
	}
	for(int i=0;i<=n;i++)
		a[i]=read();
	for(int i=0;i<=n;i++)
		for(int j=0;j<i;j++)
			a[i]=(a[i]-jc[i]*nc[j]%mod*nc[i-j]%mod*a[j]%mod+mod)%mod;
	for(int j=0;j<=n;j++){
		dp[0][j]=1;
		tmp[j]=1;
	}
	for(int k=1;k<n;k++)
		for(int j=0;j<=n;j++){
			dp[k][j]=(tmp[j]+dp[k-1][j])%mod;
			if(j>0)
				dp[k][j]=(dp[k][j]+dp[k][j-1])%mod;
			tmp[j]=(tmp[j]+dp[k][j])%mod;
		}
	ll ans;
	for(int i=1;i<n;i++){
		int m=(n-1)/i;ans=0;
		for(int j=0;j<=m;j++)
			ans=(ans+dp[n-1-j*i][j]*a[j])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
