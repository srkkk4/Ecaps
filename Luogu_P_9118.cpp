#include <bits/stdc++.h>
#define MAXK 103
using namespace std;
long long n,k;
long long f[MAXK];
int main(){
    cin>>n>>k;
    long long ans=0;
    for (int i=100;i>=k;i--){
        f[i]=pow<long double>(n,1.0/i)+0.000000001-1;
        for (int j=i*2;j<=100;j+=i) f[i]-=f[j];
        ans+=f[i];
    }
    cout<<ans+1<<endl;
    return 0;
}