#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define g(t1) (t1)
#define rg(t1) (t1 + n)
using namespace std;
const int MAXN = 2e6 + 5, MAXM = 5e6 + 5;
const int INF = 1e9;
int n, m, Q, S, T;

int dep[MAXN], cur[MAXN];

int tot = 1, h[MAXN];
struct edge {
	int to, nxt;
	int val;
} e[MAXM << 1];

void add (int x, int y, int z) {
	e[++tot] = (edge) { y, h[x], z };
	h[x] = tot;
}

queue<int> q; // 不良示范，一定要记得手打队列
int bfs() {
	memset (dep, 0, sizeof (dep));
	q.push (S), dep[S] = 1;
	while (q.size()) {
		int k = q.front(); q.pop();
		for (int u = h[k]; u; u = e[u].nxt)
			if (e[u].val && !dep[e[u].to])
				dep[e[u].to] = dep[k] + 1, q.push (e[u].to);
	} return dep[T];
}

int dfs (int k, int flow) {
	int ans = 0;
	if (k == T) return flow;
	for (int &u = cur[k]; u; u = e[u].nxt) // 当前弧优化
		if (e[u].val && dep[e[u].to] == dep[k] + 1) {
			int ret = dfs (e[u].to, min (flow - ans, e[u].val));
			ans += ret, e[u].val -= ret, e[u^1].val += ret;
			if (ans == flow) return ans; // 这个优化好像也有个名字，不记得了
		} return ans;
}

int Dinic() {
	int ans = 0;
	while (bfs()) {
		memcpy (cur, h, sizeof (cur));
		ans += dfs (S, INF);
	} return ans;
}

int main() {
#ifdef IN
	freopen ("x.in", "r", stdin);
	freopen ("x.out", "w", stdout);
#endif
	int i, j, k;
	int x, y;
	int z;
	scanf ("%d%d%d%d", &n, &m, &S, &T);
	for (i=1; i<=m; ++i) {
		scanf ("%d%d%lld", &x, &y, &z);
		add (x, y, z), add (y, x, 0);
	}
	printf ("%d", Dinic());
	return 0;
}