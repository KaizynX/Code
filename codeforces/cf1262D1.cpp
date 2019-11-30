#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, m;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    long long sum, now;
    vector<int> tmp, cur;
    cin >> m;
    for (int i = 1, k, p; i <= m; ++i) {
        cin >> k >> p;
        cur.clear();
        sum = 0;
        for (int j = 1; j+k-1 <= n; ++j) {
            tmp.clear();
            now = 0;
            for (int l = 0; l < k; ++l) {
                tmp.emplace_back(a[j+l]);
                now += a[j+l];
            }
            if (cur.empty() || now > sum || (now == sum && tmp < cur))
                cur = tmp, sum = now;
        }
        cout << cur[p-1] << endl;
    }
    return 0;
}
