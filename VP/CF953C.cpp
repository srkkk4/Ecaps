#include <bits/stdc++.h>
using namespace std;
long long T,n,k;
int ans[200003];
int main(){
    cin>>T;
    while (T--){
        cin>>n>>k;
        // cout<<n<<endl;
        if (k%2==0&&k<=((n%2)?(n/2+1)*(n/2)*2:(n/2+1)*(n/2)*2-n)){
            // memset(ans,0,sizeof ans);
            // cout<<"ok\n";
            for (int i=1;i<=n;i++){
                ans[i]=i;
            }
            int t=0; int l;
            bool OK=1;
            if (n%2){
                if (k&2) t=1;
                l=n/2;
                while (k&&l>=1){
                    if (k>=l*4){
                        // cout<<"ok\n";
                        k-=l*4;
                        swap(ans[n/2+1+l],ans[n/2+1-l]);
                    }
                    l--;
                }
                if (t){
                    bool ok=1;
                    for (int i=1;i<=n-1;i++){
                        if (abs(ans[i]-i)+abs(ans[i+1]-(i+1))+2==abs(ans[i+1]-i)+abs(ans[i]-(i+1))){
                            swap(ans[i],ans[i+1]);
                            ok=0;
                            break;
                        }
                    }
                    if (ok) OK=0;
                }
            } else {
                l=n/2;
                while (k&&l>=2){
                    if (k>=l*4-2){
                        k-=l*4-2;
                        swap(ans[n/2+l],ans[n/2+1-l]);
                    }
                    l--;
                }
                if (k==2) swap(ans[n/2+1],ans[n/2]);
                if (k==4){
                    bool ok=1;
                    for (int i=1;i<=n-1;i++){
                        if (abs(ans[i]-i)+abs(ans[i+2]-(i+2))+4==abs(ans[i+2]-i)+abs(ans[i]-(i+2))){
                            swap(ans[i],ans[i+2]);
                            ok=0;
                            break;
                        }
                    }
                    if (ok) OK=0;
                }
            }
            if (OK){
                cout<<"Yes"<<endl;
                for (int i=1;i<=n;i++){
                    printf("%d ",ans[i]);
                }
                cout<<endl;
            } else {
                cout<<"No"<<endl;
            }
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}