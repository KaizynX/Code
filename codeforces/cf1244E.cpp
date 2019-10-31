#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;

int n, res;
int a[N];
long long k;
map<int, int> mp;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++mp[a[i]];
    }
    auto l = mp.begin();
    auto r = mp.rbegin();
    while (l->first != r->first) {
        if (l->second <= r->second) {
            auto tmp = l; ++tmp;
#ifdef DEBUG
            cout << l->first << " " << tmp->first << endl;
#endif
            int dif = tmp->first-l->first;
            if (k >= dif*l->second) {
                tmp->second += l->second;
                l = tmp;
                k -= 1ll*dif*l->second;
            } else {
                res = r->first-(l->first+k/l->second);
                break;
            }
        } else {
            auto tmp = r; ++mp;
#ifdef DEBUG
            cout << r->first << " " << tmp->first << endl;
#endif
            int dif = r->first - tmp->first;
            if (k >= dif*r->second) {
                tmp->second += r->second;
                r = tmp;
                k -= 1ll*dif*r->second;
            } else {
                res = r->first-k/r->second - l->first;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
