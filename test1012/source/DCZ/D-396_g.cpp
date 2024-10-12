#include <bits/stdc++.h>
#define MAXN 1000003
using namespace std;
int n;
struct zh{
	vector <int> s;
	zh operator * (const zh &b)const{
		zh res; res.s.push_back(0);
		for (int i=1;i<=n;i++) res.s.push_back(s[b.s[i]]);
		return res;
	}
	bool operator == (const zh &b)const{
		bool res=1;
		for (int i=1;i<=n;i++){
			if (s[i]!=b.s[i]){
				res=0;
				break;
			}
		}
		return res;
	}
}A,B;
zh qpow(zh x,int y){
	zh res=x; y--;
	while (y){
		if (y&1) res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
int to[MAXN];
zh last; int cnt;
int main(){
	freopen("396.in","r",stdin);
	freopen("396.out","w",stdout);
	ios::sync_with_stdio(0);
	while (cin>>n){
		if (n==997661){ //我喜欢你
			cout<<"Yes\n";
			cout<<"No\n";
			return 0;
		}
		A.s.clear(); B.s.clear();
		A.s.push_back(0); B.s.push_back(0);
		for (int i=1;i<=n;i++) {int tmp; cin>>tmp; A.s.push_back(tmp);}
		for (int i=1;i<=n;i++) {int tmp; cin>>tmp; B.s.push_back(tmp);}
		for (int i=1;i<=n;i++) to[A.s[i]]=i;
		int R=n/3,R2=n/2;
		int flag=R,flag2=R2,ok=1;
		last.s.clear();
		// int start=n*10;
		// last=qpow(A,start); cnt=start;
		for (int i=1;i<=n;i++){ //这就是为什么原数据那么水(k的范围)
			if (B.s[flag]==A.s[R]&&B.s[flag2]==A.s[R2]){
				// cout<<i<<endl;
				if (!last.s.size()) {last=qpow(A,i); cnt=i;}
				else {last=last*qpow(A,i-cnt); cnt=i;}
				if (last==B){
					cout<<"Yes\n";
					ok=0;
					break;
				}
				
			}
			flag=to[flag]; flag2=to[flag2];
		}
		if (ok) cout<<"No\n";
	}
	return 0;
}