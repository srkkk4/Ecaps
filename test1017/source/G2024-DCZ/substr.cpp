#include <bits/stdc++.h>
#define MAXN 250003
using namespace std;
int n;
struct TMP{
	int val;
	int id;
	bool operator<(const TMP &B)const{
		return val<B.val;
	}
}tmp[MAXN];
int a[MAXN];
int t[2][MAXN];
int lowbit(int x){
	return x&-x;
}
void add(int pos,int x,int y){
	for (int p=x;p<=n;p+=lowbit(p)){
		t[pos][p]+=y;
	}
	return;
}
int sum(int pos,int x){
	int res=0;
	for (int p=x;p>=1;p-=lowbit(p)){
		res+=t[pos][p];
	}
	return res;
}
bool is_sub4=1;
struct Q{
	int len;
	int l;
}q[MAXN];
int cnt2;
int main(){
	freopen("substr.in","r",stdin);
	freopen("substr.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) {cin>>tmp[i].val; tmp[i].id=i;}
	sort(tmp+1,tmp+1+n); int last=tmp[1].val,cnt=1; a[tmp[1].id]=cnt;
	for (int i=2;i<=n;i++){
		if (tmp[i].val!=last) {cnt++; last=tmp[i].val;}
		a[tmp[i].id]=cnt;
	}
	for (int i=1;i<=n;i++) if (a[i-1]>a[i]) {is_sub4=0; break;}
	int ans=0;
	if (is_sub4){
		int LAST=0,lp=0;
		for (int i=1;i<=n+1;i++){
			if (a[i]!=LAST) {q[cnt2++].len=i-lp; q[cnt2].l=lp; LAST=a[i]; lp=i;}
		}
		cnt2--;
		for (int i=1;i<=cnt2-1;i++){
			ans=max(ans,min(q[i].len*2,(n-q[i].l+1)-(n-q[i].l+1)%2));
		}
		ans=max(ans,q[cnt].len-q[cnt].len%2);
		cout<<ans<<endl;
		return 0;
	}
	for (int i=1;i<=n-1;i++){
		if (ans>=(n-i)*2) continue;
		int l=i,r=i+1; int res=0;
		while (l>=1&&r<=n){
			if (sum(0,a[l])==sum(1,a[r])) res+=2;
			else break;
			add(0,a[l],1); add(1,a[r],1);
			l--; r++;
		}
		ans=max(ans,res);
		for (int j=l+1;j<=i;j++) add(0,a[j],-1);
		for (int j=i+1;j<=r-1;j++) add(1,a[j],-1);
	}
	cout<<ans<<endl;
	return 0;
}
