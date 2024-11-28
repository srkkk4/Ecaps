#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
int c,T;
int n,m;
int a[MAXN],b[MAXN];
long long DIS[MAXN];
int vis[MAXN];
struct D{
	int u; 
	long long dis;
	bool operator<(const D &B)const{
		return dis>B.dis;
	}
};
long long MX;
int que[MAXN],cnt;
void dijk(int s){
	priority_queue <D> q;
	memset(vis,0,sizeof vis);
	cnt=0;
	DIS[s]=0; vis[s]=1;
	for (int i=2;i<=n;i++) DIS[i]=(a[1]+b[i])%m;
	for (int i=2;i<=n-1;i++){
		if ((a[1]+b[i])%m<MX) {q.push((D){i,(a[1]+b[i])%m});}
	}
	// for (int i=1;i<=n;i++) if (!vis[i]) que[++cnt]=i;
	while (!q.empty()){
		D now=q.top(); q.pop();
		vis[now.u]=1;
		// cout<<now.u<<endl<<">:";
		for (int v=1;v<=n;v++){
			if (vis[v]) continue;
			// cout<<v<<" ";
			if (now.dis+(a[now.u]+b[v])%m<DIS[v]){
				DIS[v]=now.dis+(a[now.u]+b[v])%m;
				q.push((D){v,DIS[v]});
			}
		}
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while (T--){
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) cin>>b[i];
		MX=(a[1]+b[n])%m;
		dijk(1);
		cout<<DIS[n]<<endl;
	}
	return 0;
}