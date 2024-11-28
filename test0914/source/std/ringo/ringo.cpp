#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m;
char a[1005][1005];
int pre1[1005][1005],suf1[1005][1005],s1[1005],s2[1005];
int pre2[1005][1005],suf2[1005][1005];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='#'){
				pre1[i][j]=0;continue; 
			}
			pre1[i][j]=pre1[i][j-1]+1;
			s1[i]+=pre1[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j;j--){
			if(a[i][j]=='#'){
				suf1[i][j]=0;continue;
			}
			suf1[i][j]=suf1[i][j+1]+1;
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(a[i][j]=='#'){
				pre2[i][j]=0;continue;
			}
			pre2[i][j]=pre2[i-1][j]+1;
			s2[j]+=pre2[i][j];
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=n;i;i--){
			if(a[i][j]=='#'){
				suf2[i][j]=0;continue;
			}
			suf2[i][j]=suf2[i+1][j]+1;
		}
	}
	int ans=0,S1=0,S2=0;
	for(int i=1;i<=n;i++){
		S1+=s1[i];if(S1>=mod) S1-=mod;
	}
	for(int i=1;i<=n;i++){
		ans+=(S1-s1[i])*s1[i]%mod;
		int sum=0; 
		for(int j=1;j<=m;j++){
			ans+=sum*suf1[i][j]%mod*2%mod;
			sum+=pre1[i][j];
			if(sum>=mod) sum-=pre1[i][j];
		}
	}ans=(ans%mod+mod)%mod;
	for(int j=1;j<=m;j++){
		S2+=s2[j];if(S2>=mod) S2-=mod;
	}
	for(int j=1;j<=m;j++){
		ans+=(S2-s2[j])*s2[j]%mod;
		int sum=0;
		for(int i=1;i<=n;i++){
			ans+=sum*suf2[i][j]%mod*2%mod;
			sum+=pre2[i][j];
		}
	}ans=(ans%mod+mod)%mod;
	ans+=S1*S2%mod*2%mod;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans-=pre1[i][j]*suf1[i][j]%mod*pre2[i][j]%mod*suf2[i][j]%mod*2%mod;
		}
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<'\n';
	memset(pre1,0,sizeof(pre1));
	memset(pre2,0,sizeof(pre2));
	memset(suf1,0,sizeof(suf1));
	memset(suf2,0,sizeof(suf2));
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
}
signed main(){
	freopen("ringo.in","r",stdin);
	freopen("ringo.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt,tid;cin>>tt>>tid;
	while(tt--) solve();
}
