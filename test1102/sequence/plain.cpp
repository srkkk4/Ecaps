#include <bits/stdc++.h>
using namespace std;
int n,m;
int au(int x){
    int res=0;
    for (int i=1;i<=x;i++){
        if (__gcd(i,x)==1) res++;
    }
    return res;
}
int main(){
    while (1){
        cin>>n>>m;
        long long ans=1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                ans=ans*au(i*j);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}