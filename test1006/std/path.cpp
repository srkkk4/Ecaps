#include <iostream>
#include <cstdio>
#include <queue>
#include <ctime>

namespace FastIO {
    char gc() {
        static char buf[1 << 25], *is = buf, *it = buf;
        if (is == it) is = buf, it = is + fread(buf, 1, 1 << 25, stdin);
        return is == it ? EOF : *is ++;
    }
    char out[1 << 25];
    int len;
    void flush() { fwrite(out, 1, len, stdout), len = 0; }
    void pc(char ch) {
        if (len == 1 << 25) flush();
        out[len ++] = ch;
    }
    struct Flusher {
        ~Flusher() { flush(); }
    } Fls;
    template <class T>
    inline void read(T &x)
    {
        char c, flag = 0;
        while ((c = gc()) < '0' || c > '9') flag = c == '-';
        x = c & 15;
        while ((c = gc()) >= '0' && c <= '9')
            x = (x << 1) + (x << 3) + (c & 15);
        if (flag) x = ~x + 1;
    }
    template <class T, class ...T1>
    inline void read(T &x, T1 &...x1) { read(x), read(x1...); }
    template <class T>
    inline void _put(T x)
    {
        if (x > 9) _put(x / 10);
        pc(x % 10 | 48);
    }
    template <class T>
    inline void write(T x) {
        if (x < 0) pc('-'), x = -x;
        _put(x);
    }
    template <>
    inline void write(char *s) {
        for (; *s; ++ *s) pc(*s);
    }
    template <>
    inline void write(const char *s) {
        for (int i = 0; s[i]; ++ i) pc(s[i]);
    }
    template <>
    inline void write(char ch) { pc(ch); }
    template <class T, class ...T1>
    inline void write(T x, T1 ...x1) { write(x), write(x1...); }
}
using FastIO::read;
using FastIO::write;

using PII = std::pair<int, int>;

const int N = 5e5 + 10;
std::vector<int> g[N];
int n, m, s, b[N], mat[N], a[N];
bool vis[N];

template <class T>
inline bool chkmax(T &x, T y) { return x < y ? x = y, 1 : 0; }
template <class T>
inline bool chkmin(T &x, T y) { return x > y ? x = y, 1 : 0; }

int main()
{
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout); 
    read(n, m, s);
    for (int i = 1; i <= n; ++ i) read(a[i]);
    for (int i = 1; i <= s; ++ i) read(b[i]);
    for (int i = 1, u, v; i <= m; ++ i)
    {
        read(u, v);
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++ i) mat[i] = s + 1;
    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> q;
    q.push({mat[1] = a[1] == b[1], 1});
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (int v : g[x]) {
            int nxt = mat[x] + (a[v] == b[mat[x] + 1]);
            if (nxt < mat[v]) mat[v] = nxt, q.push({mat[v], v});
        }
    }
    for (int i = 1; i <= n; ++ i) write(vis[i] ? mat[i] : -1, ' ');
    std::cerr << clock() << '\n';
    return 0;
}
