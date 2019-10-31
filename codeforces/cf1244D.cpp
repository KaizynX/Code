#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
int c[3][N], dp[N][3][3][3], col[N];
vector<int> e[N], st;

int main()
{
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> c[i][j];
        }
    }
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() > 2) {
            cout << -1 << endl;
            return 0;
        }
        if (e[i].size() == 1) {
            st.push_back(i);
        }
    }
    int cur = st[0], nex1 = e[cur][0], nex2 = e[nex1][0];
    if (nex2 == cur) nex2 = e[nex1][1];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            for (int k = 0; k < 3; ++k) {
                if (k == i || k == j) continue;
                dp[nex2][i][j][k] = c[nex2][i]+c[nex1][j]+c[cur][k];
            }
        }
    }
    int last = nex1;
    cur = nex2;
    while (cur != st[1]) {
        int tmp = cur;
        cur = e[cur][0];
        if (cur == last) cur = e[cur][1];
        last = tmp;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) continue;
                for (int k = 0; k < 3; ++k) {
                    if (k == i || k == j) continue;
                    dp[cur][i][j][k] = dp[cur-1][j][k][i]+c[cur][i];
                }
            }
    }
    }
    int res = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            for (int k = 0; k < 3; ++k) {
                if (k == i || k == j) continue;
                res = max(res, dp[st[1]][i][j][k]);
            }
        }
    }
    cout << res << endl;
    return 0;
}
