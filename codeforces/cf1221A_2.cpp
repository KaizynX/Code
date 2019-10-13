#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int q, n;
int s[N], cnt[32];

int main()
{
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 0; i <= 29; ++i) cnt[i] = 0;
        for (int i = 1, tmp, bit; i <= n; ++i) {
            cin >> s[i];
            tmp = s[i];
            bit = 0;
            while (tmp > 1) {
                ++bit;
                tmp >>= 1;
            }
            ++cnt[bit];
        }
        for (int i = 0; i <= 10; ++i) {
            cnt[i+1] += cnt[i]/2;
        }
        cout << (cnt[11] ? "YES" : "NO") << endl;
    }
    return 0;
}
