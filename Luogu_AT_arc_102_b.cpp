#include <bits/stdc++.h>
#define MAXN 200003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int L;
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>L;
    int cnt1=0; int tmp=L; while (tmp) {cnt1++; tmp>>=1;} cnt1--;
    L-=(1<<cnt1);
    int cnt2=0; tmp=L; while (tmp) {if (tmp&1) cnt2++; tmp>>=1;}
    cout<<cnt1+1<<" "<<cnt1*2+cnt2<<'\n';
    for (int i=1;i<=cnt1;i++){
        cout<<i<<" "<<i+1<<" "<<(1<<(cnt1-i))<<'\n';
        cout<<i<<" "<<i+1<<" "<<0<<'\n';
    }
    int cnt3=1<<cnt1;
    for (int i=cnt1-1;i>=0;i--){
        if (L&(1<<i)){
            cout<<1<<" "<<cnt1-i+1<<" "<<cnt3<<'\n';
            cnt3+=(1<<i);
        }
    }
    return 0;
}