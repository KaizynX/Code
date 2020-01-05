#include <bits/stdc++.h>

using namespace std;

long long n, k;
long long res;

inline long long calc(long long x)
{
    if (x > n) return 0;
    if (x == 0) return 0;
    if (x == n) return 1;
    int i = 0;
    long long tmp = x;
    while ((x<<1) <= n) x <<= 1, ++i;
    return tmp == n>>i ? n%(1ll<<(i+1)) : (1ll<<(i+1))-1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    long long l = 0, r = n/2;
    while (l < r) {
        long long mid = (l+r+1)>>1;
        if (calc(mid*2+1) >= k) l = mid;
        else r = mid-1;
    }
    res = l*2+1;
    l = 0; r = n/2;
    while (l < r) {
        long long mid = (l+r+1)>>1;
        if (calc(mid*2)+calc(mid*2+1) >= k) l = mid;
        else r = mid-1;
    }
    res = max(res, l*2);
    cout << res << endl;
    return 0;
}
