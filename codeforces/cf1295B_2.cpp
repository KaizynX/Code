#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;

int T, n, x;
int s[N], mem[N<<2], *t = mem+N*2;
string str;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> x >> str;
        int minv = 0, maxv = 0;
        for (int i = -n; i <= n; ++i) t[i] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i-1]+(str[i-1] == '1' ? -1 : 1);
            ++t[s[i]];
            minv = min(minv, s[i]);
            maxv = max(maxv, s[i]);
        }
        if (s[n] == 0 && abs(x) <= n && t[x]) {
            cout << -1 << endl;
            continue;
        }
        if ((s[n] < 0 && maxv < x) || (s[n] > 0 && minv > x)) {
            cout << 0 << endl;
            continue;
        }
        if (s[n] < 0) {
            minv = 0, maxv = 0;
            for (int i = -n; i <= n; ++i) t[i] = 0;
            for (int i = 1; i <= n; ++i) {
                s[i] = s[i-1]+(str[i-1] == '1' ? 1 : -1);
                ++t[s[i]];
                minv = min(minv, s[i]);
                maxv = max(maxv, s[i]);
            }
        }
        // ++t[0];
        if (x > maxv) {
            x -= (x-maxv)/s[n]*s[n];
        }
        int res = x == 0;
        while (x >= minv) {
#ifdef DEBUG
            cout << x << " " << t[x] << endl;
#endif
            res += t[x];
            x -= s[n];
        }
        cout << res << endl;
    }
    return 0;
}
