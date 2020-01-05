#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, a, b, c, r;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> r;
        if (a > b) swap(a, b);
        if (c+r < a || c-r > b) {
            cout << b-a << endl;
            continue;
        }
        int res = 0;
        if (c-r >= a) {
            res += c-r-a;
        }
        if (c+r <= b) {
            res += b-c-r;
        }
        cout << res << endl;
    }
    return 0;
}
