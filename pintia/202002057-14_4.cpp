#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e6+7;

string s;
vector<int> vec[N];
long long dp[10][26];
long long vis[10][26][26];

int main()
{
    cin >> s;
    vec[0].emplace_back(0);
    for (int i = 1; i <= (int)s.length(); ++i) {
        for (int j = i-1; j < i+3 && j < (int)s.length(); ++j)
            vec[i].emplace_back(s[j]-'a');
        sort(vec[i].begin(), vec[i].end());
        vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
    }
    dp[0][0] = 1;
    for (int i = 1, c; i <= (int)s.length(); ++i) {
        c = s[i-1]-'a';
        for (int j : vec[i]) {
            dp[i%5][j] = 0;
            for (int k : vec[i-1])
                vis[i%5][j][k] = 0;
        }
        for (int j = i; j >= i-3 && j > 0; --j) {
            for (int k : vec[j-1]) {
                long long tmp = dp[(j-1)%5][k]-vis[j%5][c][k];
                dp[j%5][c] += tmp;
                vis[j%5][c][k] += tmp;
            }
        }
#ifdef DEBUG
        for (int j = i; j >= i-3 && j > 0; --j) {
            for (int k : vec[j]) {
                printf("(%d %c %lld) ", j, k+'a', dp[j%5][k]);
            }
            putchar('\n');
        }
        putchar('\n');
#endif
    }
    long long res = 0;
    for (int i = (int)s.length(); i >= (int)s.length()-3; --i)
        for (int j : vec[i])
            res += dp[i%5][j];
    cout << res << endl;
    return 0;
}

