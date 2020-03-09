#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int a, b, c;

inline void solve()
{
    cin >> a >> b >> c;
    int res = INF, resa, resb, resc;
    for (int i = 1, cnt; i <= 20000; ++i) {
        for (int j = 1; j*i <= 20000; ++j) {
            int k = c/(j*i),
                cnt = abs(a-i)+abs(i*j-b)+abs(i*j*(k+1)-c);
            if (cnt < res) {
                res = cnt;
                resa = i;
                resb = i*j;
                resc = i*j*(k+1);
            }
            if (!k) continue;
            cnt = abs(a-i)+abs(i*j-b)+abs(i*j*k-c);
            if (cnt < res) {
                res = cnt;
                resa = i;
                resb = i*j;
                resc = i*j*k;
            }
        }
    }
    cout << res << endl
         << resa << " " << resb << " " << resc << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}