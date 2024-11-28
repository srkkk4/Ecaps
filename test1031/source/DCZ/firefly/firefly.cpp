#include <bits/stdc++.h>
#define MAXN 1000003
using namespace std;
int c;
int n,m,q;
struct DO{
	int l;
	int r;
	bool operator<(const DO &B)const{
		if (l==B.l) return r<B.r;
		else return l<B.l;
	}
}D[MAXN];
struct QUE{
	int L;
	int R;
	int id;
	bool operator<(const QUE &B)const{
		if (L==B.L) return R<B.R;
		else return L<B.L;
	}
}Q[MAXN];
int ans[MAXN];
int main(){
	freopen("firefly.in","r",stdin);
	freopen("firefly.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c;
	cin>>n>>m>>q;
	for (int i=1;i<=m;i++){
		cin>>D[i].l>>D[i].r;
	}
	sort(D+1,D+1+m);
	// for (int i=1;i<=m;i++) cout<<"->:"<<D[i].l<<" "<<D[i].r<<endl;
	for (int i=1;i<=q;i++){
		cin>>Q[i].L>>Q[i].R;
		Q[i].id=i;
	}
	sort(Q+1,Q+1+q);
	int cnt=1;
	for (int i=1;i<=q;i++){
		// cout<<">:"<<Q[i].L<<" "<<Q[i].R<<endl;
		// cout<<cnt<<endl;
		while (D[cnt].l<Q[i].L&&cnt<=m) cnt++;
		// cout<<cnt<<endl;
		// cout<<D[cnt].l<<" "<<D[cnt].r<<endl;
		int l=0,r=-1; int cnt2=cnt;
		while (D[cnt2].l<=Q[i].R&&cnt2<=m){
			if (D[cnt2].r>Q[i].R) {cnt2++; continue;}
			// cout<<D[cnt2].l<<" "<<D[cnt2].r<<endl;
			if (D[cnt2].l>r){
				ans[Q[i].id]+=r-l+1;
				l=D[cnt2].l; r=D[cnt2].r;
			} else {
				r=max(r,D[cnt2].r);
			}
			cnt2++;
		}
		ans[Q[i].id]+=r-l+1;
	}
	for (int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
/*
0
10 4 5
1 3
2 4
8 9
7 10
1 3
1 4
1 10
8 10
7 8
*/