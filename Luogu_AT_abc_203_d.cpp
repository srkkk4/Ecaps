#include <bits/stdc++.h>
#define MAXN 803
using namespace std;
int n,k;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
bool check(int x){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (a[i][j]>x) b[i][j]=1;
            else b[i][j]=0;
            b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+b[i][j];
        }
    }
    for (int i=1;i<=n-k+1;i++){
        for (int j=1;j<=n-k+1;j++){
            int x=i+k-1,y=j+k-1;
            if (b[x][y]-b[i-1][y]-b[x][j-1]+b[i-1][j-1]<(k*k)/2+1) return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int l=0,r=1000000000;
    while (l<r){
        int mid=(l+r)>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}