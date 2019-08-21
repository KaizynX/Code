#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3+7;

int dp[2], a[MAXN][2];
string str, res;

int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        a[i][0] = a[i][1] = 0;
        ++a[i][str[i]-'0'];
        for (int j = i+1; j < str.length(); ++j) {
            if (str[j] == '1') {
                a[i][1] = max(a[i][1]+1, a[i][0]+1);
            } else {
                ++a[i][0];
            }
        }
    }
    //int i = str.length()-1;
    //while (i >= 0 && str[i] == '1') --i, res = '1'+res;
    //while (i >= 0 && str[i] == '0') --i, res = '0'+res;
    for (int i = str.length()-1; i >= 0; --i) {
        if (str[i] == '0') {
            res = '0'+res;
            continue;
        } else {
            char flag = '0';
            dp[1] = 0;
            dp[0] = 1;
            for (int j = i+1; j < str.length(); ++j) {
                if (str[j] == '1') {
                    dp[1] = max(dp[1]+1, dp[0]+1);
                } else {
                    ++dp[0];
                }
                printf("%d:%d %d\n", i, max(dp[0], dp[1]), max(a[i][0], a[i][1]));
                // if (dp[str[j]-'0'] != a[i][str[j]-'0']) {
                if (max(dp[0], dp[1]) != max(a[i][0], a[i][1])) {
                    flag = '1';
                    break;
                }
            }
            res = flag+res;
        }
    }
    cout << res << endl;
    return 0;
}
