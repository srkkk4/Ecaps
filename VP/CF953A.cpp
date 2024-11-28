#include <bits/stdc++.h>
using namespace std;
int T,n;
int a[103];
int main(){
    cin>>T;
    while (T--){
        cin>>n;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int mx=0;
        for (int i=1;i<=n-1;i++) mx=max(mx,a[i]);
        cout<<a[n]+mx<<endl;
    }
    return 0;
}