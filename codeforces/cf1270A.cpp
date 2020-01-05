#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n, k1, k2, a1, a2;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> k1 >> k2;
        a1 = a2 = 0;
        for (int i = 1, a; i <= k1; ++i) {
            cin >> a;
            a1 = max(a, a1);
        }
        for (int i = 1, a; i <= k2; ++i) {
            cin >> a;
            a2 = max(a, a2);
        }
        cout << (a1 < a2 ? "NO" : "YES") << endl;
    }
    return 0;
}
