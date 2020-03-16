/*
 * @Author: Kaizyn
 * @Date: 2020-03-16 19:05:31
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-16 23:35:52
 * @FilePath: \Code\atcoder\panasonic2020E_2.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int p[5], nex[5][N], len[5];
char s[5][N];

inline bool cmp(const char &c1, const char &c2)
{
    return c1 == '?' || c2 == '?' || c1 == c2;
}

inline void GetNext(const char *s, int *nex)
{
    nex[0] = nex[1] = 0;
    for (int i = 2, j = 0, len = strlen(s+1); i <= len; ++i) {
        while (j && !cmp(s[i], s[j+1])) j = nex[j];
        if (cmp(s[i], s[j+1])) ++j;
        nex[i] = j;
    }
}

inline vector<int> kmp(const char *s1, const char *s2, int *nex)
{
    vector<int> res;
    for (int i = 1, j = 0, l1 = strlen(s1+1), l2 = strlen(s2+1); i <= l1; ++i) {
        while (j && !cmp(s1[i], s2[j+1])) j = nex[j];
        if (s1[i] == s2[j+1]) ++j;
        if (j == l2) {
            res.emplace_back(i-l2+1);
            j = nex[j];
        }
    }
    return res;
}

inline void combine(const char *s1, const char *s2, const int &be)
{
    int l1 = strlen(s1+1), l2 = strlen(s2+1), i, j;
    for (i = 1; i < be; ++i) s[3][i] = s1[i];
    for (i = be, j = 1; i <= l1 && j <= l2; ++i, ++j)
        s[3][i] = (s1[i] == '?' ? s2[j] : s1[i]);
    while (i <= l1) s[3][i] = s1[i];
    while (j <= l2) s[3][be+j-1] = s2[i];
    s[3][max(i, be+j-1)] = '\0';
}

signed main()
{
    int res = 0;
    for (int i = 0; i < 3; ++i) {
        scanf("%s", s[i]+1);
        len[i] = strlen(s[i]+1);
        GetNext(s[i], nex[i]);
        res += strlen(s[i]+1);
        p[i] = i;
    }
    do {
        vector<int> v1 = kmp(s[p[0]], s[p[1]], nex[p[1]]);
        for (int i : v1) {
            combine(s[p[0]], s[p[1]], i);
            vector<int> v2 = kmp(s[3], s[p[2]], nex[p[2]]);
            if (!v2.size()) continue;
            #ifdef DEBUG
            printf("%s %s\n", s[3]+1, s[p[2]]);
            #endif
            res = min(res, max((int)strlen(s[3]+1), v2.front()+len[p[2]]-1));
        }
    } while (next_permutation(p, p+3));
    printf("%d\n", res);
    return 0;
}