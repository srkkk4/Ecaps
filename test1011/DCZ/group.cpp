#include <bits/stdc++.h>
#define MAXN 2003
using namespace std;
int n;
int a[MAXN];
long long f[MAXN][MAXN];
int main(){
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cout<<a[n]<<endl;
	return 0;
}