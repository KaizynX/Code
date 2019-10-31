#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;

int n, m, res;
int a[N], d[N], cnt[N];
long long k;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        d[i] = a[i];
    }
    sort(d+1, d+n+1);
    sort(a+1, a+n+1);
    m = unique(d+1, d+n+1)-d-1;
    for (int i = 1, p = 1; i <= n; ++i) {
        while (a[i] > d[p]) ++p;
        ++cnt[p];
    }
    int l = 1, r = m;
    while (l < r) {
        if (cnt[l] <= cnt[r]) {
            int dif = d[l+1]-d[l];
            if (k >= 1ll*dif*cnt[l]) {
                k -= 1ll*dif*cnt[l];
                cnt[l+1] += cnt[l];
                ++l;
            } else {
                d[l] += static_cast<int>(k/cnt[l]);
                break;
            }
        } else {
            int dif = d[r]-d[r-1];
            if (k >= 1ll*dif*cnt[r]) {
                k -= 1ll*dif*cnt[r];
                cnt[r-1] += cnt[r];
                --r;
            } else {
                d[r] -= static_cast<int>(k/cnt[r]);
                break;
            }
        }
    }
    cout << d[r]-d[l] << endl;
    return 0;
}
