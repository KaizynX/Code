#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e6+7;

int n, m, res = 2;
int f[N];
string str;

int main()
{
    cin >> n >> m;
    if (n == 1) {
        cin >> str;
        res = 1;
        for (char c : str) {
            if (c == '#') {
                res = 0;
                break;
            }
        }
        cout << res << endl;
        return 0;
    }
    if (m == 1) {
        res = 1;
        for (int i = 1; i <= n; ++i) {
            cin >> str;
            if (str == "#") {
                res = 0;
                break;
            }
        }
        cout << res << endl;
        return 0;
    }
    f[0] = 1;
    for (int i = 1, cnt, cnt2, p = 0; i <= n; ++i) {
        cin >> str;
        if (i > 1) {
            cnt2 = 0;
            for (int j = 0; j < m; ++j) {
                if (f[j] && str[j] == '.')
                    ++cnt2;
            }
            res = min(res, cnt2);
        }

        if (str[0] == '#') f[0] = 0;
        cnt = f[0];
        if ((i == 2) || (i == n && m == 2))
            res = min(res, p+(str[0] == '.'));

        for (int j = 1; j < m; ++j) {
            if (str[j] == '#') f[j] = 0;
            else f[j] = f[j]|f[j-1];
            cnt += f[j];


            if (i == 1 && j == 1)
                p = (str[j] == '.');
            if (i == n-1 && j == m-1)
                p = (str[j] == '#' || f[j] == 0 ? 0 : 1);
            if (i == n && j == m-2)
                res = min(res, p+(str[j] == '#' || f[j] == 0 ? 0 : 1));
        }
        res = min(res, cnt);
#ifdef DEBUG
        for (int j = 0; j < m; ++j) {
            cout << f[j] << " ";
        }
        cout << endl;
#endif
    }
    if (!f[m-1]) res = 0;
    cout << res << endl;
    return 0;
}
