#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m;
int a[N][4];
vector<int> add[N<<2], del[N<<2];
typedef pair<int, int> pii;
set<pii> s;

inline void descrete()
{
    vector<int> d;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            d.emplace_back(a[i][j]);
        }
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    m = d.size();
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            a[i][j] = lower_bound(d.begin(), d.end(), a[i][j])-d.begin()+1;
        }
    }
}

inline bool overlap(pii x, pii y)
{
    return max(x.first, y.first) <= min(x.second, y.second);
}

inline bool check(pii cur)
{
    if (!s.size()) return true;
    auto big = s.upper_bound(cur), sma = big;
    if (big != s.end() && overlap(*big, cur)) return false;
    if (sma != s.begin() && overlap(*--sma, cur)) return false;
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a[i][j];
        }
    }
    descrete();
    for (int i = 1; i <= n; ++i) {
        add[a[i][0]].emplace_back(i);
        del[a[i][1]+1].emplace_back(i);
    }
    for (int i = 1; i <= m+1; ++i) {
        for (int j : del[i]) s.erase({a[j][2], a[j][3]});
        for (int j : add[i]) {
            pii cur = {a[j][2], a[j][3]};
            if (!check(cur)) {
                cout << "NO" << endl;
                return 0;
            }
            s.insert(cur);
        }
    }
    cout << "YES" << endl;
    return 0;
}
