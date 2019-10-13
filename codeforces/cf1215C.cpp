#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+7;

int n, na, sa, sb, ans;
string s, t;
vector<pair<int, int> > res;

int main()
{
    cin >> n >> s >> t;
    for (char c : s)
        if (c == 'a') ++na;
    for (char c : t)
        if (c == 'a') ++na;
    if (na&1) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) continue;
        if (s[i] == 'a') {
            if (!sa) sa = i+1;
            else {
                ++ans;
                res.push_back({ sa, i+1 });
                sa = 0;
            }
        }
        else if (s[i] == 'b') {
            if (!sb) sb = i+1;
            else {
                ++ans;
                res.push_back({ sb, i+1 });
                sb = 0;
            }
        }
    }
    if (sa) {
        ans += 2;
        res.push_back({ sa, sa });
        res.push_back({ sa, sb });
    }
    cout << ans << endl;
    for (auto p : res) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
