#include <bits/stdc++.h>
#define MAXN 5003
using namespace std;
int n,m;
int a[MAXN],b[MAXN];
int ton[MAXN<<2];
int main(){
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    cin>>m;
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (a[i]!=(cnt%2)){
            cnt+=1;
        } else {
            cnt+=2;
        }
        ton[cnt]=1;
    }
    cnt=0;
    for (int i=1;i<=m;i++){
        if (cnt%2){
            if (b[i]){
                cnt+=2;
            } else {
                cnt+=1;
            }
        } else {
            if (b[i]){
                cnt+=1;
            } else {
                cnt+=2;
            }
        }
        while (ton[cnt]){
            cnt+=2;
        }
        ton[cnt]=1;
    }
    for (int i=20000;i>=1;i--){
        if (ton[i]){
            cout<<i<<endl;
            break;
        }
    }
    // for (int i=1;i<=n+m;i++){
        // if (ca<=n&&cb<=m){
        //     if (a[ca]!=(ans%2)){
        //         ans++; ca++;
        //     } else if (b[cb]!=(ans%2)){
        //         ans++; cb++;
        //     } else {
        //         ans+=2;
        //         ca++;
        //     }
        // } else if (ca<=n){
        //     if (a[ca]!=(ans%2)){
        //         ans++;
        //     } else {
        //         ans+=2;
        //     }
        //     ca++;
        // } else if (cb<=m){
        //     if (b[cb]!=(ans%2)){
        //         ans++;
        //     } else {
        //         ans+=2;
        //     }
        //     cb++;
        // }
        // if (ca<=n&&(ans+1)%2==a[ca]){
        //     ans++;
        //     ca++;
        // } else if (cb<=m&&(ans+1)%2==b[cb]){
        //     ans++;
        //     cb++;
        // } else {
        //     ans+=2;
        //     if (ca<=n){
        //         ca++;
        //     } else if (cb<=m){
        //         cb++;
        //     }
        // }
    // }
    // cout<<ans<<endl;
    return 0;
}