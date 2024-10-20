#include <bits/stdc++.h>
using namespace std;
constexpr int p = 1000000007;
const int N = 305;
int n, m, n2, a[N], f[N][N][N >> 1][2], s[2], ans = 1;
int main()
{
	freopen("2475.in","r",stdin);
	freopen("2475.out","w",stdout);
 scanf("%d%d", &n, &m), n2 = n >> 1, s[0] = n2, s[1] = n - s[0];
 for (int i = 1; i <= n; ++i)
 {
 scanf("%d", &a[i]);
 if (a[i])
 --s[a[i] & 1];
 }
 f[0][0][0][1] = f[0][0][0][0] = 1;
 for (int i = 1; i <= n; ++i)
 for (int j = 1; j <= min(i, m); ++j)
 for (int k = 0; k <= min(n2, i); ++k)
 {
 if (!(a[i] & 1) && k)
 f[i][j][k][0] = (f[i - 1][j - 1][k - 1][1] + f[i - 1][j][k - 1]
[0]) % p;
 if ((a[i] & 1) || !a[i])
 f[i][j][k][1] = (f[i - 1][j - 1][k][0] + f[i - 1][j][k][1]) % p;
 }
 for (int i = 2; i <= s[0]; ++i)
 ans = (1ll * ans * i) % p;
 for (int i = 2; i <= s[1]; ++i)
 ans = (1ll * ans * i) % p;
 printf("%d", 1ll * ans * ((f[n][m][n2][0] + f[n][m][n2][1]) % p) % p);
 return 0;
}

