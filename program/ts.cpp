#include <bits/stdc++.h>
#define MAXN 500003
using namespace std;
int n,m;
float a[MAXN],t[MAXN];
int lowbit(int x){
    return x&-x;
}
float SUM(int x){
    float add=0;
    for (int p=x;p>0;p-=lowbit(p)){
        add+=t[p];
    }
    return a[x]+add;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        scanf("%f",&a[i]);
    }
    for (int i=1;i<=m;i++){
        int type,x,y;
        float k;
        scanf("%d",&type);
        if (type==1){
            scanf("%d %d %f",&x,&y,&k);
            for (int p=x;p<=n;p=p+lowbit(p)){
                t[p]+=k;
            }
            for (int p=y+1;p<=n;p=p+lowbit(p)){
                t[p]-=k;
            }
        } else if (type==2){
            scanf("%d %d",&x,&y);
            float ans=0;
            for (int j=x;j<=y;j++){
                ans+=SUM(j);
            }
            printf("%0.4lf\n",ans/(float)(y-x+1));
        } else {
            scanf("%d %d",&x,&y);
            float aver=0,sum=0;
            for (int j=x;j<=y;j++){
                sum+=SUM(j);
            }
            aver=sum/(float)(y-x+1);
            float tot=0;
            for (int j=x;j<=y;j++){
                float ai=SUM(j);
                tot+=(ai-aver)*(ai-aver);
            }
            printf("%0.4lf\n",tot/(float)(y-x+1));
        }
    }
    return 0;
}