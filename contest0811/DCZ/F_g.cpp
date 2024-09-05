#include <bits/stdc++.h>
#define MAXL 1000003
#define MAXK 50003
using namespace std;
long long n;
int k;
char s[MAXL];
// int q[27][MAXL];
int ton[MAXL];
int cnt[27];
map <int,int[27]> p; //离线
long long a[MAXK]; char c[MAXK];
int main(){
    cin>>n;
    cin>>s;
    long long len=strlen(s); ton[len]=1;
    // for (int i=0;i<len;i++){
    //     for (int j=1;j<=26;j++){
    //         q[j][i+1]=q[j][i];
    //     }
    //     q[s[i]-'A'+1][i+1]++;
    // }
    cin>>k;
    for (int i=1;i<=k;i++){
        cin>>a[i]>>c[i];
        __int128 tmp=a[i];
        tmp=tmp*(a[i]-1);
        tmp=tmp/2+1;
        int l=(tmp-1)%len+1;
        // cout<<l<<" "<<a<<endl;
        long long ans=0;
        // a[i]+=l-1;
        ton[(a[i]+l-1)%len]=1; ton[l-1]=1;
    }
    for (int i=0;i<len;i++){
        cnt[s[i]-'A'+1]++;
        if (ton[i+1]){
            for (int j=1;j<=26;j++){
                p[i+1][j]=cnt[j];
            }
        }
    }
    for (int i=1;i<=k;i++){
        __int128 tmp=a[i];
        tmp=tmp*(a[i]-1);
        tmp=tmp/2+1;
        int l=(tmp-1)%len+1;
        // cout<<l<<" "<<a<<endl;
        long long ans=0;
        a[i]+=l-1;
        ans+=p[len][c[i]-'A'+1]*(a[i]/len);
        ans+=p[a[i]%len][c[i]-'A'+1];
        ans-=p[l-1][c[i]-'A'+1];
        cout<<ans<<endl;
        // ans+=q[c-'A'+1][len]*(a/len);
        // ans+=q[c-'A'+1][a%len];
        // ans-=q[c-'A'+1][l-1];
        // cout<<ans<<endl;
    }
    return 0;
}