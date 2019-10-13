#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
int cnt[42];
long long a, k, res;
long long mind = -1, dis;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        for (int j = 0; j <= 40; ++j) {
            if (a&(1ll<<j)) ++cnt[j];
        }
    }
    for (int j = 40, flag = 1; j >= 0; --j) {
        if ((1ll<<j) > k) {
            res += cnt[j]*(1ll<<j);
            continue;
        }
        if (flag) {
            int choose = cnt[j] >= n-cnt[j] ? 0 : 1;
            dis = (n-cnt[j]-cnt[j])*(1ll<<j);
            if ((k&(1ll<<j)) && choose == 0) {
                flag = 0;
                res += cnt[j]*(1ll<<j);
            } else if ((choose == 1 && (k&(1ll<<j))) || (choose == 0 && (k&(1ll<<j)) == 0)) {
                res += max(cnt[j], n-cnt[j])*(1ll<<j);
            } else if (choose == 1 && (k&(1ll<<j)) == 0) {
                if (dis >= mind) {
                    flag = 0;
                    res += (n-cnt[j])*(1ll<<j) - mind;
                } else {
                    res += cnt[j]*(1ll<<j);
                }
            }
            if (choose && (mind == -1 || mind > dis)) mind = dis;
        } else {
            res += max(cnt[j], n-cnt[j])*(1ll<<j);
        }
    }
    cout << res << endl;
    return 0;
}
