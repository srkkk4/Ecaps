#include <bits/stdc++.h>
using namespace std;
long long T,n,a,b;
int main(){
    cin>>T;
    while (T--){
        cin>>n>>a>>b;
        if (b>a&&b-n+1<=a){
            cout<<(b+(a+1))*(b-a)/2+a*(n-(b-a))<<endl;
        } else if (b>a&&b-n+1>a){
            cout<<(b+(b-n+1))*n/2<<endl;
        } else {
            cout<<n*a<<endl;
        }
    }
    return 0;
}