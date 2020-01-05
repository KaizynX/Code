#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int T, n, hb, tb, hs, ts;
int a[N], qb[N], qs[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        hb = tb = hs = ts = 0;
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            while (hs < ts && a[qs[ts]] >= a[i]+i-qs[ts]) --ts;
            qs[++ts] = i;
            while (hb < tb && a[qb[tb]] <= a[i]-i+qb[tb]) --tb;
            qb[++tb] = i;
            if (abs(a[i]-a[qs[hs+1]]) > i-qs[hs+1]) {
                cout << "YES" << endl;
                cout << qs[hs+1] << " " << i << endl;
                flag = 1;
                break;
            }
            if (abs(a[i]-a[qb[hb+1]]) > i-qb[hb+1]) {
                cout << "YES" << endl;
                cout << qb[hb+1] << " " << i << endl;
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        cout << "NO" << endl;
    }
    return 0;
}
