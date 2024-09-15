#include <bits/stdc++.h>
#define MAXL 1000003
using namespace std;
long long n;
int k;
char s[MAXL];
int q[27][MAXL];
int main(){
    freopen("F.in","r",stdin);
    freopen("F.out","w",stdout);
    cin>>n;
    cin>>s;
    long long len=strlen(s);
    for (int i=0;i<len;i++){
        for (int j=1;j<=26;j++){
            q[j][i+1]=q[j][i];
        }
        q[s[i]-'A'+1][i+1]++;
    }
    // for (int i=1;i<=26;i++){
    //     cout<<char('A'+i-1)<<" ";
    //     for (int j=1;j<=len;j++){
    //         cout<<q[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cin>>k;
    while (k--){
        long long a; char c;
        cin>>a>>c;
        __int128 tmp=a;
        tmp=tmp*(a-1);
        tmp=tmp/2+1;
        int l=(tmp-1)%len+1;
        // cout<<l<<" "<<a<<endl;
        long long ans=0;
        a+=l-1;
        ans+=q[c-'A'+1][len]*(a/len);
        ans+=q[c-'A'+1][a%len];
        ans-=q[c-'A'+1][l-1];
        cout<<ans<<endl;
    }
    return 0;
}