#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, m, k;
int h[N], a[N];

int main()
{
    cin >> n >> m;
    int sum = 0, minh = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cin >> a[j];
        for (int j = m, last = 0, now = 0; j; --j) {
            now += a[j];
            if (now >= last) {
                ++h[i];
                last = now;
                now = 0;
            }
        }
        sum += h[i];
        minh = min(minh, h[i]);
    }
    cin >> k;
    cout << max(min(sum, k), min(k+minh, sum-minh)) << endl;
    return 0;
}
