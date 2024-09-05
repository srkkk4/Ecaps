#include <bits/stdc++.h>
#define MAXN 100003
#define MAXK 2000003
using namespace std;
int n;
struct F{
    int a; int b; int c;
    int is_del;
};
F f[MAXN]; int tot=0; int cnt=0;
int t[MAXK],t2[MAXK];
int lowbit(int x){
    return x&-x;
}
void ADD(int x,int y){
    for (int p=x;p<=2000002;p+=lowbit(p)){
        t[p]+=y;
    }
    return;
}
void ADD2(int x,int y){
    for (int p=x;p<=2000002;p+=lowbit(p)){
        t2[p]+=y;
    }
    return;
}
int SUM(int x){
    int res=0;
    for (int p=x;p>=1;p-=lowbit(p)){
        res+=t[p];
    }
    return res;
}
int SUM2(int x){
    int res=0;
    for (int p=x;p>=1;p-=lowbit(p)){
        res+=t2[p];
    }
    return res;
}
int main(){
    cin>>n;
    while (n--){
        string tpye;
        cin>>tpye;
        if (tpye=="Add"){
            int a,b,c;
            cin>>a>>b>>c;
            f[++tot]={a,b,c,0};
            if (a>0){
                int up=floor((c*1.0-b)/a)+1;
                if (up<-1000000) cnt++;
                if (up>=-1000000&&up<=1000000) ADD(up+1000001,1);
            } else if (a<0){
                int dn=ceil((c*1.0-b)/a)-1;
                if (dn>1000000) cnt++;
                if (dn>=-1000000&&dn<=1000000) ADD2(dn+1000001,1);
            } else {
                if (b>c) cnt++;
            }
        } else if (tpye=="Query"){
            int k;
            cin>>k;
            cout<<SUM(k+1000001)+(SUM2(2000002)-SUM2(k+1000001-1))+cnt<<endl;
        } else if (tpye=="Del"){
            int i;
            cin>>i;
            if (f[i].is_del) continue;
            f[i].is_del=1;
            if (f[i].a>0){
                int up=floor((f[i].c*1.0-f[i].b)/(f[i].a))+1;
                if (up<-1000000) cnt--;
                if (up>=-1000000&&up<=1000000) ADD(up+1000001,-1);
            } else if (f[i].a<0){
                int dn=ceil((f[i].c*1.0-f[i].b)/(f[i].a))-1;
                if (dn>1000000) cnt--;
                if (dn>=-1000000&&dn<=1000000) ADD2(dn+1000001,-1);
            } else {
                if (f[i].b>f[i].c) cnt--;
            }
        }
    }
    return 0;
}