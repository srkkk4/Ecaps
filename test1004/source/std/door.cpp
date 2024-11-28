#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define IL inline
#define pb push_back
int mp[129];
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
    IL void rdc(char *x)
    {
        char ch = gh();
		for (; ch > 42 || ch < 35 || mp[ch] == -1; ch = gh());
		for (; ch <= 42 && ch >= 35 && mp[ch] != -1; ch = gh())
            *x++ = ch;
        *x = '\0';
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
using FIO::rdc;
const int N = 1e4 + 100, M = 1e4 + 100, A = 4, L = 50, D = 15;
int n, m, ct = 0, tmp[N + M], cc = 0, f[N + M], dep[N + M];
char s[L];
bool KI[N + M];
std::bitset<L * A> ts;
struct Node
{
    std::bitset<L * A> w;
    std::bitset<L * A> x;
    int son[N + M], cs;
    IL void pb(int x){ son[++cs] = x; }
} tr[N + M];
std::vector<int> G[N];
IL void dfs(int x, int fa)
{
    auto t = tr[fa].w << A;
    tr[x].w = tr[x].x | t;
    f[x] = fa, dep[x] = dep[fa] + 1;
    for (int y : G[x]) if (y != fa) tr[x].pb(y), dfs(y, x);
}
IL void dfs2(int x, int fa)
{
    auto t = tr[fa].w << A;
    tr[x].w = tr[x].x | t;
    f[x] = fa, dep[x] = dep[fa] + 1;
    for (int i = tr[x].cs; i; --i) if (!KI[tr[x].son[i]]) dfs2(tr[x].son[i], x);
}
IL void merge(int x, int y)
{
    if (KI[x] || KI[y]) return ;
    if (dep[x] > dep[y]) std::swap(x, y);
    while (dep[y] > dep[x]) y = f[y];
    if (x == y) return ;
    while (x != y)
    {
        KI[x] = true;
        tr[y].x = tr[y].x | tr[x].x;
        for (int i = tr[x].cs; i; --i) if (!KI[tr[x].son[i]]) tr[y].pb(tr[x].son[i]);
        tr[x].cs = 0;
        if (f[y] == f[x])
        {
            x = y, y = f[y];
            cc = 0;
            for (int i = tr[y].cs; i; --i) if (!KI[tr[y].son[i]]) tmp[++cc] = tr[y].son[i];
            tr[y].cs = 0;
            for (int i = 1; i <= cc; ++i) tr[y].pb(tmp[i]);
            break;
        }
        y = f[y], x = f[x];
    }
    dfs2(x, y);
}
int main()
{
    freopen("door.in", "r", stdin);
    freopen("door.out", "w", stdout);
    memset(mp, -1, sizeof mp);
    mp[35] = 0, mp[36] = 1, mp[38] = 2, mp[42] = 3;
    rd(n);
    for (int i = 1; i <= n; ++i)
    {
        rdc(s + 1), ++ct;
        tr[ct].x.set(mp[s[1]]);
    }
    for (int i = 1, u, v; i < n; ++i)
    {
        rd(u), rd(v);
        G[u].pb(v), G[v].pb(u);
    }
    tr[1].w = tr[1].x;
    dfs(1, 0);
    rd(m);
    for (int op, x, y, len; m--; )
    {
        rd(op);
        if (op == 1)
        {
            ++ct;
            rd(x), rdc(s + 1);
            if (KI[x]) 
            {
                KI[ct] = true;
                continue;
            }
            tr[x].pb(ct);
            tr[ct].x.set(mp[s[1]]);
            auto t = tr[x].w << A;
            tr[ct].w = tr[ct].x | t;
            f[ct] = x, dep[ct] = dep[x] + 1;
        }
        else if (op == 2)
        {
            rd(x), rd(y);
            merge(x, y);
        }
        else
        {
            rdc(s + 1), len = strlen(s + 1);
            ts.reset();
            for (int i = len, j = 0; i; --i, ++j) ts.set(j * A + mp[s[i]]);
            for (int i = 1; i <= ct; ++i)
            {
                if (KI[i]) continue;
                if ((ts | tr[i].w) == tr[i].w) wt(i), putc(' ');
            }
            putc('\n');
        }
    }
    return flus(), 0;
}
