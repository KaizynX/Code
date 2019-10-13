#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n, res;
int a[N], sum[4], need[4];

void dfs(int cur, int mp)
{
    if (cur > n) {
        int now = mp-30;
        for (int i = 1; i <= 3; ++i) {
            if (!sum[i]) return;
            now += abs(need[i]-sum[i]);
        }
        res = min(res, now);
        return;
    }

    dfs(cur+1, mp);
    for (int i = 1; i <= 3; ++i) {
        sum[i] += a[cur];
        dfs(cur+1, mp+10);
        sum[i] -= a[cur];
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= 3; ++i) {
        cin >> need[i];
        res += need[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << res << endl;
    return 0;
}
