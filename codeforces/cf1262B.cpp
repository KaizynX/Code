#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, T;
int a[N], q[N], vis[N];

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            a[i] = vis[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> q[i];
            if (q[i] != q[i-1]) {
                a[i] = q[i];
                vis[q[i]] = 1;
            }
        }
        int flag = 0;
        for (int i = 1, p = 1; i <= n; ++i) {
            if (a[i]) continue;
            while (p <= n && vis[p]) ++p;
            if (p > n || p > q[i]) {
                flag = 1;
                break;
            }
            a[i] = p;
            vis[p] = 1;
        }
        if (flag) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " \n"[i==n];
        }
    }
    return 0;
}

