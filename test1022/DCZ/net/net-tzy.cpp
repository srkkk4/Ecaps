#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int n,m,h[N],cnt,dep[N],fa[N];
bool vis[N];
int t[N],top,F[N];
char ok;
struct edge{
    int h[N],cnt;
    struct node{
        int to,nxt;
    }a[N*N];
    void add(int u,int v){
        a[++cnt].to=v;
        a[cnt].nxt=h[u];
        h[u]=cnt;
    }
}f,g;

void bfs(int s,bool o){
    queue<int> q;
    q.push(s);dep[s]=1;vis[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=f.h[u];i;i=f.a[i].nxt){
            int v=f.a[i].to;
            if(!vis[v]){
                dep[v]=dep[u]+1;
                fa[v]=u;vis[v]=1;
                g.add(u,v),g.add(v,u);
                if(o) cout<<u<<' '<<v<<'\n';
                q.push(v);
                
            }
        }
    }
    return ;
}
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;F[u]=fa;
    for(int i=g.h[u];i;i=g.a[i].nxt){
        int v=g.a[i].to;if(v==fa) continue;
        dfs(v,u);
    }
}
int check(int x){
    memset(dep,0,sizeof dep);
    memset(vis,0,sizeof vis);
    bfs(x,0);int k=0;
    for(int i=1;i<=n;i++) if(dep[i]>dep[k]) k=i;
    memset(dep,0,sizeof dep);
    dfs(k,0);k=0;g.cnt=0;memset(g.h,0,sizeof g.h);
    for(int i=1;i<=n;i++) if(dep[i]>dep[k]) k=i;
    return dep[k];
}
int ans[N],in[N];
bool cmp(int x,int y){
    return in[x]<in[y];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("net.in","r",stdin);
    freopen("net.out","w",stdout);
    srand(time(0));
    cin>>n;
    if(n<=0){
        for(int i=1;i<=n;i++){
            ans[i]=n+1;
            for(int j=1;j<=n;j++){
                cin>>ok;
                if(ok=='1') f.add(i,j);
            }
        }
        int k=0;ans[0]=n+1;dep[0]=n+1;
        for(int i=1;i<=n;i++){
            ans[i]=check(i);
            if(ans[i]<ans[k]) k=i;
        }
        memset(dep,0,sizeof dep);
        memset(vis,0,sizeof vis);
        bfs(k,1);
    }
    else{
        for(int i=1;i<=n;i++){
            dep[i]=n+1;
            for(int j=1;j<=n;j++){
                cin>>ok;
                if(ok=='1'){
                    in[i]++,in[j]++;
                    f.add(i,j);
                }
            }
            t[i]=i;
        }
        
        sort(t+1,t+n+1,cmp);
        int k=0;
        ans[0]=n+1;dep[0]=n+1;
        for(int i=1;i<=min(100000000/n/n,n);i++){
            ans[t[i]]=check(t[i]);
            if(ans[k]>ans[t[i]]) k=t[i];
            ans[t[n-i+1]]=check(t[n-i+1]);
            if(ans[k]>ans[t[n-i+1]]) k=t[n-i+1];
        }
        memset(dep,0,sizeof dep);
        memset(vis,0,sizeof vis);
        bfs(k,1);
    }
    return 0;
}