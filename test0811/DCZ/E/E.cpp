#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,s;
int a[MAXN];
int q[MAXN];
int main(){
    freopen("E.in","r",stdin);
    freopen("E.out","w",stdout);
    cin>>n>>s;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    // for (int i=1;i<=n;i++){
    //     int ans=0;
    //     for (int j=i;j+(j-i+1)<=n;j++){
    //         if (q[j]-q[i-1]<=s&&q[j+(j-i+1)]-q[j]<=s){
    //             ans=(j-i+1)*2;
    //         }
    //     }
    //     cout<<ans<<endl;
    // }
    for (int i=1;i<=n-1;i++){
        int l=i,r=i-1+(n-i+1)/2,mid;
        // cout<<l<<" "<<r<<endl;
        while (l<r){
            mid=(l+r)>>1;
            if (q[mid]-q[i-1]>s) r=mid-1;
            else l=mid+1;
        }
        // cout<<"l:"<<l<<endl;
        int ans=0;
        for (int j=l;j>=i;j--){
            if (q[j]-q[i-1]<=s&&q[j+(j-i+1)]-q[j]<=s){
                ans=(j-i+1)*2;
                break;
            }
        }
        cout<<ans<<endl;
    }
    cout<<0<<endl;
    return 0;
}