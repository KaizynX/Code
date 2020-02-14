#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;

int n, m, k;
vector<int> v[3];

int main()
{
    while (cin >> n >> m >> k) {
        for (int i = 0; i < 3; ++i) vector<int>().swap(v[i]);
        for (int i = 1, ai, si; i <= n; ++i) {
            cin >> ai >> si;
            if (si <= 4) v[0].emplace_back(ai);
            else if (si <= 6) v[1].emplace_back(ai);
            else v[2].emplace_back(ai);
        }
        for (int i = 0; i < 3; ++i) {
            sort(v[i].begin(), v[i].end());
            reverse(v[i].begin(), v[i].end());
        }
        int res = 0;
        for (int i0 = 0; i0 <= (int)v[0].size(); ++i0)
        for (int i1 = 0; i1 <= (int)v[1].size() && i1 <= i0; ++i1)
        for (int i2 = 0; i2 <= (int)v[2].size() && i2 <= i0/2; ++i2) {
            int flag = 1;
            if (i0+i1+i2 > k) break;
            multiset<int> tmp;
            for (int i = 0; i < i0; ++i) tmp.insert(v[0][i]);
            for (int i = 0; i < i1; ++i) {
                if (tmp.size() < 1) { flag = 0; break; }
                tmp.erase(tmp.begin());
                tmp.insert(v[1][i]);
            }
            if (!flag) continue;
            for (int i = 0; i < i2; ++i) {
                if (tmp.size() < 2) { flag = 0; break; }
                tmp.erase(tmp.begin());
                tmp.erase(tmp.begin());
                tmp.insert(v[2][i]);
            }
            if (!flag) continue;
            if ((int)tmp.size() <= m) continue;
            int sum = 0, cnt = 0;
            for (auto it = tmp.begin(); cnt+m < (int)tmp.size(); ++cnt, ++it)
                sum += *it;
#ifdef DEBUG
            if (i0 == 4 && i1 == 1 && i2 == 1) {
                puts("****");
                for (int i : tmp) cout << i << " ";
                puts("");
                puts("****");
            }
#endif
            res = max(res, sum);
        }
        cout << res << endl;
    }
    return 0;
}
