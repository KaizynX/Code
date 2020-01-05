#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int T, n, m;
int a[N], b[N], p[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            p[a[i]] = i;
        }
        long long res = 0;
        for (int i = 1, flag = 0; i <= m; ++i) {
            cin >> b[i];
            if (p[b[i]] <= flag) ++res;
            else {
                res += 2*(p[b[i]]-i)+1;
                flag = p[b[i]];
            }
        }
        cout << res << endl;
    }
    return 0;
}
