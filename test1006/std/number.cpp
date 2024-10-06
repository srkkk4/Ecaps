#include <iostream>
#include <cstdio>
#include <ctime>

using LL = long long;

void work()
{
    LL a, b, n, st;
    scanf("%lld %lld %lld %lld", &n, &a, &b, &st);
    if (n <= st / b) return printf("%lld\n", st -  b * n), void();
    n -= st / b, st %= b;
    LL l = 0, r = n;
    while (l < r)
    {
        LL mid = (l + r) >> 1;
        if ((a * mid + st) / b + mid < n) l = mid + 1;
        else r = mid;
    }
    printf("%lld\n", a * l + st - (n - l) * b);
}

int main()
{
    freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
    int T;
    std::cin >> T;
    while (T --) work();
    std::cerr << clock() << '\n';
    return 0;
}
