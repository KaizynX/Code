/*
 * @Author: Kaizyn
 * @Date: 2020-04-18 14:29:14
 * @LastEditTime: 2020-04-18 17:00:02
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int k;
int h[3];
string s;
string a[3], cur, res, v[3];

inline void solve()
{
    res = "";
    for (int i = 0; i < 3; ++i) a[i] = "";

    cin >> s >> k;
    for (char &c : s) a[(c-'0')%3] += c;
    for (int i = 0; i < 3; ++i) {
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());
        #ifdef DEBUG
        // cout << a[i] << endl;
        #endif
    }
    if (1) {
        h[0] = h[1] = h[2] = 0;
        cur = "";
        for (int t = 1, id; t*3 <= k; ++t) {
            id = -1;
            for (int i = 0; i < 3; ++i) {
                if (a[i].size()-h[i] < 3) continue;
                v[i] = a[i].substr(h[i], 3);
                if (id == -1 || v[i] > v[id]) id = i;
            }
            if (id==-1) break;
            cur += v[id];
            h[id] += 3;
        }
        if (k-cur.size() <= a[0].size()-h[0]) {
            cur += a[0].substr(h[0], k-cur.size());
            sort(cur.begin(), cur.end());
            reverse(cur.begin(), cur.end());
            if (res < cur) res = cur;
        }
    }
    #ifdef DEBUG
    cout << res << endl;
    #endif
    if (a[1].size() >= 1 && a[2].size() >= 1) {
        h[0] = 0; h[1] = h[2] = 1;
        cur = "";
        cur += a[1].substr(0, 1);
        cur += a[2].substr(0, 1);
        for (int t = 1, id; t*3 <= k-2; ++t) {
            id = -1;
            for (int i = 0; i < 3; ++i) {
                if (a[i].size()-h[i] < 3) continue;
                v[i] = a[i].substr(h[i], 3);
                if (id == -1 || v[i] > v[id]) id = i;
            }
            if (id == -1) break;
            cur += v[id];
            h[id] += 3;
        }
        if (k-cur.size() <= a[0].size()-h[0]) {
            cur += a[0].substr(h[0], k-cur.size());
            sort(cur.begin(), cur.end());
            reverse(cur.begin(), cur.end());
            if (res < cur) res = cur;
        }
    }
    #ifdef DEBUG
    cout << res << endl;
    #endif
    if (a[1].size() >= 2 && a[2].size() >= 2) {
        h[0] = 0; h[1] = h[2] = 2;
        cur = "";
        cur += a[1].substr(0, 2);
        cur += a[2].substr(0, 2);
        for (int t = 1, id; t*3 <= k-4; ++t) {
            id = -1;
            for (int i = 0; i < 3; ++i) {
                if (a[i].size()-h[i] < 3) continue;
                v[i] = a[i].substr(h[i], 3);
                if (id == -1 || v[i] > v[id]) id = i;
            }
            if (id == -1) break;
            cur += v[id];
            h[id] += 3;
        }
        if (k-cur.size() <= a[0].size()-h[0]) {
            cur += a[0].substr(h[0], k-cur.size());
            sort(cur.begin(), cur.end());
            reverse(cur.begin(), cur.end());
            if (res < cur) res = cur;
        }
    }
    if ((int)res.size() == k) {
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}