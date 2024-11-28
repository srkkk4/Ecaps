#include <bits/stdc++.h>
#define MAXN 2000003
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n,m;
string s;
string t;
string a;
int nxt[MAXN];
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    cin>>t; m=t.length();
    a=t+'#'+s; n=a.length(); a=' '+a;
    int p=0; nxt[1]=0;
    for (int i=2;i<=n;i++){
        while (p>0&&a[p+1]!=a[i]) p=nxt[p];
        if (a[p+1]==a[i]) p=p+1;
        nxt[i]=p;
    }
    for (int i=m+2;i<=n;i++){
        if (nxt[i]==m) cout<<i-2*m<<'\n';
    }
    for (int i=1;i<=m;i++) cout<<nxt[i]<<" ";
    cout<<'\n';
    return 0;
}