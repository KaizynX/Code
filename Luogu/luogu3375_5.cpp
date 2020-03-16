/*
 * @Author: Kaizyn
 * @Date: 2020-03-16 20:09:36
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-16 22:46:25
 * @FilePath: \Code\Luogu\luogu3375_5.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

inline void get_next(const string &s, int nex[])
{
    nex[0] = nex[1] = 0;
    for (int i = 1, j = 0; i < (int)s.size(); ++i) {
        while (j && s[i] != s[j]) j = nex[j];
        nex[i+1] = s[i] == s[j] ? ++j : 0;
    }
}

inline void kmp(const string &s1, const string &s2, int nex[])
{
    for (int i = 0, j = 0; i < (int)s1.size(); ++i) {
        while (j && s1[i] != s2[j]) j = nex[j];
        if (s1[i] == s2[j]) ++j;
        if (j == (int)s2.size()) {
            cout << i-s2.size()+2 << endl;
            j = nex[j];
        }
    }
}

int nex[N];
string s1, s2;

signed main()
{
    cin >> s1 >> s2;
    get_next(s2, nex);
    kmp(s1, s2, nex);
    for (int i = 1; i <= (int)s2.size(); ++i)
        cout << nex[i] << " \n"[i==(int)s2.size()];
    return 0;
}
