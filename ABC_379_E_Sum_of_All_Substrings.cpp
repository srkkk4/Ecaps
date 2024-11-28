#include <bits/stdc++.h>
#define MAXN 210003
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n;
char a[MAXN];
long long sum[MAXN];
int ans[MAXN]; int cnt;
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1,j=n;i<=n;i++,j--) sum[j]=i*(a[i]-'0');
    long long now=0;
    for (int i=n;i>=1;i--){
        now+=sum[i];
        sum[i]=now;
    }
    int i=1;
    while (sum[i]){
        ans[++cnt]=sum[i]%10;
        sum[i+1]+=sum[i]/10;
        i++;
    }
    for (int i=cnt;i>=1;i--) cout<<ans[i];
    cout<<'\n';
    return 0;
}