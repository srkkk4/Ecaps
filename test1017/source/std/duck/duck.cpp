#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;

int n, m;
int a[N + 5];

inline bool check(int x){
	int l = x, r = n * 2;
	while(l <= r){
		if(a[l] + a[r] < m) return 0;
		++ l, -- r;
	}
	return 1;
}

inline int solve(int p){
	int ans = 0;
	int l = 1, r = p - 1;
	while(l <= r){
		ans = max(ans, a[l] + a[r]);
		++ l, -- r;
	}
	l = p, r = n * 2;
	while(l <= r){
		ans = max(ans, a[l] + a[r] - m);
		++ l, -- r;
	}
	return ans;
}

int main(){
	freopen("duck.in", "r", stdin);
	freopen("duck.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n * 2; ++ i) cin >> a[i];
	
	sort(a + 1, a + n * 2 + 1);
	int l = 0, r = n, p = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(2 * mid + 1)){
			r = mid - 1;
			p = 2 * mid + 1;
		}
		else{
			l = mid + 1;
		}
	}
	
	cout << solve(p) << '\n';
	
	return 0;
}
