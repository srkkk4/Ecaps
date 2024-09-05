#include <bits/stdc++.h>
#define MAXN 1003
using namespace std;
int n;
struct dot{
    int x,y,w;
};
dot a[MAXN];
double ansx,ansy,sum;
double count(double x,double y){
    double res=0;
    for (int i=1;i<=n;i++){
        res+=sqrt((a[i].x-x)*(a[i].x-x)+(a[i].y-y)*(a[i].y-y))*a[i].w;
    }
    return res;
}
void SA(){
    double t=2100;
    double dt=0.995;
    while (t>1e-15){
        double nx=ansx+(rand()*2-RAND_MAX)*t;
        double ny=ansy+(rand()*2-RAND_MAX)*t;
        double sum1=count(nx,ny);
        double cha=sum1-sum;
        if (cha<0){
            ansx=nx; ansy=ny;
            sum=sum1;
        } else if (exp(-cha/t)>=(double)rand()/RAND_MAX){
            ansx=nx; ansy=ny;
        }
        t*=dt;
    }
}
int main(){
    srand(time(0));
    cin>>n;
    for (int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].w);
    }
    double sx=0,sy=0;
    for (int i=1;i<=n;i++){
        sx+=a[i].x; sy+=a[i].y;
        // printf("%d %d\n",a[i].x,a[i].y);
    }
    ansx=sx/n; ansy=sy/n;
    // printf("%0.3lf %0.3lf\n",sx,sy);
    sum=count(ansx,ansy);
    SA();
    SA();
    SA();
    printf("%0.3lf %0.3lf",ansx,ansy);
    return 0;
}