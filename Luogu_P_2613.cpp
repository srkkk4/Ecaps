#include <bits/stdc++.h>
#define MAXN 10003
#define mod 19260817
using namespace std;
char A[MAXN],B[MAXN];
long long a,b;
long long qpow(long long x,long long y){
    long long res=1;
    while (y){
        if (y&1) res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}
int main(){
    cin>>A;
    cin>>B;
    int lena=strlen(A),lenb=strlen(B);
    for (int i=0;i<=lena-1;i++){
        a=(a*10+int(A[i]-'0'))%mod;
    }
    for (int i=0;i<=lenb-1;i++){
        b=(b*10+int(B[i]-'0'))%mod;
    }
    if (b!=0){
        cout<<(qpow(b,mod-2)*a)%mod<<endl;
    } else {
        cout<<"Angry!\n";
    }
    return 0;
}