#include <bits/stdc++.h>
#define MAXN 103
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
char s[MAXN]; int n;
int K;
long long C(int m,int n){
    if (m<n) return 0;
    long long res=1;
    for (int i=m;i>=m-n+1;i--) res=res*i;
    for (int i=1;i<=n;i++) res=res/i;
    return res;
}
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s+1; n=strlen(s+1);
    cin>>K;
    long long ans=0; int flag=0; int tmpk=K;
    for (int i=1;i<=tmpk&&i<=n;i++){
        if (s[i]>'0') {ans+=C(n-i,tmpk-i+1)*pow<long long>(9,tmpk-i+1); flag++;}
        else tmpk++;
        if (s[i]>'1') ans+=(s[i]-'1')*C(n-i,tmpk-i)*pow<long long>(9,tmpk-i);
    }
    if (flag==K) ans+=1;
    cout<<ans<<'\n';
    return 0;
}