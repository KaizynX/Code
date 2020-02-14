#include <bits/stdc++.h>

using namespace std;

int T;
long long n, k;

inline long long check(long long x)
{
    if (x > n) return 0;
    long long res = 0, base = 1;
    if (x%2 == 0) res = check(x+1);
    while (x*2 <= n) {
        res += base;
        x <<= 1;
        base <<= 1;
    }
    return res+n-x+1;
}

inline bool f(int i, int x)
{
    while (i) {
        if (i == x) return true;
        if (i&1) i--;
        else i >>= 1;
    }
    return false;
}

inline long long brute(long long x)
{
    long long res = 0;
    for (long long i = x; i <= n; ++i) {
        if (f(i, x)) ++res;
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << i << " " <<  check(i) << " " << brute(i) << endl;
    }
    return 0;
}
