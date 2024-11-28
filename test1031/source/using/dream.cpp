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
const ll mod=1000000007;
const int maxn=5020;
int di[maxn];
int l[maxn],r[maxn];
int len[maxn];
ll dp[2][maxn<<1];
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	read();
	int n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)
		di[read()]=i;
	for(int i=1;i<=m;i++){
		l[i]=read()+1;
		r[i]=read()+1;
		len[i]=r[i]-l[i]+1;
	}
	l[0]=1;r[0]=0;
	for(int i=m,d=1;i>=0;i--,d^=1)
		if(d==0){l[i]=-l[i];r[i]=-r[i];}
	int cnt=0;
	for(int i=1;i<=m;i++)
		cnt+=min(l[i],r[i]);
	cnt%=n;cnt+=n;cnt%=n;
	int fr=0,to=1;
	for(int i=1;i<n;i++)
		dp[fr][i]=0;
	dp[fr][0]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<n;j++)
			dp[fr][j]=(dp[fr][j]+dp[fr][j-1])%mod;
		dp[to][0]=0;
		for(int j=0;j<n;j++)
			dp[fr][j+n]=(dp[fr][j]+dp[fr][n-1])%mod;
		for(int j=0;j<n;j++)
			dp[to][j]=(dp[fr][j+n]-dp[fr][j+n-len[i]]+mod)%mod;
		swap(fr,to);
	}
	while(q--){
		int y=read(),x=read();
		x=(di[x]*l[0]+cnt+n)%n;
		y=(y-x+n)%n;
		printf("%lld\n",dp[fr][y]);
	}
	return 0;
}
