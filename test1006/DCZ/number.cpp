#include <bits/stdc++.h>
using namespace std;
int T;
long long n,a,b,s;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>T;
    while (T--){
        cin>>n>>a>>b>>s;
        long long num1=s-n*b;
        if (num1>=0) cout<<num1<<endl;
        else cout<<((a+b)-abs(num1)%(a+b))%(a+b)<<endl;
    }
    return 0;
}