#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int T,tid,n;
int a[MAXN];
vector<int> e[MAXN];
struct node{
	int mn,sum,pos,key;
	bool friend operator<(const node &a,const node &b){
		int da=a.sum>=0,db=b.sum>=0;
		if(da==db){
			if(da&&a.mn!=b.mn)
				return a.mn<b.mn;
			if(!da&&a.sum-a.mn!=b.sum-b.mn)
				return a.sum-a.mn<b.sum-b.mn;
			return a.key<b.key;
		}
		return da<db;
	}
}b[MAXN];
priority_queue<node> q;
bool del[MAXN];
int f[MAXN],fa[MAXN];
void dfs(int x,int dad){
	fa[x]=dad;
	for(int to:e[x])
		if(to!=dad) dfs(to,x);
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int solve(int rot){
	dfs(rot,0);
	int tot=0;
	for(int i=1;i<=n;i++){
		f[i]=i;
		b[i].sum=b[i].mn=a[i];
		b[i].pos=i;
		b[i].key=++tot;
		if(i!=rot) q.push(b[i]);
	}
	while(1){
		while(!q.empty()&&del[q.top().key])
			q.pop();
		if(q.empty()) break;
		int u=find(q.top().pos),fu=find(fa[u]);
		q.pop();
		del[b[fu].key]=1;
		b[fu].mn=min(b[fu].mn,b[fu].sum+b[u].mn);
		b[fu].sum+=b[u].sum;
		b[fu].key=++tot;
		f[u]=fu;
		if(fu!=rot) q.push(b[fu]);
	}
	for(int i=1;i<=tot;i++) del[i]=0;
	return b[rot].mn;
}
signed main(){
	
	freopen("ceremony.in","r",stdin);
	freopen("ceremony.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			cout<<solve(i)<<' ';
		cout<<'\n';
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}
