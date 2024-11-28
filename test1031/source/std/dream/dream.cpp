//Mashiro
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5002;
const int mod = 1e9 + 7;

int c, n, m, Q, l, r;
int a[MAXN<<1], f[MAXN][MAXN], ans[MAXN][MAXN], sum[MAXN];

inline int getsum(int l, int r){
	if(1<=l && l<=r && r<=n) return (sum[r]-sum[l-1]+mod)%mod;
	if(l>n) return (sum[r-n]-sum[l-n-1]+mod)%mod;
	if(r>n) return ((sum[n]-sum[l-1]+mod)%mod+sum[r-n])%mod;
	if(r<1) return (sum[r+n]-sum[l+n-1]+mod)%mod;
	if(l<1) return ((sum[n]-sum[l+n-1]+mod)%mod+sum[r])%mod;
	return -1;
}

signed main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	cin >> c >> n >> m >> Q; f[0][1]=1;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=m;++i){
		int o=i&1;
		for(int j=1;j<=n;++j) sum[j]=(sum[j-1]+f[i-1][j])%mod;
		cin >> l >> r;
		if(o) for(int j=1;j<=n;++j) f[i][j]=getsum(j-r+1,j-l+1);
		else for(int j=1;j<=n;++j) f[i][j]=getsum(j+l-1,j+r-1);
	}
	if(m&1){
		reverse(a+1,a+1+n);
		for(int i=n+1;i<=n<<1;++i) a[i]=a[i-n];
		for(int i=1;i<=n;++i)
			for(int j=i, k=1;j<=i+n-1;++j, ++k) (ans[k][a[j]]+=f[m][n-i+1])%=mod; 	
	}
	else{
		for(int i=n+1;i<=n<<1;++i) a[i]=a[i-n];
		for(int i=1;i<=n;++i)
			for(int j=i, k=1;j<=i+n-1;++j, ++k) (ans[k][a[j]]+=f[m][i])%=mod;
	}
	while(Q--){
		int p, v;
		cin >> p >> v;
		cout << ans[p][v] << '\n';	
	}
	return 0;
}

































































