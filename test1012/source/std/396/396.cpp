#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define RI register int
typedef long long LL;
#define FILEIO(name) freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
using namespace std;
namespace IO
{
  char buf[1000000], *p1 = buf, *p2 = buf;
  inline char gc()
  {
    if (p1 == p2)
      p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin);
    return p1 == p2 ? EOF : *(p1++);
  }
  bool CheckEOF()
  {
    RI ch = gc();
    if (ch == EOF)
      return 1;
    while ((ch < '0' || ch > '9') && ch != '-')
      if ((ch = gc()) == EOF)
        return 1;
    return --p1, 0;
  }
  template <class T>
  inline void read(T &n)
  {
    n = 0;
    RI ch = gc(), f;
    while ((ch < '0' || ch > '9') && ch != '-')
      ch = gc();
    f = (ch == '-' ? ch = gc(), -1 : 1);
    while (ch >= '0' && ch <= '9')
      n = n * 10 + (ch ^ 48), ch = gc();
    n *= f;
  }
  char Of[105], *O1 = Of, *O2 = Of;
  template <class T>
  inline void print(T n, char ch = '\n')
  {
    if (n < 0)
      putchar('-'), n = -n;
    if (n == 0)
      putchar('0');
    while (n)
      *(O1++) = (n % 10) ^ 48, n /= 10;
    while (O1 != O2)
      putchar(*(--O1));
    putchar(ch);
  }
}
using IO ::CheckEOF;
using IO ::print;
using IO ::read;
int const MAXN = 1e6 + 5;
int a[MAXN], p[MAXN], to[MAXN];
int val[MAXN], chg[MAXN];
int tmp[MAXN], vis[MAXN];
int stk[MAXN], top;
int main()
{
  freopen ("396.in", "r", stdin);
  freopen ("396.out", "w", stdout);
  
  while (666)
  {
    if (CheckEOF())
      break;

    int n;
    read(n);
    for (RI i = 1; i <= n; ++i)
      read(a[i]), to[i] = a[i], vis[i] = val[i] = chg[i] = 0;
    for (RI i = 1, x; i <= n; ++i)
      read(x), p[x] = i;
    int flag = 0;
    top = 0;
    for (RI i = 1; i <= n; ++i)
      if (!vis[i])
      {
        int now = i, cnt = 0;
        do
        {
          tmp[++cnt] = now;
          vis[now] = 1;
          now = to[now];
        } while (now != i);
        int pos = p[a[i]];
        int tim = 0;
        now = i;
        while (now != pos && tim <= n)
          ++tim, now = to[now];
        if (tim == n + 1)
        {
          flag = 1;
          break;
        }
        for (pos = 1; pos <= cnt; ++pos)
          if (p[a[tmp[pos]]] != tmp[(pos + tim - 1) % cnt + 1])
            break;
        if (pos != cnt + 1)
        {
          flag = 1;
          break;
        }
        if (chg[cnt] && val[cnt] != tim)
        {
          flag = 1;
          break;
        }
        if (!chg[cnt])
          stk[++top] = cnt;
        val[cnt] = tim, chg[cnt] = 1;
      }
    if (flag)
    {
      puts("No");
      continue;
    }
    for (RI i = 1; i <= top; ++i)
      for (RI j = i + 1; j <= top; ++j)
      {
        int x = stk[i], y = stk[j];
        int tmp = val[y] - val[x];
        if (tmp % __gcd(x, y) != 0)
        {
          flag = 1;
          break;
        }
      }
    if (flag)
    {
      puts("No");
      continue;
    }
    puts("Yes");
  }
  return 0;
}
