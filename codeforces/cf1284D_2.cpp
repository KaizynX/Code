#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m;
int a[N][4];
vector<int> add[N<<2], del[N<<2];
multiset<int> s, e;

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

inline void solve()
{
    s.clear();
    e.clear();
    for (int i = 1; i <= m+1; ++i) {
        add[i].clear();
        del[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        add[a[i][0]].emplace_back(i);
        del[a[i][1]+1].emplace_back(i);
    }
    for (int i = 1; i <= m+1; ++i) {
        for (int j : del[i]) {
            s.erase(s.find(a[j][2]));
            e.erase(e.find(a[j][3]));
        }
        for (int j : add[i]) {
            if (s.size() && (a[j][3] < *s.rbegin() || a[j][2] > *e.begin())) {
                cout << "NO" << endl;
                exit(0);
            }
            s.insert(a[j][2]);
            e.insert(a[j][3]);
        }
    }
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
    solve();
    for (int i = 1; i <= n; ++i) {
        swap(a[i][0], a[i][2]);
        swap(a[i][1], a[i][3]);
    }
    solve();
    cout << "YES" << endl;
    return 0;
}

