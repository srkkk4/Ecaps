#include <bits/stdc++.h>
using namespace std;
int n;
int a[10];
int b[10][10][10][10][10];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=5;j++){
            cin>>a[j];
        }
        for (int j=1;j<=9;j++){
            b[(a[1]+j)%10][a[2]][a[3]][a[4]][a[5]]++;
            b[a[1]][(a[2]+j)%10][a[3]][a[4]][a[5]]++;
            b[a[1]][a[2]][(a[3]+j)%10][a[4]][a[5]]++;
            b[a[1]][a[2]][a[3]][(a[4]+j)%10][a[5]]++;
            b[a[1]][a[2]][a[3]][a[4]][(a[5]+j)%10]++;

            b[(a[1]+j)%10][(a[2]+j)%10][a[3]][a[4]][a[5]]++;
            b[a[1]][(a[2]+j)%10][(a[3]+j)%10][a[4]][a[5]]++;
            b[a[1]][a[2]][(a[3]+j)%10][(a[4]+j)%10][a[5]]++;
            b[a[1]][a[2]][a[3]][(a[4]+j)%10][(a[5]+j)%10]++;
        }
    }
    int ans=0;
    for (int i=0;i<=9;i++){
        for (int j=0;j<=9;j++){
            for (int k=0;k<=9;k++){
                for (int l=0;l<=9;l++){
                    for (int o=0;o<=9;o++){
                        if (b[i][j][k][l][o]==n){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}