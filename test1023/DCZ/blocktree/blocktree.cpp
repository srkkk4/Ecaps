#include <bits/stdc++.h>
#define MAXN 1000003
using namespace std;
int N,n,m;
vector <int> e[MAXN];
int root;
int dep[MAXN];
int vis[MAXN];
int mxdep=0; int ck[2];
void getDep(int u){
	vis[u]=1;
	mxdep=max(mxdep,dep[u]);
	if (e[u].size()==1){
		ck[dep[u]&1]=1;
	}
	for (int v:e[u]){
		if (vis[v]) continue;
		dep[v]=dep[u]+1;
		getDep(v);
	}
	vis[u]=0;
	return;
}
int fang[MAXN]; int fang_cnt,bian_cnt_mn; long long bian_cnt_mx;
// int mn_sz=INT_MAX;
void dfs(int u,int s){
	vis[u]=1;
	if (dep[u]%2==s){
		fang[u]=1;
		fang_cnt++;
		int sz=e[u].size();
		// mn_sz=min(mn_sz,sz);
		if (sz==2){
			bian_cnt_mn+=1; bian_cnt_mx+=1;
		} else {
			bian_cnt_mn+=sz; bian_cnt_mx+=1ll*sz*(sz-1)/2;
		}
	}
	for (int v:e[u]){
		if (vis[v]) continue;
		dfs(v,s);
	}
	vis[u]=0;
	return;
}
int bian_cnt;
int to[MAXN];
int main(){
	// freopen("ex_blocktree8.in","r",stdin);
	freopen("blocktree.in","r",stdin);
	freopen("blocktree.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>N>>n>>m;
	for (int i=1;i<=N-1;i++){
		int u,v; cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	root=1;
	dep[root]=1;
	getDep(root);
	if (ck[0]&&ck[1]){
		cout<<"No\n";
		return 0;
	}
	if (mxdep&1){ //圆开始
		dfs(root,0);
	} else { //方开始
		dfs(root,1);
	}
	// cerr<<mn_sz<<endl;
	if (N-n!=fang_cnt){
		cout<<"No\n";
		return 0;
	}
	// cerr<<"m:"<<m<<" mn:"<<bian_cnt_mn<<" mx:"<<bian_cnt_mx<<endl;
	if (m<bian_cnt_mn||m>bian_cnt_mx){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
    int cnt=0;
	bian_cnt=m-bian_cnt_mn;
	for (int u=1;u<=N;u++){
		if (!fang[u]){
            to[u]=++cnt;
			cout<<to[u]<<" ";
		} else {
			cout<<0<<" ";
		}
	}
	cout<<endl;
    for (int u=1;u<=N;u++){
        if (fang[u]){
            int sz=e[u].size();
            for (int i=0;i<=sz-2;i++){
                cout<<to[e[u][i]]<<" "<<to[e[u][i+1]]<<endl;
            }
            if (sz!=2) cout<<to[e[u][sz-1]]<<" "<<to[e[u][0]]<<endl;
            if (bian_cnt&&sz>=4){
                bool flag=0;
                for (int i=0;i<=sz-1;i++){
                    for (int j=i+2;j<=sz-1;j++){
                        if (i==0&&j==sz-1) continue;
                        cout<<to[e[u][i]]<<" "<<to[e[u][j]]<<endl;
                        bian_cnt--;
                        if (!bian_cnt){
                            flag=1;
                            break;
                        }
                    }
                    if (flag) break;
                }
            }
        }
    }
	return 0;
}
/*
13 9 12
1 2
1 3
1 4
2 5
2 6
3 7
3 8
3 9
4 10
4 11
10 12
12 13
*/