#include <bits/stdc++.h>

using namespace std;

long long a, b;
int dp[10][10], pow10[10];

inline void init()
{
    pow10[0] = 1;
    for (int i = 1; i <= 9; ++i)
        pow10[i] = pow10[i-1]*10;
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                if (abs(j-k) < 2) dp[i][j] += pow10[i-1];
                else dp[i][j] += dp[i-1][k];
            }
        }
    }
}


inline long long solve(long long x)
{
    long long res = x;
    vector<int> v;
    do {
        v.push_back(static_cast<int>(x%10));
        x /= 10;
    } while (x);
    for (int i = (int)v.size()-1; ; --i) {
        for (int j = 0+(i == (int)v.size()-1); j < v[i]; ++j)
            res -= dp[i][j];
        if (abs(v[i]-v[i-1]) < 2) {
            res -= (i-2 >= 0 ? pow10[i-2] : 1);
            break;
        }
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
