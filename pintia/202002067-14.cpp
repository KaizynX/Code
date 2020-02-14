#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int M = 1e4+7;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int n, k;
int cnt[M];
int mp[M], mmp[M], tot;

inline int get_id(const int &x)
{
    if (mp[x]) return mp[x];
    mmp[++tot] = x;
    return mp[x] = tot;
}

int main()
{
    cin >> n;
    for (int i = 1, m; i <= n; ++i) {
        cin >> m;
        for (int j = 1, a; j <= m; ++j) {
            cin >> a;
            a = get_id(a);
            ++cnt[a];
        }
    }
    cin >> k;
    for (int i = 1, x, y; i <= k; ++i) {
        cin >> x >> y;
        x = get_id(x);
        y = get_id(y);
    }
    return 0;
}
