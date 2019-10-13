#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;

int n;
int cnt[42];
long long a, k, res;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        for (int j = 0; j <= 40; ++j) {
            if (a&(1ll<<j)) ++cnt[j];
        }
    }
    for (int j = 0; j <= 40; ++j) {
        if (k < (1ll<<j)) res += cnt[j]*(1ll<<j);
        else res += max(cnt[j], n-cnt[j])*(1ll<<j);
#ifdef DEBUG
        cout << j << " " << res << endl;
#endif
    }
    cout << res << endl;
    return 0;
}
