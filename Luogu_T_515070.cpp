#include <bits/stdc++.h>
#define mod 988444333
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a,b,h,k;
    cin>>a>>b>>h>>k;
    long long ans=1ll*(a+k)*(b+k)*(h+k);
    cout<<ans%mod<<endl;
    return 0;
}