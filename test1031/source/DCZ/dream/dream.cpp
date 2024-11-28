#include <bits/stdc++.h>
#define MAXN 5003
#define mod 1000000007
#define MAXQ 50003
using namespace std;
int c;
int n,m,Q;
int a[MAXN];
struct DO{
	int l;
	int r;
}D[MAXN];
long long f[MAXN][MAXN];
long long g[MAXN][MAXN];
struct Que{
	int p;
	int v;
}QUE[MAXQ];
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c;
	cin>>n>>m>>Q;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++){
		cin>>D[i].l>>D[i].r;
	}
	if (c>=3&&c<=4){
		int p,v; cin>>p>>v;
		for (int i=1;i<=n;i++){
			f[i][a[i]]=1;
		}
		for (int y=v;y<=v;y++){
			for (int x=1;x<=n;x++){
				g[y][x]=g[y][x-1]+f[x][y];
			}
		}
		for (int i=1;i<=m;i++){
			for (int x=1;x<=n;x++){
				for (int y=v;y<=v;y++){
					f[x][y]=0;
					if (D[i].l<x){
						f[x][y]=(f[x][y]+g[y][n-(x-min(x-1,D[i].r))+1]-g[y][n-x+D[i].l]+mod)%mod;
					}
					if (D[i].r>=x){
						f[x][y]=(f[x][y]+g[y][D[i].r-x+1]-g[y][max(x,D[i].l)-x]+mod)%mod;
					}
				}
			}
			for (int y=v;y<=v;y++){
				g[y][0]=0;
				for (int x=1;x<=n;x++){
					g[y][x]=(g[y][x-1]+f[x][y])%mod;
				}
			}
		}
		cout<<f[p][v]<<endl;
	}
	else if ((c>=1&&c<=2)||(c>=5&&c<=6)){
		for (int i=1;i<=n;i++){
			f[i][a[i]]=1;
		}
		for (int y=1;y<=n;y++){
			for (int x=1;x<=n;x++){
				g[y][x]=g[y][x-1]+f[x][y];
			}
		}
		for (int i=1;i<=m;i++){
			for (int x=1;x<=n;x++){
				int tmp1=n-(x-min(x-1,D[i].r))+1,tmp2=n-x+D[i].l,tmp3=D[i].r-x+1,tmp4=max(x,D[i].l)-x;
				for (int y=1;y<=n;y++){
					f[x][y]=0;
					if (D[i].l<x){
						f[x][y]=(f[x][y]+g[y][tmp1]-g[y][tmp2]+mod)%mod;
					}
					if (D[i].r>=x){
						f[x][y]=(f[x][y]+g[y][tmp3]-g[y][tmp4]+mod)%mod;
					}
				}
			}
			for (int y=1;y<=n;y++){
				g[y][0]=0;
				for (int x=1;x<=n;x++){
					g[y][x]=(g[y][x-1]+f[x][y])%mod;
				}
			}
		}
		for (int i=1;i<=Q;i++){
			int p,v;
			cin>>p>>v;
			cout<<f[p][v]<<endl;
		}
	}
	return 0;
}
/*
0
3 1 3
3 2 1
2 3
1 1
1 2
1 3

*/