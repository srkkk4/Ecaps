#include <bits/stdc++.h>
#define MAXN 2003
using namespace std;
int n,m;
int a[MAXN];
int main(){
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (m==0){
        int ans=0,mx=-INT_MAX;
        for (int i=1;i<=n;i++){
            ans+=a[i];
            mx=max(mx,ans);
            if (ans<0) ans=0;
        }
        cout<<mx<<endl;
    } else if (m==1){
        int mx=-INT_MAX;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=i-1;j++){
                swap(a[i],a[j]);
                int ans=0;
                for (int k=1;k<=n;k++){
                    ans+=a[k];
                    mx=max(mx,ans);
                    if (ans<0) ans=0;
                }
                swap(a[i],a[j]);
            }
        }
        cout<<mx<<endl;
    } else if (m==2){
        int mx=-INT_MAX;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=i-1;j++){
                for (int k=1;k<=n;k++){
                    for (int l=1;l<=k-1;l++){
                        swap(a[i],a[j]); swap(a[k],a[l]);
                        int ans=0;
                        for (int o=1;o<=n;o++){
                            ans+=a[o];
                            mx=max(mx,ans);
                            if (ans<0) ans=0;
                        }
                        swap(a[i],a[j]); swap(a[k],a[l]);
                        swap(a[k],a[l]); swap(a[i],a[j]);
                        ans=0;
                        for (int o=1;o<=n;o++){
                            ans+=a[o];
                            mx=max(mx,ans);
                            if (ans<0) ans=0;
                        }
                        swap(a[k],a[l]); swap(a[i],a[j]);
                    }
                }
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}