#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int c;
int T;
int a[MAXN];
int v[10];
long long sum[MAXN];
long long f[MAXN][7];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c;
    cin>>T;
    sum[0]=1;
    for (int i=1;i<=6;i++) sum[i]=sum[i-1]*10;
    while (T--){
        string num; cin>>num;
        int len=num.length();
        for (int i=0;i<=len-1;i++) a[i+1]=int(num[len-i-1]-'0');
        for (int i=1;i<=9;i++) cin>>v[i];
        for (int i=1;i<=len;i++){
            for (int j=1;j<=6;j++){
                f[i][j]=min(f[i-1][j]+v[a[i]],f[i-1][j-1]+sum[j-1]*a[i]);
            }
            f[i][0]=f[i-1][0]+v[a[i]];
        }
        long long ans=LONG_LONG_MAX;
        for (int i=6;i>=0;i--) ans=min(ans,f[len][i]);
        cout<<ans<<endl;
    }
    return 0;
}