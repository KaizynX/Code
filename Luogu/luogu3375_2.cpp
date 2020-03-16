/*
 * @Author: Kaizyn
 * @Date: 2020-03-16 19:34:15
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-16 20:09:08
 * @FilePath: \Code\Luogu\luogu3375_2.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

inline void get_next(const string &s, int nex[]) { get_next(s.c_str(), nex); }
inline void get_next(const char *s, int nex[])
{
    nex[0] = nex[1] = 0;
    for (int i = 1, j = 0, l = strlen(s); i < l; ++i) {
        while (j && s[i] != s[j]) j = nex[j];
        nex[i+1] = s[i] == s[j] ? ++j : 0;
    }
}

inline void kmp(const string &s1, const string &s2, int nex[]) { kmp(s1.c_str(), s2.c_str(), nex); }
inline void kmp(const char *s1, const char *s2, int nex[])
{
    for (int i = 0, j = 0, l1 = strlen(s1), l2 = strlen(s2); i < l1; ++i) {
        while (j && s1[i] != s2[j]) j = nex[j];
        if (s1[i] == s2[j]) ++j;
        if (j == l2) {
            cout << i-l2+2 << endl;
            j = nex[j];
        }
    }
}

int nex[N];
char s1[N], s2[N];
// string s1, s2;

signed main()
{
    cin >> s1 >> s2;
    get_next(s2, nex);
    kmp(s1, s2, nex);
    for (int i = 1, l = strlen(s2); i <= l; ++i)
        cout << nex[i] << " \n"[i==l];
    return 0;
}
