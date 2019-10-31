#include <bits/stdc++.h>

using namespace std;

const int N = 600+7;
const int M = N*N/2;

int n, m;
vector<int> e[N];
double res;
double dp[N];

inline void calc(int del)
{
    dp[n] = 0;
    for (int i = n-1; i; --i) {
        double sum = 0.0, mx = 0.0;
        int num = e[i].size();
        for (int j : e[i]) {
            sum += dp[j];
            mx = max(mx, dp[j]);
        }
        if (i == del && num >= 2) {
            --num;
            sum -= mx;
        }
        dp[i] = sum/num+1;
    }
    res = min(res, dp[1]);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1, s, t; i <= m; ++i) {
        scanf("%d %d", &s, &t);
        e[s].push_back(t);
    }
    res = 1e12;
    for (int i = 0; i <= n; ++i) calc(i);
    printf("%.10lf\n", res);
    return 0;
}
