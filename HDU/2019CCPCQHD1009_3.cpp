#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;
const int INF = 0x3f3f3f3f;

int dp[N][6], res = INF;
char s[N], a[128][6][4];

inline void fuck(int id, string str)
{
    int tmp[3] = { 0, 1, 2 }, p = 0;
    do {
        for (int i = 0; i < 3; ++i)
            a[id][p][i] = str[tmp[i]];
        ++p;
    } while (next_permutation(tmp, tmp+3));
}

inline void init()
{
    fuck('Y', "QQQ");
    fuck('V', "QQW");
    fuck('G', "QQE");
    fuck('C', "WWW");
    fuck('X', "QWW");
    fuck('Z', "WWE");
    fuck('T', "EEE");
    fuck('F', "QEE");
    fuck('D', "WEE");
    fuck('B', "QWE");
}

inline int check(const char s1[], const char s2[])
{
    for (int i = 3; i; --i) {
        int flag = 1;
        for (int j = 3-i, k = 0; j < 3; ++j, ++k) {
            if (s1[j] != s2[k]) {
                flag = 0;
                break;
            }
        }
        if (flag) return i;
    }
    return 0;
}

int main()
{
    init();
    while( scanf("%s", s) != EOF) {
    res = INF;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i < 6; ++i) dp[0][i] = 3;
    int len = strlen(s);
    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 6; ++k) {
                dp[i][j] = min(dp[i][j], dp[i-1][k]+3-check(a[s[i-1]][k], a[s[i]][j]));
            }
        }
    }
    for (int i = 0; i < 6; ++i) res = min(res, dp[len-1][i]+len);
    printf("%d\n", res);
    }
    return 0;
}
