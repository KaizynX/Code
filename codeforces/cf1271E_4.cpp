#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

long long n, k;

inline long long count_even(long long x) {
    if (!x) return n;
    long long res = 0, base = 2;
    while (x <= n) {
        res += min(n-x+1, base);
        base <<= 1;
        x <<= 1;
    }
    return res;
}

inline long long count_odd(long long x) {
    if (x > n) return 0;
    long long res = 0, base = 1;
    while (x <= n) {
        res += min(n-x+1, base);
        base <<= 1;
        x <<= 1;
    }
    return res;
}

int main()
{
    cin >> n >> k;
    long long l = 0, r = n/2;
    while (l < r) {
        long long mid = (l+r+1)>>1;
#ifdef DEBUG
        cout << mid*2 << " " << count_even(mid*2) << endl;
#endif
        if (count_even(mid*2) >= k) l = mid;
        else r = mid-1;
    }
#ifdef DEBUG
    cout << count_odd(l*2+1) << endl;
#endif
    cout << (count_odd(l*2+1) >= k ? l*2+1 : l*2) << endl;
    return 0;
}
