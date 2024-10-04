#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define IL inline
namespace FIO
{
	const int L = (1 << 20) + 5;
	int l = 0;
	char buf[L], out[L], *S, *E;
	#define gh() (S == E ? E = (S = buf) + fread(buf, 1, L, stdin), (S == E ? EOF : *S++) : *S++)
	IL void flus(){ fwrite(out, 1, l, stdout), l = 0; }
	IL void chk(){ if (l >= L - 5) flus(); }
	template<class T>
	IL void rd(T &x)
	{
		char ch = gh(), t = 0;
		for (; ch < '0' || ch > '9'; ch = gh()) t |= ch == '-';
		for (x = 0; ch >= '0' && ch <= '9'; ch = gh()) x = x * 10 + (ch ^ 48);
		if (t) x = -x;	
	}
	IL void putc(char x){ out[l++] = x, chk(); }
	template<class T>
	IL void wt(T x)
	{
		if (x < 0) putc('-'), x = -x;
		if (x > 9) wt(x / 10);
		out[l++] = x % 10 + 48, chk();
	}
	#undef gh
} 
using FIO::flus;
using FIO::rd;
using FIO::putc;
using FIO::wt;
using LL = long long;
using PII = std::pair<int, int>;
const int N = 1e4 + 100, K = 100, M = 1e4 + 100, INF = 0x3f3f3f3f, D = 26, P = 998244353;
int n, m, k, cta = 0, ctq = 0, ctt, ans, dep[(N + M) * K * 2], id[(N + M) * K * 2], id_b[(N + M) * K * 2], v[N], la[N], rk[N], ctrk = 0, inv[N], h[(N + M) * K], idx = 0;
struct Node
{
    std::array<int, K> x;
    int tl, tr, id;
    IL int& operator [] (int id){ return x[id]; }
    IL bool operator < (Node &_a){ return x > _a.x; }
} a[N + M];
struct Q{ int l, r, c, ti; } q[M];
struct Edge{ int ne, ver, w; } e[(N + M) * K];
IL void adj(int &x){ x += (x >> 31) & P; }
IL int qpow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1, x = LL(x) * x % P) if (y & 1) res = LL(res) * x % P;
    return res;
}
namespace ST
{
    PII mn[(N + M) * K * 2][D];
    int lg2[(N + M) * K * 2];
    IL void prev()
    {
        lg2[1] = 0;
        for (int i = 2; i <= ctt; ++i) lg2[i] = lg2[i >> 1] + 1;
        for (int i = 1; i <= ctt; ++i) mn[i][0] = {dep[i], id_b[i]};
        int t = std::min(lg2[ctt] + 1, D - 1);
        for (int j = 1; j <= t; ++j)
            for (int i = 1; i <= ctt - (1 << j) + 1; ++i) mn[i][j] = std::min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
    }
    IL int ask(int l, int r)
    {
        int t = lg2[r - l + 1];
        return std::min(mn[l][t], mn[r - (1 << t) + 1][t]).first;
    }
}
IL void add(int x, int y, int z){ e[idx] = {h[x], y, z}, h[x] = idx++; }
IL void ins(int id)
{
    Node &x = a[id];
    int now = cta + 1, o = 0, ne;
    for (int i; o < k; ++o, now = ne)
    {
        for (i = h[now], ne = -1; ~i; i = e[i].ne) if (e[i].w == x[o])
        {
            ne = e[i].ver;
            break;
        }
        if (ne == -1) add(now, ne = ++ctt, x[o]);
    }
    add(now, id, 0);
}
IL void dfs(int x, int depth)
{
    id[x] = ++ctt, id_b[ctt] = x, dep[ctt] = depth;
    for (int i = h[x]; ~i; i = e[i].ne)
    {
        dfs(e[i].ver, depth + 1);
        id_b[++ctt] = x, dep[ctt] = depth;
    }
}
IL int same(int x, int y){ return ST::ask(std::min(id[x], id[y]), std::max(id[x], id[y])) - 2; } //-1 is num of same,-2 is id of wei
IL void work(int l, int r)
{
    int sum = 0;
    for (int o = l; o <= r; ++o) adj(sum += v[a[rk[o]].id] - P);
    sum = LL(sum) * inv[r - l + 1] % P;
    adj(ans += ((LL(r + l) * (r - l + 1)) >> 1) % P * sum % P - P); 
}
int main()
{
    freopen("donut.in", "r", stdin);
    freopen("donut.out", "w", stdout);
    rd(n), rd(k);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = qpow(i, P - 2);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; ++i) rd(v[i]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = k - 1; ~j; --j) rd(a[i][j]);
        a[i].tl = 1, a[i].tr = INF;
        la[i] = a[i].id = i;
    }
    cta = n;
    rd(m);
    for (int i = 1, op, x, y; i <= m; ++i)
    {
        rd(op);
        if (op == 1)
        {
            rd(x), ++cta;
            for (int j = k - 1; ~j; --j) rd(a[cta][j]);
            a[la[x]].tr = i - 1;
            a[cta].tl = i, a[cta].tr = INF;
            a[cta].id = x;
            la[x] = cta;
        }
        else
        {
            ++ctq;
            rd(q[ctq].l), rd(q[ctq].r), rd(x);
            for (int i = 1; i <= x; ++i) rd(y), q[ctq].c = std::max(q[ctq].c, y);
            q[ctq].c = k - q[ctq].c;
            q[ctq].ti = i;
        }
    }
    std::sort(a + 1, a + 1 + cta);
    ctt = cta + 1;
    for (int i = 1; i <= cta; ++i) ins(i);
    ctt = 0;
    dfs(cta + 1, 1), ST::prev();
    for (int i = 1; i <= ctq; ++i)
    {
        ctrk = ans = 0;
        for (int j = 1; j <= cta; ++j) if (a[j].tl <= q[i].ti && a[j].tr >= q[i].ti && a[j].id >= q[i].l && a[j].id <= q[i].r) rk[++ctrk] = j;
        for (int j = 2, last = 1; j <= ctrk + 1; ++j)
            if (j == ctrk + 1)
            {
                work(last, j - 1);
                break;
            }
            else if (same(rk[j], rk[j - 1]) < q[i].c) work(last, j - 1), last = j;
        wt(ans), putc('\n');
    }
    return flus(), 0;
}