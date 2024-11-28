#include <bits/stdc++.h>
#define MAXN 200003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
bool ED;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	multiset <int> s;
	for (int i=10;i>=1;i--) s.insert(i);
	for (int i=6;i>=1;i--) s.insert(i);
	
	cout<<s.size()<<'\n';
	multiset <int>::iterator it;
	for (it=s.begin();it!=s.end();it++){
		cout<<*it<<' ';
	}
	cout<<'\n';
	return 0;
}