#include <bits/stdc++.h>

using namespace std;

const int N = 4e5+7;
const int INF = 1e9;

int testcase = 1;
int n;
int a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        int minv = INF, maxv = 0, cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            cnt += a[i] == -1;
        }
        a[n+1] = 0;
        if (cnt == n) { cout << 0 << " " << 0 << endl; continue; }
        for (int i = 1; i <= n; ++i) {
            if (a[i] == -1) continue;
            if (a[i-1] == -1 || a[i+1] == -1) {
                minv = min(minv, a[i]);
                maxv = max(maxv, a[i]);
            }
        }
        int k = (minv+maxv)/2, m = 0;
        for (int i = 1; i <= n; ++i) if (a[i] == -1) a[i] = k;
        for (int i = 1; i < n; ++i) m = max(m, abs(a[i]-a[i+1]));
        cout << m << " " << k << endl;
    }
    return 0;
}

