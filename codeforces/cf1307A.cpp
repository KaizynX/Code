#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const double err = 1e-9;
const int INF = 1e9;
typedef pair<int, int> pii;

int testcase = 1;
int n, d;
int a[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> n >> d >> a[0];
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
            int t = min(d/i, a[i]);
            a[0] += t;
            d -= t*i;
        }
        cout << a[0] << endl;
    }
    return 0;
}
