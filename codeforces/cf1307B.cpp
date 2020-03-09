#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const double err = 1e-9;
const int INF = 1e9;
typedef pair<int, int> pii;

int testcase = 1;
int n, x;
int a[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> n >> x;
        int mv = 0, flag = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] == x) flag = 1;
            mv = max(mv, a[i]);
        }
        if (flag) cout << 1 << endl;
        else if (x >= mv) cout << x/mv+(x%mv != 0) << endl;
        else cout << 2 << endl;
    }
    return 0;
}

