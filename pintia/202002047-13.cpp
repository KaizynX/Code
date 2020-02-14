#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, m, k, top;
int a[N], vis[N], sta[N];

int main()
{
    cin >> n >> m >> k;
    while (k--) {
        int now = 1;
        top = 0;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            if (a[i] == now) {
                ++now;
                while (top && sta[top] == now) {
                    --top;
                    ++now;
                }
                if (top && vis[now]) break;
            } else {
                sta[++top] = a[i];
                vis[a[i]] = 1;
                if (top > m) break;
            }
        }
        cout << (now > n ? "YES" : "NO") << endl;
    }
    return 0;
}
