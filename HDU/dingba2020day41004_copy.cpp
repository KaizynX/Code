#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int T, n, m, k;
int h[N], t[N], s[N];

inline bool check(int mid)
{
    memset(t, 0, sizeof t);
    for (int i = 1; i <= mid; ++i) ++t[h[i]];
    for (int i = 1; i <= 100000; ++i) s[i] = s[i-1]+t[i];
    for (int i = 1; i+k <= 100000; ++i) {
        if (s[i+k]-s[i-1] >= m) return true;
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; ++i) scanf("%d", h+i);
        int l = m, r = n;
        while (l < r) {
            int mid = (l+r)/2;
            if (check(mid)) r = mid;
            else l = mid+1;
        }
        if (check(l)) cout << l << endl;
        else cout << "impossible" << endl;
    }
    return 0;
}
