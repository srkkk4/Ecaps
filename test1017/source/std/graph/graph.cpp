#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
bool be;
constexpr int N = 6e5 + 5;
int n, m, a[N], b[N], pos[N], d[N];
bool vis[N];
vector<pii>e[N];
struct node {
	int a, b, id;
}c[N];
inline int id(int i, int j)
{
	return j * n + i;
}
inline void link(int u, int v, int w)
{
	e[u].emplace_back(v, w);
}
int Dijkstra(int s, int t)
{
	priority_queue<pii, vector<pii>, greater<pii>>q;
	memset(d, 63, sizeof d);
	memset(vis, 0, sizeof vis);
	q.emplace(d[s] = 0, s);
	while (!q.empty()) {
		int u = q.top().second;
		if (vis[u]) continue;
		q.pop();
		for (auto [v, w] : e[u]) {
			if (d[v] > d[u] + w) {
				q.emplace(d[v] = d[u] + w, v);
			}
		}
	}
	return d[t];
}
bool en;
int main()
{
	cerr << (&be - &en) / 1024.0 / 1024 << " MB\n--------------------------------" << endl;
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int cc, T;
	cin >> cc >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= 3 * n; ++i) e[i].clear();
		for (int i = 1; i <= n; ++i) {
			cin >> c[i].a;
			c[i].id = i;
		}
		for (int i = 1; i <= n; ++i) {
			cin >> c[i].b;
		}
		sort(c + 1, c + 1 + n, [](node a, node b) {
			return a.b < b.b;
		});
		for (int i = 1; i <= n; ++i) {
			a[i] = c[i].a, b[i] = c[i].b;
			pos[c[i].id] = i;
		}
		for (int i = 1; i <= n; ++i) {
			link(id(i, 1), id(i, 0), 0);
			link(id(i, 2), id(i, 0), b[i]);
			if (i > 1) {
				link(id(i, 2), id(i - 1, 2), 0);
			}
			if (i < n) {
				link(id(i, 1), id(i + 1, 1), b[i + 1] - b[i]);
			}
			int p = lower_bound(b + 1, b + 1 + n, m - a[i]) - b - 1;
			if (p) {
				link(id(i, 0), id(p, 2), a[i]);
			}
			if (p < n) {
				link(id(i, 0), id(p + 1, 1), a[i] + b[p + 1] - m);
			}
		}
		cout << Dijkstra(id(pos[1], 0), id(pos[n], 0)) << endl;
	}
	return 0;
}