#include <bits/stdc++.h>
#define MAXN 1000003
using namespace std;
int T,n,m;
bool is[MAXN];
int prime[MAXN],cnt;
void init(){
    memset(is,1,sizeof is);
    is[1]=1;
    for (int i=2;i<=MAXN-1;i++){
        if (is[i]) prime[++cnt]=i;
        for (int j=1;j<=cnt&&i*prime[j]<=MAXN-1;j++){
            is[i*prime[j]]=0;
            if (i%prime[j]==0) break;
        }
    }
    return;
}
int ans[MAXN];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    init();
    cin>>T;
    while (T--){
        cin>>n>>m;
        if (m>n/2){
            for (int i=1;i<=m-1;i++) cout<<i<<" ";
            cout<<n<<" ";
            for (int i=n-1;i>=m;i--) cout<<i<<" ";
            cout<<endl;
        }
        else if (is[n]||m==1) {for (int i=1;i<=n;i++) cout<<i<<" "; cout<<endl;}
        else {
            int x=0;
            for (x=m;x>=1;x--){
                if (n%x==0) break;
            }
            if (x==1){
                for (int i=1;i<=n;i++) cout<<i<<" ";
                cout<<endl;
                continue;
            }
            for (int i=1;i<=n;i++) ans[i]=0;
            int num=n,num2=n;
            int i;
            for (i=1;i<=n;i++){
                if ((i-1)%m==0) {
                    ans[i]=num; num-=x;
                }
                else {
                    // cerr<<"CNM\n";
                    while (num2%x==0) num2--;
                    ans[i]=num2;
                    num2--;
                    if (num2==0){
                        if (i%m==0) reverse(ans+i-m+1,ans+i+1);
                        else reverse(ans+(i-i%m+1),ans+i+1);
                        break;
                    }
                    if (i%m==0){
                        reverse(ans+i-m+1,ans+i+1);
                        continue;
                    }
                }
            }
            while (num){
                i++;
                ans[i]=num;
                num-=x;
            }
            for (int i=1;i<=n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}