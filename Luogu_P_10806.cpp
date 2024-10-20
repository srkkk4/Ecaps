#include <bits/stdc++.h>
#define MAXN 100003
using namespace std;
int n,m;
int s[MAXN];
int f[MAXN];
int fl[MAXN];
int flag[MAXN];
string ans,plan;
bool check(int x){
    plan.clear();
    int j=1;
    for (int i=1;i<=n;i++){
        if (j<=m&&f[j]<s[i]){
            if (f[j]<s[i]-x) return false;
            else {
                fl[i]=f[j];
                while (j<=m&&f[j]<=s[i]) j++;
                if (plan.back()=='L'&&fl[i-1]>=s[i]-x){
                    flag[i]=1;
                    while (j<=m &&f[j]<=s[i-1]+x) j++;
                }
                plan.push_back('L');
            }
        } else {
            while (j<=m&&f[j]<=s[i]+x) j++;
            plan.push_back('R');
        }
    }
    if (j<=m) return false;
    ans=plan;
    for (int i=n;i>=1;i--) if (flag[i]) {flag[i-1]=flag[i]=0; ans[i-2]='R';} //从右到左再翻转一遍
    return true;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=1;i<=m;i++) cin>>f[i];
    int l=0,r=1000000001;
    while (l<r){
        int mid=(l+r)>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    if (r==1000000001) {cout<<-1<<endl; return 0;}
    cout<<l<<endl;
    cout<<ans<<endl;
    return 0;
}