#include <bits/stdc++.h>
#define MAXN 2003
#define mod 998244353
using namespace std;
int n;
struct P{
	int ch[3];
}a[MAXN];
long long f[MAXN][MAXN][3];
int main(){
	freopen("106.in","r",stdin);
	freopen("106.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		string s; cin>>s; int len=s.length();
		for (int j=0;j<len;j++) a[i].ch[s[j]-'0']=1;
	}
	f[1][1][0]=a[1].ch[0]; f[1][1][1]=a[1].ch[1]; f[1][1][2]=a[1].ch[2];
	for (int i=2;i<=n;i++){
		for (int k=1;k<=n;k++){
			if (a[i].ch[0]) f[i][k][0]=(f[i][k][0]+f[i-1][k][0]+f[i-1][k][1]+f[i-1][k-1][2])%mod;
			if (a[i].ch[1]) f[i][k][1]=(f[i][k][1]+f[i-1][k][1]+f[i-1][k][2]+f[i-1][k-1][0])%mod;
			if (a[i].ch[2]) f[i][k][2]=(f[i][k][2]+f[i-1][k][2]+f[i-1][k][0]+f[i-1][k-1][1])%mod;
		}
	}
	for (int k=1;k<=n;k++){
		cout<<(f[n][k][0]+f[n][k][1]+f[n][k][2])%mod<<" ";
	}
	cout<<endl;
	return 0;
}
/*
3
01
12
02
*/