#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int w;
struct BT
{
	ull a[1 << 10];
	void set(ull u)
	{
		memset(a, 0, w >> 3);
		a[0] = u;
	}
	BT operator & (BT T)
	{
		int i;
		BT ans;
		for(i = 0; i < (w >> 6); i++)
			ans.a[i] = a[i] & T.a[i];
		return ans;
	}
	BT operator | (BT T)
	{
		int i;
		BT ans;
		for(i = 0; i < (w >> 6); i++)
			ans.a[i] = a[i] | T.a[i];
		return ans;
	}
	BT operator ^ (BT T)
	{
		int i;
		BT ans;
		for(i = 0; i < (w >> 6); i++)
			ans.a[i] = a[i] ^ T.a[i];
		return ans;
	}
	BT operator ~ ()
	{
		int i;
		BT ans;
		for(i = 0; i < (w >> 6); i++)
			ans.a[i] = ~a[i];
		return ans;
	}
	BT operator << (int d)
	{
		int i, x = d >> 6, y = d & 63;
		BT ans;
		for(i = 0; i < (w >> 6); i++)
		{
			if(d >= ((i + 1) << 6))
			{
				ans.a[i] = 0;
				continue;
			}
			ans.a[i] = a[i - x] << y;
			if(i > x && y)
				ans.a[i] |= a[i - x - 1] >> (64 - y);
		}
		return ans;
	}
	BT operator >> (int d)
	{
		int i, x = d >> 6, y = d & 63;
		BT ans;
		for(i = 0; i < (w >> 6); i++)
		{
			if(i + x >= (w >> 6))
			{
				ans.a[i] = 0;
				continue;
			}
			ans.a[i] = a[i + x] >> y;
			if(i + x < (w >> 6) - 1 && y)
				ans.a[i] |= a[i + x + 1] << (64 - y);
		}
		return ans;
	}
	BT operator + (BT T)
	{
		BT ans;
		int i, o = 0, p;
		for(i = 0; i < (w >> 6); i++)
		{
			p = 0;
			if(a[i] > ~T.a[i])
				p = 1;
			ans.a[i] = a[i] + T.a[i];
			if(o && !(~ans.a[i]))
				p = 1;
			ans.a[i] += o;
			o = p;
		}
		return ans;
	}
	BT operator - (BT T)
	{
		BT ans;
		int i, o = 1, p;
		for(i = 0; i < (w >> 6); i++)
		{
			p = 0;
			if(a[i] > T.a[i])
				p = 1;
			ans.a[i] = a[i] + ~T.a[i];
			if(o && !(~ans.a[i]))
				p = 1;
			ans.a[i] += o;
			o = p;
		}
		return ans;
	}
	ull val()
	{
		return a[0];
	}
	int pos(int x)
	{
		return (a[x >> 6] >> (x & 63)) & 1;
	}
};
const int N = 1e6 + 5;
BT B[105];
string s;
int p[N];
int xp[N], zp[N];
ull yp[N];
int type()
{
	if(s == "+")
		return 1;
	if(s == "-")
		return 2;
	if(s == "~")
		return 3;
	if(s == "=")
		return 4;
	if(s == "&")
		return 5;
	if(s == "|")
		return 6;
	if(s == "^")
		return 7;
	if(s == "<<")
		return 8;
	if(s == ">>")
		return 9;
	quitf(_wa, "invalid operator!");
	return 0;
}
void calc(int t, int k)
{
	if(!t)
	{
		if(k <= 2048)
			quitp(0.24, "valid construction(%d steps)", k);
		quitp(max((64 - 4 * log2(k - 1024)) / 100, 0.1), "valid construction(%d steps)", k);
	}
	if(k > 6400)
		quitp((88 - k / 200.00) / 100, "valid construction(%d steps)", k);
	if(k > 3000)
		quitp((86 - 0.5 * sqrt(k - 2800)) / 100, "valid construction(%d steps)", k);
	if(k <= 514)
		quitf(_ok, "correct(%d steps)", k);
	quitp((6 * log2(33 - k / 100.00) + 71) / 100, "valid construction(%d steps)", k);
}
mt19937_64 rng(time(0));
void work()
{
	int i, j;
	for(i = 0; i < w; i += 64)
		B[0].a[i >> 6] = rng();
}

int main(int argc, char* argv[])
{
    // This command initializes checker environment.
    registerTestlibCmd(argc, argv);
	int t = ouf.readInt(0, 1), T = 10;
	int k = ouf.readInt(0, 1000000), d = 1e9;
	int i, j, u, v;
	int x, z;
	ull y;
	w = (t ? (1 << 16) : (1 << 8));
	if(t && k > 12800)
	{
		quitf(_wa, "too long");
		return 0;
	}
	for(i = 1; i <= k; i++)
	{
		s = ouf.readToken();
		p[i] = type();
		if(p[i] == 3)
		{
			xp[i] = ouf.readInt(0, 100);
			yp[i] = ouf.readInt(0, 100);
			continue;
		}
		if(p[i] == 4)
		{
			xp[i] = ouf.readInt(0, 100);
			yp[i] = ouf.readLong(0, (1ll << 32) - 1);
			continue;
		}
		xp[i] = ouf.readInt(0, 100);
		yp[i] = ouf.readInt(0, 100);
		if(p[i] >= 8)
			zp[i] = ouf.readInt(0, d);
		else
			zp[i] = ouf.readInt(0, 100);
	}
	while(T--)
	{
		for(i = 0; i <= 100; i++)
			B[i].set(0);
		u = v = 0;
		work();
		for(i = 0; i < w; i++)
		{
			u += 2 * B[0].pos(i) - 1;
			v = max(u, v);
		}
		for(i = 1; i <= k; i++)
		{
			x = xp[i];
			y = yp[i];
			z = zp[i];
			if(p[i] == 1)
				B[x] = B[y] + B[z];
			if(p[i] == 2)
				B[x] = B[y] - B[z];
			if(p[i] == 3)
				B[x] = ~B[y];
			if(p[i] == 4)
				B[x].set(y);
			if(p[i] == 5)
				B[x] = B[y] & B[z];
			if(p[i] == 6)
				B[x] = B[y] | B[z];
			if(p[i] == 7)
				B[x] = B[y] ^ B[z];
			if(p[i] == 8)
				B[x] = B[y] << z;
			if(p[i] == 9)
				B[x] = B[y] >> z;
		}
		for(i = 1; i < (w >> 6); i++)
			if(B[0].a[i])
				quitf(_wa, "wrong answer");
		if(B[0].val() != v)
			quitf(_wa, "wrong answer");
	}
	calc(t, k);
	return 0;
}