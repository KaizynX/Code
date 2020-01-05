#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int INF = 2e9+2333333;

int T;
int a[3], b[3];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        int res = INF;
        for (int i = 0; i < 3; ++i) cin >> a[i];
        for (int i0 = -1; i0 <= 1; ++i0)
        for (int i1 = -1; i1 <= 1; ++i1)
        for (int i2 = -1; i2 <= 1; ++i2) {
            b[0] = a[0]+i0;
            b[1] = a[1]+i1;
            b[2] = a[2]+i2;
            res = min(res, abs(b[0]-b[1])+abs(b[0]-b[2])+abs(b[1]-b[2]));
        }
        cout << res << endl;
    }
    return 0;
}
