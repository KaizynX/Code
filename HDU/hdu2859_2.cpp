#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n;
char a[N][N];

int main()
{
    while (scanf("%d", &n) && n) {
        int res = 1;
        for (int i = 0; i < n; ++i)
            scanf("%s", a[i]);
        for (int s = n-1, add = 1; s > 0 && s < 2*n-2;
             s += add, add = -add/abs(add)*(abs(add)+1)) {
            if (min(s, 2*n-2-s)+1 <= res) break;
            for (int i = max(1, s-n+2), j, k, last = 1; i <= s && i < n; ++i) {
                if ((j = s-i) >= n) continue;
                for (k = 1; k <= last; ++k) {
                    if (a[i-k][j] != a[i][j+k]) break;
                }
                last = k;
                res = max(res, last);
            }
        }
        cout << res << endl;
    }
    return 0;
}

