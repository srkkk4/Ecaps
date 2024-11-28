#include <bits/stdc++.h>
#define MAXN 1003
using namespace std;
int n,k;
int a[MAXN],b[MAXN];
double c[MAXN];
bool cmp(double A,double B){
    return A>B;
}
bool check(double x){
    for (int i=1;i<=n;i++){
        c[i]=1.0*a[i]-1.0*x*b[i];
    }
    sort(c+1,c+1+n,cmp);
    double res=0;
    for (int i=1;i<=k;i++){
        res+=c[i];
    }
    return res>=0.0;
}
int main(){
    cin>>n>>k;
    while (n!=0||k!=0){
        k=n-k;
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for (int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        double l=0,r=1,mid;
        while (l<r){
            mid=(l+r)/2.0;
            if (check(mid)) l=mid+0.000005;
            else r=mid-0.000005;
        }
        printf("%d\n",(int)(l*100.0+0.5));
        cin>>n>>k;
    }
    return 0;
}