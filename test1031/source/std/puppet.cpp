#include <bits/stdc++.h>
#define file_in(x) (freopen(#x".in", "r", stdin))
#define file_out(x) (freopen(#x".out", "w", stdout))
#define ll long long
#define vi vector
#define pb push_back
#define pr pair <int, int>
#define mk make_pair
#define fi first
#define se second

using namespace std;

char _c; bool _f; template <class T> void IN(T &x) {
  _f = x = 0; while (_c = getchar(), !isdigit(_c)) {if (_c == '-') _f = 1;}
  while (isdigit(_c)) {x = x * 10 + _c - '0', _c = getchar();} if (_f) x = -x;
}

template <class T> void _write(T x) {
  if (x < 0) return putchar('-'), _write(-x), void();
  if (x > 9) _write(x / 10);
  putchar('0' + x % 10);
}
template <class T> void write(T x) {_write(x), putchar('\n');}
template <class T> void write_s(T x) {_write(x), putchar(' ');}
template <class first, class... rest> void write(first fir, rest... res) {
  write_s(fir), write(res...);
}

#define debug(...) (_debug(#__VA_ARGS__, __VA_ARGS__))
template <class T> void _debug(const char *format, T x) {
  cerr << format << " = " << x << endl;
}
template <class first, class... rest>
void _debug(const char *format, first fir, rest... res) {
  while (*format != ',') cerr << *format++;
  cerr << " = " << fir << ',', _debug(format + 1, res...);
}

bool START;

const int N = 1e6 + 5, inf = 1e9;

int n, Q, a[N], s1, s2, f[22][N], up[N], s[N];

bool END;

namespace GenHelper{
    unsigned int z1, z2, z3, z4, b;
    unsigned int rand_(){
		b = ((z1 << 6) ^ z1) >> 13;
		z1 = ((z1 & 4294967294U) << 18) ^ b;
		b = ((z2 << 2) ^ z2) >> 27;
		z2 = ((z2 & 4294967288U) << 2) ^ b;
		b = ((z3 << 13) ^ z3) >> 21;
		z3 = ((z3 & 4294967280U) << 7) ^ b;
		b = ((z4 << 3) ^ z4) >> 12;
		z4 = ((z4 & 4294967168U) << 13) ^ b;
		return (z1 ^ z2 ^ z3 ^ z4);
    }
}using namespace GenHelper;
void srand(unsigned int s1, unsigned int s2){
	z1 = s1; z2 = (~ s1) ^ 0x233333333U; z3 = s2 ^ 0x1234598766U; z4 = (~ s2) + 51;
	return ;
}
int Gen(){
    int a = rand_() & 32767;
    int b = rand_() & 32767;
    return (a * 32768 + b) % (3 * n) + 1;
}

int id(int x, int y) {return 3 * x + y + 1;}

int dep(int x) {return (x - 1) / 3;}

void link(int x, int y) {
  f[0][x] = y; for (int i = 1; i <= 20; ++i) f[i][x] = f[i - 1][f[i - 1][x]];
}

signed main() {
	freopen("puppet.in","r",stdin);
	freopen("puppet.out","w",stdout); IN(n);
  IN(n), IN(Q); for (int i = 1; i < n; ++i) IN(a[i]);
  IN(s1), IN(s2), srand(s1, s2);
  for (int i = 0; i < 3; ++i) up[id(n - 1, i)] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j < 3; ++j) up[id(i, j)] = i;
    for (int j = 0; j < 3; ++j)
      if ((a[i + 1] & (1 << j)) > 0) {
	link(id(i, j), id(i + 1, j)), up[id(i, j)] = up[id(i + 1, j)], s[id(i, j)] = s[id(i + 1, j)];
      }
    for (int j = 0; j < 3; ++j) {
      int mx = 0;
      if ((a[i + 1] & (1 << j)) == 0) {
	for (int k = 0; k < 3; ++k) {
	  if (j != k && (a[i + 1] & (1 << k)) > 0 && up[id(i, k)] > mx) {
	    mx = up[id(i, k)], link(id(i, j), id(i, k)), up[id(i, j)] = i, s[id(i, j)] = s[id(i, k)] + 1;
	  }
	}
      }
    }
  }
  int num = 0; ll res = 0;
  while (Q--) {
    num++;
    int u = Gen(), v = Gen();
    if (u > v) swap(u, v);
    int iu = (u - 1) / 3, iv = (v - 1) / 3;
    if (iu == iv) {
      if (u != v) res ^= (1ll * num);
      continue;
    }
    int U = (u - 1) % 3, V = (v - 1) % 3;
    int x = u;
    for (int i = 20; i >= 0; --i)
      if (f[i][x] && dep(f[i][x]) < dep(v)) x = f[i][x];
    if (dep(x) < dep(v)) x = f[0][x];
    int ans;
    if (x == v) ans = dep(v) - dep(u) + s[u] - s[v];
    else if (s[u] == s[x]) ans = dep(v) - dep(u) + 1;
    else {
      int y = u;
      for (int i = 20; i >= 0; --i)
	if (f[i][y] && dep(f[i][y]) < dep(v) && s[f[i][y]] > s[x])
	  y = f[i][y];
      int iy = (y - 1) / 3;
      if ((y % 3) == (v % 3)) ans = dep(v) - dep(u) + s[u] - s[x] + 1;
      else if (up[id(iy, (v - 1) % 3)] >= iv) ans = dep(v) - dep(u) + s[u] - s[x];
      else ans = dep(v) - dep(u) + s[u] - s[x] + 1;
    }
    res ^= (1ll * num * ans);
  }
  write(res);
  return 0;
}

