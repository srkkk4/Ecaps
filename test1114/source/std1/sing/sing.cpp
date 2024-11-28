#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int N=45,mod=998244353;
int qpow(int a,int b){
    int ans=1,base=a;
    while(b){
        if(b&1) ans=ans*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ans;
}
int n,m,k;
bool e[N+1][N+1];
int fac[N+1],inv[N+1];
int A(int n,int m){
    return fac[n]*inv[n-m]%mod;
}
int C(int n,int m){
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int a[N+1][N+1],c[N+1][N+1],w[N+1][N+1];

int col[N+1],pos[N+1],tot;
void flood(int x,int y){
    col[x]=y,pos[tot++]=x;
    for(int to=1;to<=n;to++)
        if(e[x][to]&&col[to]==-1)
            flood(to,y^1);
}

int dp[1<<(N/2)],edge[N+1];
int f[1<<(N/2)],lg[1<<(N/2)];
void add(int &x,int y){
    x=(x+y)%mod;
}
void prepare(){
    for(int i=0;i<k;i++)
        lg[1<<i]=i,f[1<<i]=edge[i];
    for(int i=1;i<(1<<k);i++)
        f[i]=f[i^lowbit(i)]|f[lowbit(i)];
}
int solve1(){
    for(int i=0;i<(1<<k);i++) dp[i]=0;
    dp[0]=1;
    int s=(1<<k)-1;
    for(int mask=0;mask<(1<<k);mask++){
        int vis=f[mask],p=__builtin_popcountll(vis);
        for(int sub=(s^mask);sub;sub^=lowbit(sub)){
            int i=lg[lowbit(sub)],q=__builtin_popcountll(edge[i]^(vis&edge[i]));
            add(dp[mask^(1<<i)],dp[mask]*a[tot-p-1][q-1]);
        }
    }
    return dp[s];
}
int solve2(){
    for(int i=0;i<(1<<k);i++) dp[i]=0;
    dp[0]=1;
    int ans=0,s=(1<<k)-1,t=0,cnt=0;
    for(int i=0;i<tot;i++)
        if(col[pos[i]]==1) t|=(1ll<<pos[i]);
    for(int mask=0;mask<(1<<k);mask++){
        int vis=f[mask],p=__builtin_popcountll(vis);
        int cnt=0,num=tot-p-1;
        cnt=__builtin_popcountll(t^(t&vis));
        if(!cnt) continue;

        for(int sub=(s^mask);sub;sub^=lowbit(sub)){
            int i=lg[lowbit(sub)],q=__builtin_popcountll(edge[i]^(vis&edge[i]));
            add(dp[mask^(1<<i)],dp[mask]*w[p][q]);
        }
        int delta=dp[mask]*c[p+num][p]%mod*fac[num]%mod*cnt%mod;
        if(__builtin_popcountll(mask)&1) ans-=delta;
        else ans+=delta;
    }
    return (ans%mod+mod)%mod;
}
int solve(int fst){
    tot=0;
    flood(fst,0);
    if(tot==1) return 1;
    
    int cnt[2]={0,0};
    for(int i=0;i<tot;i++)
        cnt[col[pos[i]]]++;
    if(cnt[0]>cnt[1]){
        for(int i=0;i<tot;i++) col[pos[i]]^=1;
    }

    k=0;
    for(int i=0;i<tot;i++){
        if(col[pos[i]]==1) continue;
        edge[k]=(1ll<<pos[i]);
        for(int j=0;j<tot;j++)
            if(col[pos[j]]==1&&e[pos[i]][pos[j]])
                edge[k]|=(1ll<<pos[j]);
        k++;
    }

    int ans=0;
    prepare();
    ans+=solve1();
    ans+=solve2();
    return ans%mod;
}
signed main(){
freopen("sing.in","r",stdin);
freopen("sing.out","w",stdout);
    n=read(),m=read();
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=qpow(fac[i],mod-2);
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++) a[i][j]=A(i,j),c[i][j]=C(i,j);
    for(int p=0;p<=n;p++)
        for(int q=1;q<=n;q++) w[p][q]=c[p+q-1][p]*fac[q-1]%mod;

    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        e[u][v]=e[v][u]=1;
    }

    memset(col,-1,sizeof(col));
    int ans=1,num=0;
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            int cnt=solve(i);
            ans=ans*c[n-num][tot]%mod*cnt%mod;
            num+=tot;
        }
    }
    ans=ans*qpow(fac[n],mod-2)%mod;
    cout<<qpow(ans,mod-2);
    return 0;
}
