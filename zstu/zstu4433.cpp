#include <bits/stdc++.h>

using namespace std;

int T, k;

inline int check(int x) {
    int cnt2 = 0, cnt5 = 0;
    for (int i = 2; i <= x; i *= 2)
        cnt2 += x/i;
    for (int i = 5; i <= x; i *= 5)
        cnt5 += x/i;
    return min(cnt2, cnt5);
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> k;
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = (l+r)>>1;
            if (check(mid) < k) l = mid+1;
            else r = mid;
        }
        cout << "Case " << t << ": ";
        if (check(l) == k) cout << l << endl;
        else cout << "impossible" << endl;
    }
    return 0;
}
