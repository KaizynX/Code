#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

long long a, b;
int dp[10][10], pre[10];

inline void init()
{
    for (int j = 0; j <= 9; ++j) dp[0][j] = 1;
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                if (abs(j-k) >= 2) dp[i][j] += dp[i-1][k];
            }
        }
        for (int k = 1; k <= 9; ++k)
            pre[i] += dp[i-1][k];
        pre[i] += pre[i-1];
    }
}


inline long long solve(long long x)
{
    vector<int> v;
    do {
        v.push_back(static_cast<int>(x%10));
        x /= 10;
    } while (x);
    v.push_back(INF);
    long long res = pre[(int)v.size()-2];
    for (int i = (int)v.size()-2; i >= 0; --i) {
        for (int j = 0+(i==(int)v.size()-2); j < v[i]; ++j)
            if (abs(j-v[i+1]) >= 2) res += dp[i][j];
        if (abs(v[i]-v[i+1]) < 2) break;
    }
    return res;
}

int main()
{
    cin >> a >> b;
    init();
    cout << solve(b+1)-solve(a) << endl;
    return 0;
}
