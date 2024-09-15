#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, k;
int a[N];
vector<bitset<N>> eve;

inline pair<int, int> sol() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	for (int i = 1; i <= k; i++) q.emplace(a[i], i);
	int l = k;
	while (l <= n) {
		int t = q.top().first;
		pair<int, int> u = q.top();
		q.pop();
		q.emplace(u.first + a[++l], u.second);
		if (q.top().first == t && l <= n) {
			eve.emplace_back();
			eve.back().set(u.second);
		}
		while (q.top().first == t && l <= n) {
			u = q.top();
			q.pop();
			q.emplace(u.first + a[++l], u.second);
			eve.back().set(u.second);
		}
	}
	return q.top();
}

signed main() {
	// freopen("interview.in","r",stdin);
	// freopen("interview.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	pair<int, int> x = sol();
	bitset<N> ans;
	ans.set(x.second);
	reverse(eve.begin(), eve.end());
	for (const bitset<N> &i : eve) if ((ans & i).any()) ans |= i;
	cout << x.first << '\n';
	for (int i = 1; i <= k; i++) cout.put(ans[i] | 48);
}
