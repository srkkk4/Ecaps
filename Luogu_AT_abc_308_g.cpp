#include <bits/stdc++.h>
#define MAXN 300003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n;
multiset <int> num,XOR;
bool ED;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		int type; cin>>type;
		if (type==1){
			int x; cin>>x;
			num.insert(x);
			multiset <int>::iterator it=num.find(x),rbegin=num.begin(),rend=--num.end();
			multiset <int>::iterator pre=it,suf=it;
            if (it!=rbegin) pre--; if (it!=rend) suf++; 
            if (it!=rbegin&&it!=rend) XOR.erase(XOR.find(*pre^*suf));
			if (it!=rbegin) XOR.insert(*pre^*it);
			if (it!=rend) XOR.insert(*it^*suf);
		} else if (type==2){
			int x; cin>>x;
			multiset <int>::iterator it=num.find(x),rbegin=num.begin(),rend=--num.end();
			multiset <int>::iterator pre=it,suf=it;
            if (it!=rbegin) pre--; if (it!=rend) suf++; 
            if (it!=rbegin) XOR.erase(XOR.find(*pre^*it));
			if (it!=rend) XOR.erase(XOR.find(*it^*suf));
			if (it!=rbegin&&it!=rend) XOR.insert(*pre^*suf);
            num.erase(it);
		} else {
			cout<<*XOR.begin()<<'\n';
        }
        // multiset <int>::iterator iter;
        // for (iter=num.begin();iter!=num.end();iter++) cerr<<*iter<<' ';
        // cerr<<'\n';
	}
	return 0;
}