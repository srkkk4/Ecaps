#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,L;
int used[MAXN];
struct medi{
	int A;
	int B;
	int id;
	bool operator<(const medi &b)const {
		return A<b.A;
	}
}a[MAXN];
int c[MAXN];
bool cmp(medi x,medi y){
	if (x.A-x.B==y.A-y.B) return x.A<y.A;
	else return x.A-x.B>y.A-y.B;
}
priority_queue <medi> q;
int main(){
	freopen("129.in","r",stdin);
	freopen("129.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>L;
	for (int i=1;i<=n;i++) {cin>>a[i].A>>a[i].B; a[i].id=i; q.push(a[i]);}
	for (int i=1;i<=n;i++) cin>>c[i];
	sort(a+1,a+1+n,cmp);
	long long cnt=0,lvl=0;
	for (int i=1;i<=n;i++){
		medi now=q.top();
		while (used[now.id]) {q.pop(); now=q.top();}
		// cout<<a[i].A<<" "<<a[i].B<<" "<<now.A<<" "<<cnt<<endl;
		if (cnt+now.A>=L) {cout<<i<<endl; return 0;}
		cnt+=a[i].A-a[i].B; used[a[i].id]=1;
		lvl+=c[i];
		if (cnt<=lvl) {cout<<-1<<endl; return 0;}
	}
	cout<<-1<<endl;
	return 0;
}
/*
3 9
6 3
5 2
3 1
2
2
2

5 20
3 2
4 2
6 3
8 4
10 5
4
2
3
4
5

*/