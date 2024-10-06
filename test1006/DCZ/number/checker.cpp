#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int main(){
    freopen("number3.out","r",stdin);
    long long tmp,res=0;
    while (cin>>tmp){
        res=(res+tmp)%mod;
    }
    cout<<res<<endl;
    return 0;
}