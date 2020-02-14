#include <bits/stdc++.h>

using namespace std;

int T;
long long n, k;

inline long long count(long long x) {
    if (!x) return n;
    if (x > n) return 0;
    long long res = 0, base = 2-(x&1);
    while (x <= n) {
        res += min(n-x+1, base);
        base <<= 1;
        x <<= 1;
    }
    return res;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> k;
        long long l = 0, r = n/2, mid;
        while (l < r) {
            mid = (l+r+1)>>1;
            if (count(mid*2) < k) r = mid-1;
            else l = mid;
        }
        cout << (count(2*l+1) >= k ? 2*l+1 : 2*l) << endl;
    }
    return 0;
}
