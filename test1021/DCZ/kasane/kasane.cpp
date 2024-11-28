#include <bits/stdc++.h>
#define MAXN 500003
using namespace std;
int T;
int n,K;
char c[MAXN];
int main(){
    freopen("kasane.in","r",stdin);
    freopen("kasane.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n>>K;
        cin>>c+1;
        if (K==1) cout<<(1+n)*n/2<<endl;
        else if (n<=5000){
            long long ans=0;
            for (int i=1;i<=n-K+1;i++){
                string A="";
                for (int len=1;len<=n/K;len++){
                    A+=c[i+len-1];
                    bool rev=1;
                    int flag=1;
                    for (int cnt=2;cnt<=K;cnt++){
                        if (rev){
                            for (int j=i+len*(cnt-1),o=len-1;j<=i+len*cnt-1;j++,o--) if (c[j]!=A[o]) {flag=0; break;} 
                        } else {
                            for (int j=i+len*(cnt-1),o=0;j<=i+len*cnt-1;j++,o++) if (c[j]!=A[o]) {flag=0; break;}
                        }
                        rev=!rev;
                    }
                    if (flag) ans++;
                }
            }
            cout<<ans<<endl;
        } else {
            cout<<0<<endl;
        }
    }
    return 0;
}
/*
5
8 1
abbaabba
8 2
abbaabba
8 3
abbaabba
8 4
abbaabba
8 5
abbaabba
*/