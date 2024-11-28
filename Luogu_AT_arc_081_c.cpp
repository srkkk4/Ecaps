#include <bits/stdc++.h>
#define MAXN 200003
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
using namespace std;
template<class T>void err(const T &x,const char c='\n') {cerr<<x<<c;}
template<class T,class ...Args>void err(const T &x,const Args &...args) {err(x,' '),err(args...);}
bool ST;
int n;
char a[MAXN];
int to[MAXN][30];
int lst[30];
struct SITU{
    int u;
    string s;
};
int vis[MAXN];
void bfs(int s){
    queue <SITU> q;
    q.push({s,""}); vis[s]=1;
    while (!q.empty()){
        SITU now=q.front(); q.pop();
        for (int i=0;i<26;i++){
            int v=to[now.u][i];
            if (!v){
                cout<<now.s+char('a'+i)<<'\n';
                return;
            }
            if (vis[v]) continue;
            vis[v]=1;
            q.push({v,now.s+char('a'+i)});
        }
    }
    return;
}
bool ED;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a+1; n=strlen(a+1);
    for (int i=n;i>=0;i--){
        for (int j=0;j<26;j++) to[i][j]=lst[j];
        lst[a[i]-'a']=i;
    }
    bfs(0);
    return 0;
}