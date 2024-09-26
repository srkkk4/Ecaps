// https://www.luogu.com.cn/problem/T508983?contestId=197293
// https://blog.csdn.net/Qiuker_jl/article/details/109528164
#include <bits/stdc++.h>
#define mod 998244353
#define MAXN 233333
#define int long long
using namespace std;
int n;
int a[MAXN];
int dp[MAXN];
int t[2335][2335];
int lowbit(int x){
    return x&-x;
}
int sum(int s,int x){
    int res=0;
    for (int p=x;p>=1;p-=lowbit(p)){
        res+=t[s][p];
    }
    return res;
}
void add(int s,int x){
    for (int p=x;p<=2333+2;p+=lowbit(p)){
        // cout<<"ok\n";
        t[s][p]++;
    }
    return;
}
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        add(a[i]/2333,(a[i]%2333)+2);
        cout<<sum(a[i]/2333,2333+2)<<" "<<sum(a[i]/2333,(a[i]%2333)+1)<<endl;
        for (int j=a[i]/2333;j<=110;j++){
            (dp[i]+=sum(j,2333+2)-sum(j,(a[i]%2333)+1))%=mod;
        }
        // cout<<dp[i]<<" ";
    }
    // cout<<endl;
    // for (int i=0;i<=10;i++){
    //     for (int j=0;j<=10;j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int ANS=0;
    for (int i=1;i<=n;i++) (ANS+=dp[i])%=mod;
    cout<<ANS-n<<endl;
    return 0;
}