/*
 * @Author: Kaizyn
 * @Date: 2020-04-04 09:27:37
 * @LastEditTime: 2020-04-04 09:38:18
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

string s;
int pre[N], suf[N];

string solve()
{
    cin >> s;
    memset(pre, 0, sizeof pre);
    memset(suf, 0, sizeof suf);
    string str = s;
    int n = s.size();
    for (int i = 9; i; --i) {
        for (int j = 0, k; j < n; j = k+1) {
            k = j;
            if (str[j]-'0' != i) continue;
            --str[j];
            while (k+1 < n && str[k+1]-'0' == i) --str[++k];
            ++pre[j]; ++suf[k];
        }
    }
    string res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < pre[i]; ++j) res += '(';
        res += s[i];
        for (int j = 0; j < suf[i]; ++j) res += ')';
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}