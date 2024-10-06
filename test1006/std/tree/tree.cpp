#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>

using LL = long long;

const int N = 1e5 + 10, M = N << 1;
int h[N], e[M], ne[M], w[M], idx;
int nw[N], dfn[N], top[N], son[N], sz[N], fa[N];
int n, m, k, lim, val[N];
LL res;

template <class T>
inline T abs(T x) { return x > 0 ? x : -x; }

struct Segment_Tree {
    struct Node {
        int l, r, mx, mn, lt;
        LL sum;
    } tr[N << 2];

    void pushup(int x) {
        tr[x].mx = std::max(tr[x << 1].mx, tr[x << 1 | 1].mx);
        tr[x].mn = std::min(tr[x << 1].mn, tr[x << 1 | 1].mn);
    }

    void build(int x, int l, int r, int *a)
    {
        tr[x] = {l, r};
        if (l == r) return tr[x].sum = a[l], void();
        int mid = (l + r) >> 1;
        build(x << 1, l, mid, a), build(x << 1 | 1, mid + 1, r, a);
        pushup(x), tr[x].sum = tr[x << 1].sum + tr[x << 1 | 1].sum;
    }

    void update(int x, int c)
    {
        tr[x].mx += c, tr[x].mn += c, tr[x].lt += c;
    }

    void pushdown(int x)
    {
        if (!tr[x].lt) return;
        update(x << 1, tr[x].lt), update(x << 1 | 1, tr[x].lt);
        tr[x].lt = 0;
    }

    LL modify(int x, int l, int r, int c)
    {
        if (tr[x].l > r || tr[x].r < l) return 0;
        if (tr[x].l >= l && tr[x].r <= r) {
            if (tr[x].mn > lim || tr[x].mx < lim) {
                LL t = (tr[x].mx < lim ? 1 : -1) * tr[x].sum;
                return update(x, c), t;
            }
            if (tr[x].mn == lim && tr[x].mx == lim)
                return update(x, c), -c * tr[x].sum;
        }
        pushdown(x);
        LL res = modify(x << 1, l, r, c) + modify(x << 1 | 1, l, r, c);
        return pushup(x), res;
    }
} seg;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void addNode(int x)
{
    while (x)
    {
        int l = dfn[top[x]], r = dfn[x];
        res += seg.modify(1, l, r, 1);
        // LL t = seg.modify(1, l, r, 1);
        // printf("ADD %d %d %lld\n", top[x], x, t);
        // res += t;
        x = fa[top[x]];
    }
}

void delNode(int x)
{
    while (x)
    {
        int l = dfn[top[x]], r = dfn[x];
        res -= seg.modify(1, l, r, -1);
        // LL t = seg.modify(1, l, r, -1);
        // printf("DEL %d %d %lld\n", top[x], x, t);
        // res -= t;
        x = fa[top[x]];
    }
}

void dfs1(int x, int fa = 0)
{
    sz[x] = 1, ::fa[x] = fa;
    for (int i = h[x], v; ~i; i = ne[i])
        if ((v = e[i]) != fa) {
            dfs1(v, x);
            if (sz[v] > sz[son[x]]) son[x] = v;
            sz[x] += sz[v];
        }
}

void dfs2(int x, int tp = 1)
{
    top[x] = tp, nw[dfn[x] = ++ *dfn] = x;
    if (!son[x]) return;
    dfs2(son[x], tp);
    for (int i = h[x], v; ~i; i = ne[i])
        if ((v = e[i]) != fa[x] && v != son[x]) dfs2(v, v);
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    std::cin >> n >> m >> k, lim = k / 2;
    for (int i = 1; i <= n; ++ i) h[i] = -1;
    for (int i = 1, u, v, w; i < n; ++ i)
    {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w), add(v, u, w);
    }
    dfs1(1), dfs2(1);
    for (int x = 1; x <= n; ++ x)
        for (int i = h[x], v; ~i; i = ne[i])
            if ((v = e[i]) != fa[x]) val[dfn[v]] = w[i];
    seg.build(1, 1, n, val);
    for (int i = 1, x; i <= k; ++ i) scanf("%d", &x), addNode(x);
    printf("%lld\n", res * 2);
    for (int i = 1, x, y; i <= m; ++ i)
    {
        scanf("%d %d", &x, &y);
        delNode(x), addNode(y);
        printf("%lld\n", res * 2);
        if (res < 0) std::cerr << "ERROR" << std::endl, exit(0);
    }
    std::cerr << clock() << '\n';
    return 0;
}
