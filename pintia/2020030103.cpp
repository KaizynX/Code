#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

inline void solve()
{
    int k;
    cin >> k;
    int n = k/25+1;
    if (k <= 25) {
        cout << 'a' << (char)('a'+k) << endl;
        return;
    }
    if (k%25 == 0) {
        for (int i = 1; i <= n; ++i) {
            cout << (i&1 ? 'a' : 'z');
        }
        cout << endl;
        return;
    }
    ++n;
    int t = k%25+25;
    if (t%2 == 0) {
        cout << 'a' << (char)('a'+t/2);
        for (int i = 3; i <= n; ++i) {
            cout << (i&1 ? 'a' : 'z');
        }
        cout << endl;
        return;
    } else {
        cout << 'a' << (char)('a'+(t+1)/2);
        for (int i = 3; i < n; ++i) {
            cout << (i&1 ? 'a' : 'z');
        }
        cout << (n&1 ? 'b' : 'y');
        cout << endl;
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}