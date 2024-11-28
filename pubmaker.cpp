#include <bits/stdc++.h>
#include <sys/time.h>
#include <unistd.h>
#define MAXN 200003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n=10;
int a[MAXN];
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    struct timeval time;
    gettimeofday(&time,NULL);
    mt19937 Rand(time.tv_usec);
    cout<<n<<'\n';
    for (int i=1;i<=n;i++){
        a[i]=Rand()%10+1;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<'\n';
    return 0;
}