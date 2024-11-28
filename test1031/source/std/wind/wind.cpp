//Mashiro
#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int MAXN = 8005;
const int mod = 998244353;

int c, n, fac[MAXN], ifac[MAXN], C[MAXN][MAXN];
int v[MAXN], f[MAXN][2], g[MAXN][2], *F[MAXN], ans[MAXN], dp[MAXN][3], las[MAXN][3];

inline void add(int &x, int y){x+=y-mod; x+=(x>>31)&mod;}

inline ll Quickpow(ll x, ll y){
	ll z=1;
	while(y){
		if(y&1) z=z*x%mod;
		x=x*x%mod; y>>=1;
	}
	return z;
}

inline void prework(){
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;	
	}
	return ;
}

inline void work(){
	for(int i=0;i<n;++i){
		add(f[i+1][0],(f[i][0]+f[i][1])%mod);
		add(f[i+1][1],((ll)f[i][0]+2*f[i][1]%mod));
		add(g[i][0],(f[i][0]+f[i][1])%mod);
	}
	return ;	
}

inline int solve(){ // solve i=1
	las[0][0]=1;	
	for(int i=1;i<n;++i){
		for(int j=0;j<i;++j){
			// las[j][0]
			add(dp[j][0],las[j][0]);
			add(dp[j+1][1],las[j][0]);
			// las[j][1]
			add(dp[j][0],las[j][1]);
			if(j) add(dp[j-1][2],las[j][1]);
			add(dp[j+1][1],las[j][1]);
			// las[j][2]
			add(dp[j][0],las[j][2]);
			add(dp[j][2],las[j][2]);
			add(dp[j+1][1],las[j][2]);
		}
		memcpy(las,dp,sizeof dp);
		memset(dp,0,sizeof dp);
	}
	int ans=0;
	for(int i=0;i<=n;++i) (ans+=1ll*v[i]*((ll)las[i][0]+las[i][1]+las[i][2])%mod)%=mod;
	return ans;
}

signed main(){
	freopen("wind.in","r",stdin);
	freopen("wind.out","w",stdout);
	cin >> c >> n; prework();
	for(int i=0;i<=n;++i) cin >> v[i];
	for(int i=2;i<n;++i){
		F[i]=new int [n/i+2];
		for(int j=0;j<n/i+1;++j) F[i][j]=0;	
	}
	f[0][0]=1; 
	for(int j=0;j<=n;++j){ // occ=i
		work();
		for(int i=2;i<n;++i){
			if(i*j>=n) break;	
			F[i][j]=(f[n-1-i*j][0]+f[n-1-i*j][1])%mod;
		}
		memcpy(f,g,sizeof g);
		memset(g,0,sizeof g);
	}
	if(n^1) cout << solve() << '\n';
	for(int i=2;i<n;++i){
		int lmt=n/i;
		for(int j=0;j<=lmt;++j){
			int now=mod-1;
			for(int k=j+1;k<=lmt;++k){
				add(F[i][j],1ll*now*C[k][j]%mod*F[i][k]%mod);
				now=mod-now;
			}
		}
		int ans=0;
		for(int j=0;j<=lmt;++j) (ans+=1ll*v[j]*F[i][j]%mod)%=mod;
		cout << ans << '\n';
	}
	return 0;
}



















































