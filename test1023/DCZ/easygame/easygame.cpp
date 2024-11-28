#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)
#define MAXN 100003
using namespace std;
int n;
string st;
char s[MAXN];
int tran[27];
unordered_map <int,int> mp;
int main(){
    freopen("easygame.in","r",stdin);
    freopen("easygame.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    getline(cin,st);
    n=st.length();
    for(int i=1;i<=n;i++) s[i]=st[i-1];
    tran[0]=1;
    for (int i=1;i<26;i++){
        tran[i]=tran[i-1]<<1;
    }
    int now=0,ans=0;
    for (int i=1;i<=n;i++){
        now=now^tran[s[i]-'a'];
        if (now==0){
            ans=max(ans,i);
        } else if (mp[now]){
            ans=max(ans,i-mp[now]);
        } else {
            mp[now]=i;
        }
        for (int j=0;j<26;j++){
            int tmp=now^tran[j];
            if (tmp==0){
                ans=max(ans,i);
            } else if (mp[tmp]){
                ans=max(ans,i-mp[tmp]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}