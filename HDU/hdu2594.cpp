/*
 * @Author: Kaizyn
 * @Date: 2020-03-22 13:35:17
 * @LastEditTime: 2020-03-22 14:01:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

string s1, s2;

string max_pre_suf(const string &s1, const string &s2)
{
    static const int M1 = 1e9+7, M2 = 1000173169, P = 31;
    static pii pre[N], suf[N], pwp[N];
    int l1 = s1.size(), l2 = s2.size();
    pre[0] = {0, 0};
    for (int i = 1; i <= l1; ++i) {
        pre[i] = {static_cast<int>((1ll*pre[i-1].first*P+s1[i-1]-'a')%M1),
                  static_cast<int>((1ll*pre[i-1].second*P+s1[i-1]-'a')%M2)};
    }
    pwp[0] = {1, 1};
    for (int i = 1; i <= l2; ++i) {
        pwp[i] = {static_cast<int>(1ll*pwp[i-1].first*P%M1),
                  static_cast<int>(1ll*pwp[i-1].second*P%M2)};
    }
    suf[l2+1] = {0, 0}; 
    for (int i = l2; i; --i) {
        suf[i] = {static_cast<int>((1ll*(s2[i-1]-'a')*pwp[l2-i].first+suf[i+1].first)%M1),
                  static_cast<int>((1ll*(s2[i-1]-'a')*pwp[l2-i].second+suf[i+1].second)%M2)};
    }
    for (int i = min(l1, l2); i; --i)
        if (pre[i] == suf[l2-i+1]) return s1.substr(0, i);
    return "";
}

inline void solve()
{
    string res = max_pre_suf(s1, s2);
    if (!res.size()) cout << 0 << endl;
    else cout << res << " " << res.size() << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> s1 >> s2) solve();
    return 0;
}