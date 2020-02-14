#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, m, k;
vector<int> a[3];

int main()
{
    while (cin >> n >> m >> k) {
        for (int i = 0; i < 3; ++i) vector<int>().swap(a[i]);
        for (int i = 1, ai, si; i <= n; ++i) {
            cin >> ai >> si;
            if (si <= 4) a[0].emplace_back(ai);
            else if (si <= 6) a[1].emplace_back(ai);
            else a[2].emplace_back(ai);
        }
        for (int i = 0; i < 3; ++i) {
            sort(a[i].begin(), a[i].end());
            reverse(a[i].begin(), a[i].end());
        }
        int res = 0;
        for (int i1 = 0; i1 <= (int)a[1].size(); ++i1) {
            for (int i2 = 0; i2 <= (int)a[2].size(); ++i2) {
                int i0 = min((int)a[0].size(), k-i1-i2);
                if (i0 < 0 || i0 < i1 || i0-i2 <= m) continue;
                multiset<int> s;
                for (int i = 0; i < i0; ++i) s.insert(a[0][i]);
                for (int i = 0; i < i1; ++i) {
                    s.erase(s.begin());
                    s.insert(a[1][i]);
                }
                int flag = 1;
                for (int i = 0; i < i2; ++i) {
                    if (s.size() < 2) { flag = 0; break; }
                    s.erase(s.begin());
                    s.erase(s.begin());
                    s.insert(a[2][i]);
                }
                if (!flag) continue;
                int i = 0;
                for (auto it = s.begin(); i+m < (int)s.size(); ++it, ++i)
                    res = max(res, *it);
            }
        }
        cout << res << endl;
    }
    return 0;
}
