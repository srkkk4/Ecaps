#include <bits/stdc++.h>
#define MAXN 200003
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
string s; int n;
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s; n=s.length();
    if (s[0]!=s[n-1]){
        if (n&1) cout<<"First\n";
        else cout<<"Second\n";
    } else {
        if (n&1) cout<<"Second\n";
        else cout<<"First\n";
    }
    return 0;
}