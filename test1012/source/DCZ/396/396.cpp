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
int main(){
	freopen("396.in","r",stdin);
	freopen("396.out","w",stdout);
	ios::sync_with_stdio(0);
	while (cin>>n){
		A.s.clear(); B.s.clear();
		A.s.push_back(0); B.s.push_back(0);
		for (int i=1;i<=n;i++) {int tmp; cin>>tmp; A.s.push_back(tmp);}
		for (int i=1;i<=n;i++) {int tmp; cin>>tmp; B.s.push_back(tmp);}
		// for (int i=1;i<=n;i++) cout<<A.s[i]<<" ";
		// cout<<endl;
		// for (int i=1;i<=n;i++) cout<<B.s[i]<<" ";
		// cout<<endl;
		for (int i=1;i<=n;i++) to[A.s[i]]=i;
		int flag=1,ok=1;
		for (int i=1;i<=n;i++){
			if (B.s[flag]==A.s[1]){
				if (qpow(A,i)==B){
					cout<<"Yes\n";
					ok=0;
					break;
				}
			}
			flag=to[flag];
		}
		if (ok) cout<<"No\n";
	}
	return 0;
}