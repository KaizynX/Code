#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;

int n, m;
int cnt[N], sum[N];

int main()
{
    cin >> n;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        ++cnt[a];
    }
    sort(cnt+1, cnt+N);
    reverse(cnt+1, cnt+N);
    m = 1;
    while (cnt[m+1]) ++m;
    reverse(cnt+1, cnt+m+1);
    for (int i = 1; i <= m; ++i)
        sum[i] = sum[i-1]+cnt[i];

    for (int k = 1, l, r, mid; k <= n; ++k) {
        if (k > m) {
            cout << 0 << endl;
            continue;
        }
        l = 0; r = n;
        while (l < r) {
            mid = (l+r+1)>>1;
            int p = lower_bound(cnt+1, cnt+m+1, mid)-cnt-1;
            if (m-p >= k || sum[p]/(k-m+p) >= mid) l = mid;
            else r = mid-1;
        }
        cout << l << endl;
    }
    return 0;
}
