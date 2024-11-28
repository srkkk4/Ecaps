#include <bits/stdc++.h>
#define MAXN 2003
using namespace std;
int n,m,k;
string s[MAXN];
unsigned long long h[MAXN];
unsigned long long Hash[MAXN][27];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        cin>>s[i];
    }
    std::mt19937 Rand(873482273);
    unsigned long long hsum=0;
    for (int i=1;i<=n;i++){
        h[i]=Rand(); hsum+=h[i];
        for (int j=0;j<=m-1;j++){
            Hash[j][s[i][j]-'a'+1]+=h[i];
        }
    }
    for (int i=1;i<=n;i++){
        unsigned long long res=0;
        for (int j=0;j<=m-1;j++){
            for (int p=1;p<=26;p++){
                if (p==s[i][j]-'a'+1) continue;
                res+=Hash[j][p];
            }
        }
        if (res==(hsum-h[i])*k) cout<<i<<'\n';
    }
    return 0;
}