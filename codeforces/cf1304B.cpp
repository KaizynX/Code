#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const double err = 1e-9;
typedef pair<int, int> pii;

int n, m;
int vis[N];
string s[N], rs[N];
vector<int> res;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        rs[i] = s[i];
        reverse(rs[i].begin(), rs[i].end());
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        for (int j = 1; j <= n; ++j) {
            if (vis[j] || i == j) continue;
            if (s[i] == rs[j]) {
                vis[i] = vis[j] = 1;
                res.emplace_back(i);
            }
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i] || s[i] != rs[i]) continue;
        flag = i;
        break;
    }
    cout << 2*m*res.size()+(flag ? m : 0) << endl;
    for (int i : res) cout << s[i];
    if (flag) cout << s[flag];
    for (int i = res.size()-1; i >= 0; --i) cout << rs[res[i]];
    cout << endl;
    return 0;
}

