#include <bits/stdc++.h>
#define MAXM 3
using namespace std;
struct Matrix{
    int a[MAXM][MAXM];
    Matrix() { memset(a,0,sizeof a); }
    Matrix operator*(const Matrix &b) const{
        Matrix res;
        for (int i=1;i<=MAXM;i++){
            for (int j=1;j<=MAXM;j++){
                for (int k=1;k<=MAXM;k++){
                    res.a[i][j]=res.a[i][j]+a[i][k]*b.a[k][j];
                }
            }
        }
        return res;
    }
}A,B;
void init(){
    A.a[1][1]=1;B.a[1][1]=1;
}
int main(){
    init();
    Matrix C=A*B;
    cout<<C.a[1][1];
    return 0;
}