#include <bits/stdc++.h>

using namespace std;

long long n, k;
long long res;

inline long long calc(long long x)
{
    if (x > n) return 0;
    int i = 0;
    while ((x<<1) <= n) x <<= 1, ++i;
    return (1ll<<i)-1+n%(1ll<<(i+1));
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return 0;
    }
    int i = 1;
    res = n;
    for (; (1ll<<i)-1 < k; ++i)
        res >>= 1;
    --i;
    for (long long x = n>>(i-1); x; --x) {
        long long cnt = calc(x);
        if (x%2 == 0) cnt += calc(x+1);
        if (cnt >= k) {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}

