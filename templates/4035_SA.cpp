#include <bits/stdc++.h>
#define MAXN 13
using namespace std;
int n;
double a[MAXN+1][MAXN];
double ans[MAXN];
// double dan;
double count(double now[]){
    double res=0,aver=0;
    double dis1[MAXN+1];
    for (int i=1;i<=n+1;i++){
        dis1[i]=0;
        for (int j=1;j<=n;j++){
            dis1[i]+=(now[j]-a[i][j])*(now[j]-a[i][j]);
        }
        dis1[i]=sqrt(dis1[i]);
        aver+=dis1[i];
    }
    aver/=(n+1);
    for (int i=1;i<=n+1;i++){
        res+=(dis1[i]-aver)*(dis1[i]-aver);
    }
    return res;
}
double dis;
double now[MAXN];
void SA(){
    double t=2000;
    double dt=0.997;
    while (t>1e-15){
        for (int j=1;j<=n;j++){
            now[j]=ans[j]+((rand()*2-RAND_MAX)%10)*t;
        }
        double ndis=count(now);
        // cout<<ndis<<" "<<dis<<endl;
        double cha=ndis-dis;
        if (cha<0){
            for (int j=1;j<=n;j++){
                ans[j]=now[j];
            }
            dis=ndis;
        } else if (exp(-cha/t)>rand()/RAND_MAX){
            for (int j=1;j<=n;j++){
                ans[j]=now[j];
            }
        }
        t*=dt;
        // for (int j=1;j<=n;j++){
        //     printf("%0.3lf ",ans[j]);
        // }
        // cout<<endl;
    }
}
int main(){
    // freopen("4035_SA.out","w",stdout);
    srand(time(0));
    cin>>n;
    for (int i=1;i<=n+1;i++){
        for (int j=1;j<=n;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    for (int j=1;j<=n;j++){
        double sp=0;
        for (int i=1;i<=n+1;i++){
            sp+=a[i][j];
        }
        ans[j]=sp/(n+1);
        // for (int i=1;i<=n+1;i++){
        //     dan+=abs(ans[j]-a[i][j])*abs(ans[j]-a[i][j]);
        // }
        // dan=sqrt(dan);
    }
    // ans[1]=0.5; ans[2]=1.0;
    // for (int j=1;j<=n;j++){
    //     printf("%0.3lf ",ans[j]);
    // }
    // cout<<endl;
    dis=count(ans);
    // printf("%0.3lf\n",dis);
    SA();
    SA();
    SA();
    SA();
    for (int j=1;j<=n;j++){
        printf("%0.3lf ",ans[j]);
    }
    return 0;
}