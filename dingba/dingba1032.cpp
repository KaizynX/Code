#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, k, m;
int a[N];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int res = 0;
    for (int i = 1, cnt = 0, dis = 0; i <= n+1; ++i) {
        if (i == n+1 || dis+(a[i]-a[i-1])*2 > m) {
            res += cnt;
            break;
        }
        dis += (a[i]-a[i-1])*2;
        if (++cnt == k) {
            res += cnt;
            m -= dis;
            dis = 0;
            cnt = 0;
            a[i] = 0;
        }
    }
    cout << res << endl;
    return 0;
}
