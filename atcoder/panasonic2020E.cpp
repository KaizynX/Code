/*
 * @Author: Kaizyn
 * @Date: 2020-03-16 17:32:41
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-16 19:06:39
 * @FilePath: \Code\atcoder\panasonic2020E.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int res;
int p[4];
string s[4];

inline string check(const string &s1, const int &be, const string &s2)
{
    string str = s1;
    int i, j;
    for (i = be, j = 0; i < (int)s1.size() && j < (int)s2.size(); ++i, ++j) {
        if (s1[i] == '?') str[i] = s2[j];
        if (s1[i] == '?' || s2[j] == '?') continue;
        if (s1[i] != s2[j]) return "";
    }
    if (j < (int)s2.size()) str += s2.substr(j);
    return str;
}

inline void solve()
{
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
        res += s[i].size();
        p[i] = i;
    }
    srand(time(NULL));
    random_shuffle(s, s+3);
    string str1, str2;
    do {
        for (int i = 0; i <= (int)s[p[0]].size(); ++i) {
            str1 = check(s[p[0]], i, s[p[1]]);
            if (!str1.size() || (int)str1.size() >= res) continue;
            for (int j = 0; j <= (int)str1.size(); ++j) {
                str2 = check(str1, j, s[p[2]]);
                if (!str2.size() || (int)str2.size() >= res) continue;
                res = str2.size();
            }
        }
    } while (next_permutation(p, p+3));
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}