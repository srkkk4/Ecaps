#include <bits/stdc++.h>
#define MAXN 100003
#define MAXM 14
using namespace std;
int n,m;
/*-----------------FIO------------------*/
inline int read()
{
	char ch = getchar();
	long long res = 0;
	while (!isdigit(ch))
	{
		ch = getchar();
	}
	while (isdigit(ch))
	{
		res = res * 10 + ch - '0';
		ch = getchar();
	}
	return res;
}

void write(long long x)
{
	if (x < 10)
	{
		putchar(x + '0');
		return;
	}
	write(x / 10);
	putchar((x % 10) + '0');
}
/*--------------------------------------*/
struct NUM{
    int num;
    int id;
    bool operator<(const NUM &b)const {
        return num<b.num;
    }
};
NUM tmp[MAXN];
int a[MAXN];
long long dp[MAXM][MAXN];
int cnt;
long long t[MAXM][MAXN];
int lowbit(int x){
    return x&-x;
}
long long SUM(int x,int z){
    long long res=0;
    while (x>=1){
        res=res+t[z][x];
        x-=lowbit(x);
    }
    return res;
}
void ADD(int x,long long y,int z){
    while (x<=cnt){
        t[z][x]=t[z][x]+y;
        x+=lowbit(x);
    }
    return;
}
int main(){
    n=read(); m=read(); m++;
    for (int i=1;i<=n;i++){
        tmp[i].num=read();
        tmp[i].id=i;
    }
    sort(tmp+1,tmp+1+n);
    cnt=0;
    for (int i=1;i<=n;i++){
        if (tmp[i-1].num!=tmp[i].num){
            cnt++;
        }
        a[tmp[i].id]=cnt;
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            dp[i][j]=0;
        }
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=cnt;j++){
            t[i][j]=0;
        }
    }
    for (int j=1;j<=n;j++){
        dp[1][j]=1;
        ADD(a[j],1,1);
        for (int i=2;i<=m;i++){
            dp[i][j]=dp[i][j]+SUM(a[j]-1,i-1);
            ADD(a[j],dp[i][j],i);
        }
    }
    long long ans=0;
    for (int j=1;j<=n;j++){
        ans=ans+dp[m][j];
    }
    cout<<ans<<endl;
    return 0;
}