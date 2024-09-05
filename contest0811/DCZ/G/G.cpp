#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int n,q;
long long a[MAXN];
int main(){
    freopen("G.in","r",stdin);
    freopen("G.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    while (q--){
        int L,R,x;
        scanf("%d %d %d",&L,&R,&x);
        for (int i=L;i<=R;i++) a[i]+=x;
        long long l=a[1]; int s=0;
        long long ans=0,ans2=0;
        // for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        // cout<<endl;
        for (int i=2;i<=n;i++){
            if (!s){
                if (a[i]>a[i-1]){
                    s=1;
                } else if (a[i]<a[i-1]){
                    s=2;
                }
            } else if (s==1){
                if (a[i]<=a[i-1]){
                    ans+=a[i-1]-l;
                    l=a[i];
                    s=0;
                }
            } else {
                if (a[i]>=a[i-1]){
                    ans+=l-a[i-1];
                    l=a[i];
                    s=0;
                }
            }
            // cout<<"s:"<<s<<endl;
        }
        ans+=abs(l-a[n]);
        l=a[n]; s=0;
        for (int i=n-1;i>=1;i--){
            if (!s){
                if (a[i]>a[i+1]){
                    s=1;
                } else if (a[i]<a[i+1]){
                    s=2;
                }
            } else if (s==1){
                if (a[i]<=a[i+1]){
                    ans2+=a[i+1]-l;
                    l=a[i];
                    s=0;
                }
            } else {
                if (a[i]>=a[i+1]){
                    ans2+=l-a[i+1];
                    l=a[i];
                    s=0;
                }
            }
            // cout<<"s:"<<s<<endl;
        }
        ans2+=abs(l-a[1]);
        cout<<max(ans,ans2)<<endl;
    }
    return 0;
}