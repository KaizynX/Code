#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int m, n;
int vis[N];

int main()
{
    cin >> m >> n;
    for (int i = 1, a; i <= m; ++i) {
        cin >> a;
        vis[a] = 1;
    }
    int res = 0;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        if (vis[a]) ++res;
    }
    cout << res << endl;
    return 0;
}
