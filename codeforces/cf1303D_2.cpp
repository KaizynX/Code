#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int T, m;
int a[N], cnt[64];
map<int, int> mp;
long long n, res;

int main()
{
    for (int i = 0; i <= 30; ++i) mp[1<<i] = i;
    cin >> T;
    while (T--) {
        memset(cnt, 0, sizeof cnt);
        res = 0;

        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> a[i];
            ++cnt[mp[a[i]]];
        }
        for (int i = 0; i < 63; ++i) {
            if ((n>>i)&1) {
                int k = -1;
                for (int j = i; j < 63; ++j)
                    if (cnt[j]) {
                        k = j;
                        break;
                    }
                if (k == -1) break;
                for (int j = k; j > i; --j) {
                    ++res;
                    --cnt[j];
                    cnt[j-1] += 2;
                }
                --cnt[i];
                n -= 1ll<<i;
            }
            cnt[i+1] += cnt[i]/2;
        }
        cout << (n ? -1 : res) << endl;
    }
    return 0;
}
