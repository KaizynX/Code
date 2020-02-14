#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;

int T;
int vis[256], l[256], r[256];
string s;

int main()
{
    cin >> T;
    while (T--) {
        memset(vis, 0, sizeof vis);
        memset(l, 0, sizeof l);
        memset(r, 0, sizeof r);
        cin >> s;
        int root = s[0], flag = 1;
        for (int i = 1, pre = s[0], now; i < (int)s.length(); ++i) {
            now = s[i];
            if ((l[pre] == now && r[now] == pre) || (l[now] == pre && r[pre] == now)) {
                ;
            } else if (!l[pre] && !r[now]) {
                r[now] = pre;
                l[pre] = now;
            } else if (!r[pre] && !l[now]) {
                r[pre] = now;
                l[now] = pre;
            } else {
                flag = 0;
                break;
            }
            pre = now;
        }
        if (!flag) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        while (l[root])
            root = l[root];
        while (root) {
            cout << (char)root;
            vis[root] = 1;
            root = r[root];
        }
        for (int i = 'a'; i <= 'z'; ++i) {
            if (vis[i]) continue;
            cout << (char)i;
        }
        cout << endl;
    }
    return 0;
}
