#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+7;

int T, n;
int s[N], d[N], dp[N];

struct Time
{
    int h = 8, m = 0, s = 0;
    Time operator + (int t) {
        this->s += t;
        this->m += s/60;
        this->s %= 60;
        this->h += m/60;
        this->m %= 60;
        return *this;
    }
    Time operator += (int t) { return *this = *this+t; }
    void print() {
        printf("%02d:%02d:%02d ", h%13, m, s);
        puts((h <= 12 ? "am" : "pm"));
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> s[i];
        for (int i = 2; i <= n; ++i) cin >> d[i];
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1]+s[i];
            if (i-2 >= 0) dp[i] = min(dp[i], dp[i-2]+d[i]);
        }
        Time res;
        res += dp[n];
        res.print();
    }
    return 0;
}
