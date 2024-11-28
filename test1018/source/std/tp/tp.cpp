#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N = 1e6 + 5;
vector<int> v[N];
int posl[N], posr[N];
int T, a[N], lim[N], pos[N];
int prel[N], prer[N], sufl[N], sufr[N];
bool check(int i, int j)
{
	int l = min(prel[i - 1], sufl[j + 1]);
	int r = max(prer[i - 1], sufr[j + 1]);
	if(l > r || i <= l && r <= j) return 1;
	return 0;
}
int main()
{
	freopen("tp.in", "r", stdin);
	freopen("tp.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n, m, cnt = 0;
		cin >> n;
		gp_hash_table<int, int> mp;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i], pos[i] = 0;
			if(!mp[a[i]]) mp[a[i]] = ++cnt;
			a[i] = mp[a[i]]; lim[i] = n + 1;
			posl[i] = n + 1, posr[i] = 0;
		}
		for(int i = 1; i <= cnt; i++) v[i].clear();
		cin >> m;
		for(int i = 1; i <= m; i++)
		{
			int l, r;
			cin >> l >> r;
			lim[r] = min(lim[r], l);
		}
		int mn = n + 1;
		for(int i = n; i; i--)
		{
			mn = min(mn, lim[i]);
			lim[i] = mn;
		}
		for(int i = 1; i <= n; i++)
		{
			while(pos[a[i]] < v[a[i]].size() && v[a[i]][pos[a[i]]] < lim[i]) pos[a[i]]++;
			if(pos[a[i]] < v[a[i]].size())
			{
				posl[i] = v[a[i]][pos[a[i]]];
				posr[i] = v[a[i]].back();
				if(posl[posl[i]] == n + 1) posl[posl[i]] = i;
				posr[posl[i]] = i;
			}
			v[a[i]].push_back(i);
		}
		prel[0] = n + 1, prer[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			prel[i] = min(prel[i - 1], posl[i]);
			prer[i] = max(prer[i - 1], posr[i]);
		}
		sufl[n + 1] = n + 1; sufr[n + 1] = 0;
		for(int i = n; i; i--)
		{
			sufl[i] = min(sufl[i + 1], posl[i]);
			sufr[i] = max(sufr[i + 1], posr[i]);
		}
		if(prel[n] > prer[n]) {cout << 0 << '\n'; continue;}
		int ans = n;
		for(int r = 1, l = 1; r <= n; r++)
		{
			while(l < r && check(l + 1, r)) l++;
			if(check(l, r)) ans = min(ans, r - l + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}