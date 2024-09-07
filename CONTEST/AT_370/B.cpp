#include <bits/stdc++.h>
#define MAXN 103
using namespace std;
int n;
int a[MAXN][MAXN];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    int x=1;
    for (int i=1;i<=n;i++){
        if (x>=i) x=a[x][i];
        else      x=a[i][x];
    }
    cout<<x<<endl;
    return 0;
}