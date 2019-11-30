#include <bits/stdc++.h>

using namespace std;

const int N = 3e4+7;

int n, m;
int a[N], dp[N];
vector<int> LIS;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n) {
        LIS.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            auto p = lower_bound(LIS.begin(), LIS.end(), a[i]);
            if (p == LIS.end()) LIS.emplace_back(a[i]);
            else *p = a[i];
        }
        cout << LIS.size() << endl;
    }
    return 0;
}
