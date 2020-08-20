#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, k, t;
int a[N], b[N];

inline bool check(long long mid)
{
    long long kk = k;
    for (int i = 1; i <= n; ++i) {
        long long need = mid*a[i];
        if (need > b[i]) kk -= (need-b[i]);
        if (kk < 0) return false;
    }
    return true;
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        long long l = 0, r = 2e9;
        while (l < r) {
            long long mid = (l+r+1)/2;
            if (check(mid)) l = mid;
            else r = mid-1;
        }
        cout << l << endl;
    }
    return 0;
}
