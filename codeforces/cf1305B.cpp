#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

string s;
int vis[N];
vector<vector<int>> res;

inline void solve()
{
    cin >> s;
    while (1) {
        vector<int> cur;
        int l = 0, r = (int)s.size()-1;
        while (l < r) {
            while (l < r && (vis[l] || s[l] == ')')) ++l;
            while (l < r && (vis[r] || s[r] == '(')) --r;
            if (s[l] == '(' && s[r] == ')') {
                cur.emplace_back(l);
                cur.emplace_back(r);
                vis[l] = vis[r] = 1;
                ++l; --r;
            }
        }
        if (!cur.size()) break;
        sort(cur.begin(), cur.end());
        res.emplace_back(cur);
    }
    cout << res.size() << endl;
    for (auto v : res) {
        cout << v.size() << endl;
        for (int i : v) cout << i+1 << " ";
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}
