#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e5+7;

int n, m;
long long res;
int a[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    // i- first place
    for (int i = 1, l, r; i <= n; ++i) {
        l = r = i;
        for (int j = 1; j <= m+1; ++j) {
            l = max(1, l-1);
            r = min(n, r+1);
            if (a[j] == l) ++l;
            if (a[j] == r) --r;
        }
#ifdef DEBUG
        printf("%d:[%d,%d]\n", i, l, r);
#endif
        res += r-l+1;
    }
    cout << res << endl;
    return 0;
}
