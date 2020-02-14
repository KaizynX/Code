#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n;
int cnt[N];

int main()
{
    cin >> n;
    for (int i = 1, k, a; i <= n; ++i) {
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            cin >> a;
            ++cnt[a];
        }
    }
    int res = 0;
    for (int i = 1000; i; --i) {
        if (cnt[res] < cnt[i]) res = i;
    }
    cout << res << " " << cnt[res] << endl;
    return 0;
}
