// Problem: U497090 世界沉睡童话
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U497090?contestId=209328
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define MAXN 5000003
#define MAXQ 5000003
using namespace std;
int n,k;
int Prime[MAXQ];
bool notPrime[MAXN]; int cnt;
void init(){
    notPrime[1]=1;
    for (int i=2;i<=2*n-1;i++){
        if (!notPrime[i]){
            Prime[++cnt]=i;
        }
        for (int j=1;j<=cnt&&1ll*i*Prime[j]<=n;j++){
            notPrime[i*Prime[j]]=1;
            if (i%Prime[j]==0){
                break;
            }
        }
    }
    return;
}
int main(){
	cin>>n>>k;
	init();
	cnt=1; int cnt2=0;
	while (k){
		int l=2,r=n,mid;
		while (l<r){
			if (mid*(mid-1)/2<=k) l=mid;
			else r=mid-1;
		}
		k-=l*(l-1)/2;
		for (int i=1;i<=l;i++) {cout<<Prime[cnt]<<" "; cnt2++;}
		cnt++;
	}
	while (cnt2<n) {cout<<Prime[cnt++]<<" "; cnt2++;}
	return 0;
}