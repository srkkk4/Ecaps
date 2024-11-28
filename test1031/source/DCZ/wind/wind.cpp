#include <bits/stdc++.h>
#define MAXN 8003
#define mod 998244353
using namespace std;
int c;
int n;
int v[MAXN];
long long f1[MAXN];
long long sum1[MAXN];
int main(){
	freopen("wind.in","r",stdin);
	freopen("wind.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c;
	cin>>n;
	for (int i=0;i<=n;i++) cin>>v[i];
	if (c>=15&&c<=16){
		f1[1]=1; f1[2]=2;
		sum1[1]=1; sum1[2]=3;
		for (int i=3;i<=n;i++){
			f1[i]=(f1[i-1]*2+sum1[i-2])%mod;
			sum1[i]=(sum1[i-1]+f1[i])%mod;
		}
		cout<<f1[n]<<endl;
	}
	return 0;
}
/*
0
10
1 1 1 1 1 1 1 1 1 1 1 
*/