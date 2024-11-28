#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define IL inline
#define fi first
#define se second
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
		for (; ch > 'z' || ch < 'A'; ch = gh());
		for (; ch <= 'z' && ch >= 'A'; ch = gh()) *x++ = ch;
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
using FIO::rdc;
using FIO::putc;
using FIO::wt;
using LL = long long;
using PII = std::pair<int, int>;
const char mp[55] = {0, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const int N = 1e5 + 100, M = 100 + 100, P = 998244353, K = 20 + 5, A = 52;
int n, m, ne[M], num, lt, ans = 0, tot, as;
PII pos[M];
char s[M], t[M];
struct Mtx
{
    int x[M][M];
    IL int* operator [] (int id){ return x[id]; }
    IL void init()
    {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j) x[i][j] = 0;
    }
} g, a;
IL void adj(int &x){ x += (x >> 31) & P; }
IL Mtx operator * (Mtx x, Mtx y)
{
    Mtx res;
    res.init();
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < m; ++k) adj(res[i][j] += LL(x[i][k]) * y[k][j] % P - P);
    return res;   
}
IL Mtx qpow(Mtx x, int y)
{
    Mtx res = x; --y;
    for (; y; y >>= 1, x = x * x) if (y & 1) res = res * x;
    return res;
}
IL int qpow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1, x = LL(x) * x % P) if (y & 1) res = LL(res) * x % P;
    return res;
}
IL void get_g()
{
    ne[1] = 0;
    for (int i = 2, j = 0; i <= m; ++i)
    {
        while (j && s[i] != s[j + 1]) j = ne[j];
        if (s[i] == s[j + 1]) ++j;
        ne[i] = j;
    }
    for (int i = 0; i < m; ++i)
        for (int j = 1; j <= A; ++j)
        {
            int k = i;
            while (k && s[k + 1] != mp[j]) k = ne[k];
            if (mp[j] == s[k + 1]) ++k;
            if (k < m) ++g[i][k];
        }
}
int main()
{
    freopen("alchemy.in", "r", stdin);
    freopen("alchemy.out", "w", stdout);
    rd(n), rdc(s + 1), rdc(t + 1), rd(num);
    lt = strlen(t + 1), m = strlen(s + 1), tot = n;
    for (int i = 1; i <= num; ++i) 
    {
        rd(pos[i].fi), pos[i].se = pos[i].fi + lt - 1;
        tot -= lt;
    }
    std::sort(pos + 1, pos + 1 + num);
    get_g(), ans = qpow(A, tot), as = 1;
    for (int i = 1, last = 1, len, tt; i <= num + 1; ++i)
    {
        len = (i == num + 1) ? n - last + 1 : pos[i].fi - last;
        if (len >= m)
        {
            a.init(), a[0][0] = 1;
            a = a * qpow(g, len);
            tt = 0;
            for (int j = 0; j < m; ++j) adj(tt += a[0][j] - P);
            as = LL(as) * tt % P;
        }
        else if (len > 0) as = LL(as) * qpow(A, len) % P;
        last = pos[i].se + 1;
    }
    adj(ans -= as);
    ans = LL(ans) * qpow(qpow(A, n), P - 2) % P;
    wt(ans), putc('\n');
    return flus(), 0;
}