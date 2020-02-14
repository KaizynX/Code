#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const long long INF = 1e18;

int n, T;
int a[N];

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        long long mv = -INF, now = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        for (int i = 1; i < n; ++i) {
            now += a[i];
            mv = max(mv, now);
            if (now < 0) now = 0;
        }
        now = 0;
        for (int i = 2; i <= n; ++i) {
            now += a[i];
            mv = max(mv , now);
            if (now < 0) now = 0;
        }
        if (mv < sum) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
