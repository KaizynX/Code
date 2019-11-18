#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int M = 1e6+7;

int n, m;
int a[N];
map<int, int> vis;
vector<int> res;

int main()
{
    cin >> n;
    for (int i = 1, cnt = 0; i <= n; ++i) {
        cin >> a[i];
        ++cnt;
        if (a[i] < 0) {
            a[i] = -a[i];
            if (!vis[a[i]]) {
                cout << -1 << endl;
                return 0;
            }
            vis[a[i]] = 0;
            if (--m == 0) {
                res.push_back(cnt);
                cnt = 0;
                vis.clear();
            }
        } else {
            if (vis.count(a[i])) {
                cout << -1 << endl;
                return 0;
            }
            vis[a[i]] = 1;
            ++m;
        }
    }
    if (m) {
        cout << -1 << endl;
        return 0;
    }
    cout << res.size() << endl;
    for (int i : res) cout << i << " ";
    return 0;
}

