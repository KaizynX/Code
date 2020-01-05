#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e1+7;

int n;
int a[4], b[4], p[N], v[N][3], t[N][3];
pair<int, int> res;
vector<int> vec;

void solve(int cur)
{
    if (cur > n) {
        vec.clear();
        for (int i = 1; i <= 3; ++i) b[i] = a[i];
        for (int i = 1; i <= n; ++i) {
            if (!p[i]) continue;
            if (b[p[i]] < v[i][p[i]]) continue;
            b[p[i]] -= v[i][p[i]];
            vec.push_back(t[i][p[i]]);
        }
        sort(vec.begin(), vec.end());
        int num = 0, time = 0, sum = 0;
        for (int i = 0; i < (int)vec.size(); ++i) {
            sum += vec[i];
            if (sum > 300) break;
            ++num;
            time += sum;
        }
#ifdef DEBUG
        for (int i = 1; i <= n; ++i) cout << "-" << p[i];
        cout << " " << num << " " << time << endl;
#endif
        res = max(res, make_pair(num, -time));
        return;
    }
    for (int i = 0; i <= 3; ++i) {
        p[cur] = i;
        solve(cur+1);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= 3; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 3; ++j)
            cin >> v[i][j] >> t[i][j];
    }
    solve(1);
    cout << res.first << " " << -res.second << endl;
    return 0;
}

