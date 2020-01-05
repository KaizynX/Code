#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int T, n;
int a[N<<1];
int mem[N<<1], *p = mem+N;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i <= n+3; ++i) p[i] = p[-i] = -1;
        for (int i = 1; i <= n*2; ++i) {
            cin >> a[i];
            if (a[i] == 2) a[i] = -1;
        }
        p[0] = 0;
        for (int i = 1, now = 0; i <= n; ++i) {
            now += a[i];
            p[now] = i;
        }
        int res = n*2-p[0];
        for (int i = n*2, now = 0; i > n; --i) {
            now += a[i];
            if (p[-now] != -1)
                res = min(res, i-p[-now]-1);
        }
        cout << res << endl;
    }
    return 0;
}
