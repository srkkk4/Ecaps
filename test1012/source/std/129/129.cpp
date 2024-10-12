#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100006
using namespace std;
inline char nc()
{
    static char buf[100000], *i = buf, *j = buf;
    return i == j && (j = (i = buf) + fread(buf, 1, 100000, stdin), i == j) ? EOF : *i++;
}
inline int _read()
{
    char ch = nc();
    int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
struct data
{
    int x, y;
    bool operator<(const data &b) const { return x - y > b.x - b.y; }
} a[maxn];
int n, L, ans, c[maxn], f1[maxn], f2[maxn];
int main()
{
	freopen("129.in","r",stdin);
	freopen("129.out","w",stdout);
    n = _read();
    L = _read();
    bool sub2 = 1, sub3 = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i].x = _read();
        a[i].y = _read();
        if (a[i].y > 0)
            sub2 = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        c[i] = _read();
        if (c[i] > 0)
            sub3 = 0;
    }
    for (int i = 1; i <= n; i++)
        c[i] += c[i - 1];
    sort(a + 1, a + 1 + n);
    if (sub2)
    {
        int s = 0;
        for (int i = 1; i <= n; i++)
        {
            s += a[i].x;
            if (s >= L)
                return printf("%d\n", i), 0;
            if (s <= c[i])
                return printf("-1"), 0;
        }
        printf("-1\n");
    }
    else if (sub3 || n > 5000)
    {
        for (int i = 1; i <= n; i++)
            f1[i] = max(f1[i - 1], a[i].y);
        for (int i = n; i >= 1; i--)
            f2[i] = max(f2[i + 1], a[i].x);
        int s = 0;
        for (int i = 1; i <= n; i++)
        {
            s += a[i].x - a[i].y;
            if (s + f1[i] >= L)
                return printf("%d\n", i), 0;
            else if (s + f2[i + 1] >= L)
                return printf("%d\n", i + 1), 0;
            if (s <= c[i])
                return printf("-1\n"), 0;
        }
    }
    ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int s = 0, t = 0;
        for (int j = 1; j <= n; j++)
            if (j != i)
            {
                s += a[j].x - a[j].y;
                t++;
                if (s <= c[t])
                    break;
                if (s + a[i].x >= L)
                {
                    ans = min(ans, j + (j < i));
                    break;
                }
            }
    }
    if (ans == 1e9)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}
