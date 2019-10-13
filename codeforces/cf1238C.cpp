#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int q, h, n;
int p[N];

int main()
{
    cin >> q;
    while (q--) {
        int res = 0;
        cin >> h >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }
        int i = 1, t = h;
        while (i < n) {
            if (i+2 <= n && p[i+2] == t-2) {
                i += 2;
                t -= 2;
                continue;
            }
            if (i+1 <= n && p[i+1] == t-1) {
                t -= 2;
                if (t <= 0) break;
                ++res;
                ++i;
            }
            if (i+1 <= n) {
                t = p[i+1]+1;
            }
        }
        cout << res << endl;
    }
    return 0;
}
