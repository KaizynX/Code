/*
 * @Author: Kaizyn
 * @Date: 2020-04-11 09:13:16
 * @LastEditTime: 2020-04-11 11:04:02
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

int n;
string str[N], suf[N], pre[N];

string solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> str[i];
    
    int flag = 1;
    string pre_str, suf_str;
    for (int i = 1; i <= n; ++i) {
        int p = str[i].find('*');
        pre[i] = str[i].substr(0, p);
        suf[i] = str[i].substr(p+1);
        if (pre[i].size() > pre_str.size()) pre_str = pre[i];
        if (suf[i].size() > suf_str.size()) suf_str = suf[i];
    }
    #ifdef DEBUG
    cout << pre_str << " " << suf_str << endl;
    #endif
    for (int i = 1; i <= n; ++i) {
        if (pre_str.substr(0, pre[i].size()) != pre[i]) flag = 0;
        if (suf_str.substr(suf_str.size()-suf[i].size()) != suf[i]) flag = 0;
    }
    return (flag ? pre_str+suf_str : "*");
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
/*
3
*abc
abc*
a*c
*/