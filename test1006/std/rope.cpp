#include <iostream>
#include <cstdio>

using LL = long long;

const int N = 5010, M = 1e6 + 10, Mod = 998244353;
int n, L, lim, eu[N][N], res[N];
int fact[M], infact[M];

inline void upd(int &x, int y) { if ((x += y) >= Mod) x -= Mod; }

int qpow(int a, int k = Mod - 2)
{
    int res = 1;
    for (; k; k >>= 1, a = (LL) a * a % Mod)
        if (k & 1) res = (LL) res * a % Mod;
    return res;
}

void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < M; ++ i) fact[i] = (LL) fact[i - 1] * i % Mod;
    infact[M - 1] = qpow(fact[M - 1]);
    for (int i = M - 2; i; -- i) infact[i] = (LL) infact[i + 1] * (i + 1) % Mod;
}

int C(int n, int m) { return n < m || m < 0 ? 0 : fact[n] * (LL) infact[m] % Mod * infact[n - m] % Mod; }

int main()
{
    freopen("rope.in", "r", stdin);
    freopen("rope.out", "w", stdout);
    init();
    std::cin >> n >> L >> lim;
    eu[1][0] = 1;
    for (int i = 2; i <= n; ++ i)
        for (int j = eu[i][0] = 1; j < i; ++ j)
            eu[i][j] = ((LL) (i - j) * eu[i - 1][j - 1] + (j + 1LL) * eu[i - 1][j]) % Mod;
    // std::cout << eu[5][2] << '\n';
    for (int d = 0; d < n - 1; ++ d)
        for (int i = 0; i <= n && i * lim + d < L; ++ i)
            upd(res[i], eu[n - 1][d] * (LL) C(L - 1 - d - i * lim + n - 1, n - 1) % Mod * C(n, i) % Mod);
    for (int i = n; ~i; -- i)
        for (int j = i + 1; j <= n; ++ j)
            upd(res[i], (LL) (Mod - res[j]) * C(j, i) % Mod);
    int tot = 0;
    for (int i = 0; i <= n; ++ i) upd(tot, res[i]);
    tot = qpow(tot);
    for (int i = 0; i <= n; ++ i) res[i] = (LL) res[i] * tot % Mod;
    for (int i = 0; i <= n; ++ i) printf("%d ", res[i]);
    puts("");
    // int tot = 0, ans = 0;
    // for (int i = 0; i <= n; ++ i) tot += res[i], ans += res[i] * i;
    // printf("%.10lf\n", ans * 1. / tot);
    return 0;
}
