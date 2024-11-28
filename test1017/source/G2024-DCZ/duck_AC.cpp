#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,m;
long long a[MAXN*2];
bool is_sub2=1;
bool check(int x){
	//左边不合法往左移，但先把右侧情况考虑完分界线会尽可能向左逼近，这里不需要判断
	if (x!=2*n) for (int i=x+1,j=2*n;i<j;i++,j--) if (a[i]+a[j]<m) return false; //仅右边不合法需要往右移分界线
	return true;
}
int main(){
	freopen("duck.in","r",stdin);
	freopen("duck.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*2;i++) {cin>>a[i]; if (a[i]!=0) is_sub2=0;}
	if (n==1){
		cout<<(a[1]+a[2])%m<<endl;
		return 0;
	}
	if (m==1){
		cout<<0<<endl;
		return 0;
	}
	if (is_sub2){
		cout<<0<<endl;
		return 0;
	}
	sort(a+1,a+1+2*n);
	int l=0,r=n;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid*2)) r=mid-1;
		else l=mid+1;
	}
	long long ans=0;
	if (l!=0) for (int i=1,j=2*l;i<j;i++,j--) ans=max(ans,a[i]+a[j]);
	if (l!=n) for (int i=2*l+1,j=2*n;i<j;i++,j--) ans=max(ans,(a[i]+a[j])%m);
	cout<<ans<<endl;
	return 0;
}