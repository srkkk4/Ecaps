#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=125,mod=998244353;
bool isprime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}
int qpow(int a,int b){
	int ans=1,base=a;
	while(b){
		if(b&1) ans=ans*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return ans;
}
int n,k,ans;

int g[MAXN][MAXN];
int gcd(int x,int y){
	if(!y) return x;
	if(x<=n&&y<=n){
		if(g[x][y]!=-1) return g[x][y];
		g[x][y]=g[y][x]=gcd(y,x%y);
	}
	return gcd(y,x%y);
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
int pw[MAXN],fac[MAXN],inv[MAXN],inv_fac[MAXN];
void init(){
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=inv_fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
		inv_fac[i]=inv_fac[i-1]*inv[i]%mod;
	}
}
vector<pair<int,int>> dp[MAXN],f[MAXN];//(lcm,val)
unordered_map<int,int> vis;
struct node{
	int lcm,sum,val;
	node(int a=0,int b=0,int c=0){lcm=a,sum=b,val=c;}
};
vector<node> stk;
void insert(node ins){
	int s=ins.sum,L=ins.lcm;
	if(dp[s].empty()){
		dp[s].push_back(make_pair(L,ins.val));
		return ;
	}

	int l=0,r=dp[s].size()-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(dp[s][mid].first>=L) r=mid;
		else l=mid+1;
	}
	if(dp[s][l].first==L) dp[s][l].second=(dp[s][l].second+ins.val)%mod;
	else{
		if(dp[s][l].first>=L) dp[s].insert(dp[s].begin()+l,make_pair(L,ins.val));
		else dp[s].push_back(make_pair(L,ins.val));
	}
}
signed main(){
	
	freopen("aporia.in","r",stdin);
	freopen("aporia.out","w",stdout);
	memset(g,-1,sizeof(g));
	cin>>n>>k;
	init();

	int B=2000;
	for(int v=1;v<=n;v++){//v表示目前枚举的权值
		pw[0]=1;
		for(int i=1;i<=n;i++) pw[i]=pw[i-1]*inv[v]%mod;
		for(int i=0;i<=n;i++) pw[i]=pw[i]*inv_fac[i]%mod;

		stk.clear();
		for(int s=0;s<=n;s++){
			for(auto tmp:dp[s]){
				int L=tmp.first,val=tmp.second,L2=lcm(L,v);
				for(int i=1;s+i*v<=n;i++){
					int f=val*pw[i]%mod;
					stk.push_back(node(L2,s+i*v,f));
					if(s+i*v==n){
						if(!vis[L2]) vis[L2]=qpow(L2,k);
						ans=(ans+f*fac[n]%mod*vis[L2])%mod;
					}
				}
			}
			if(s==0){
				for(int i=1;i*v<=n;i++){
					stk.push_back(node(v,i*v,pw[i]));
					if(i*v==n){
						if(!vis[v]) vis[v]=qpow(v,k);
						ans=(ans+pw[i]*fac[n]%mod*vis[v])%mod;
					}
				}
			}
		}
		
		if(!isprime(v)||stk.size()<=B){
			for(auto x:stk) insert(x);
		}
		else{
			for(int s=0;s<=n;s++){
				f[s].clear();
				for(auto x:dp[s]) f[s].push_back(x);
			}
			for(auto x:stk)
				f[x.sum].push_back(make_pair(x.lcm,x.val));
			for(int s=0;s<=n;s++){
				sort(f[s].begin(),f[s].end());
				dp[s].clear();
				for(int i=1;i<=f[s].size();i++){
					if(i==f[s].size()||f[s][i].first!=f[s][i-1].first){
						int l=i-1,r=i-1;
						while(l>0&&f[s][l-1].first==f[s][r].first) l--;
						int sum=0;
						for(int j=l;j<=r;j++) sum=(sum+f[s][j].second)%mod;
						dp[s].push_back(make_pair(f[s][r].first,sum));
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
