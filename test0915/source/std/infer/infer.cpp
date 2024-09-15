#include<bits/stdc++.h>
using namespace std;
const long long inf=1e9;
int n,x,y,fm,to,tot=0,d[200005],l[200005],r[200005],dep[100005];
int nd[100005];
long long ans=inf,f[100005][4];
void add(int xx,int yy){
	l[++tot]=r[xx];d[tot]=yy;r[xx]=tot;
}
void gt(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=r[u];i;i=l[i]){
		if(d[i]==fa) continue;
		if(dep[d[i]]){
			if(dep[d[i]]<dep[u]){
				fm=u;to=d[i];
			}
			continue;
		}
		gt(d[i],u);
	}
}
void dfs(int u,int fa){
	f[u][0]=0;f[u][2]=1;
	long long v1=inf,v2=inf;
	for(int i=r[u];i;i=l[i]){
		if(d[i]==fa) continue;
		if(nd[d[i]]!=-1&&nd[u]!=-1) continue;
		dfs(d[i],u);
		f[u][0]+=f[d[i]][1];
		v1=min(v1,f[d[i]][3]-f[d[i]][1]);
		f[u][2]+=f[d[i]][0];
		v2=min(v2,f[d[i]][2]-f[d[i]][0]);
	}
	f[u][1]=f[u][0]+v1;
	f[u][3]=f[u][2]+v2;
	if(nd[u]!=-1){
		if(nd[u]==0){
			f[u][2]=f[u][3]=inf;
		}
		else if(nd[u]==1){
			f[u][1]=f[u][0];
			f[u][0]=f[u][2]=f[u][3]=inf;
		}
		else if(nd[u]==2){
			f[u][0]=f[u][1]=inf;
		}
		else{
			f[u][3]=f[u][2];
			f[u][0]=f[u][1]=f[u][2]=inf;
		}
	}
}
void dd(int v1,int v2){
	nd[fm]=v1;nd[to]=v2;
	for(int i=1;i<=n;i++){
		f[i][0]=f[i][1]=f[i][2]=f[i][3]=inf;
	}
	dfs(1,0);
	ans=min(ans,min(f[1][1],f[1][3]));
}
int main()
{
	freopen("infer.in","r",stdin);
	freopen("infer.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	gt(1,0);
	memset(nd,-1,sizeof(nd));
	dd(0,0);
	dd(1,2);
	dd(2,1);
	dd(3,3);
	if(ans==inf) ans=-1;
	printf("%d",ans);
	return 0;
}
