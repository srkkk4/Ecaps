#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
const int MAXN = 5e3 + 5, MAXM = 1e6 + 5, INF = 1e9;

int n, m, S, T;
int tot = 1, h[MAXN];

int dis[MAXN], W;
int pre[MAXN], vis[MAXN];
queue<int> q;

struct edge {
	int frm, to, nxt;
	int val, w;
} e[MAXM << 2];

void add (int x, int y, int z, int w) {
	e[++tot] = (edge) { x, y, h[x], z, w };
	h[x] = tot;
}

int SPFA() {
	memset (vis, 0, sizeof (vis));
	memset (pre, 0, sizeof (pre));
	memset (dis, 127, sizeof (dis));
	q.push (S), dis[S] = 0;
	
	while (q.size()) {
		int k = q.front(); q.pop();
		vis[k] = 0;
		for (int u = h[k]; u; u = e[u].nxt)
			if (e[u].val && dis[e[u].to] > dis[k] + e[u].w) {
				dis[e[u].to] = dis[k] + e[u].w;
				pre[e[u].to] = u;
				if (!vis[e[u].to])
					q.push (e[u].to), vis[e[u].to] = 1;
			}
	}
	return dis[T] < dis[0];
}

int EK() {
	int ans = 0;
 	while ( SPFA() ) {
		int ret = INF;
		for (int p = T; p != S; p = e[ pre[p] ].frm)
			ret = min ( e[ pre[p] ].val, ret );
		ans += ret;
		for (int p = T; p != S; p = e[ pre[p] ].frm) {
			e[ pre[p] ].val -= ret, e[ pre[p] ^ 1 ].val += ret;
			W += ret * e[ pre[p] ].w;
		}
	}
	return ans;
}

int main() {
#ifdef IN
	freopen ("x.in", "r", stdin);
	freopen ("x.out", "w", stdout);
#endif
	int i,j,k;
	int x, y;
	int z, w;
	scanf ("%d%d%d%d", &n, &m, &S, &T);
	for (i=1; i<=m; ++i) {
		scanf ("%d%d%d%d", &x, &y, &z, &w);
		add (x, y, z, w), add (y, x, 0, -w);
	}

	printf ("%d ", EK());
	printf ("%d", W);	
	return 0;
}
 
