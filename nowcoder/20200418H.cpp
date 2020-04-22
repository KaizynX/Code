/*
 * @Author: Kaizyn
 * @Date: 2020-04-18 14:29:14
 * @LastEditTime: 2020-04-18 14:48:36
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
vector<int> a[3], cur, res, v[3];

inline void solve()
{
    vector<int>().swap(res);
    for (int i = 0; i < 3; ++i) vector<int>().swap(a[i]);

    cin >> s >> k;
    for (char &c : s) a[(c-'0')%3].emplace_back((c-'0'));
    for (int i = 0; i < 3; ++i) {
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());
    }
    if (k <= (int)a[0].size()) res.assign(a[0].begin(), a[0].begin()+k);
    if (a[1].size() >= 1 && a[2].size() >= 1) {
        h[0] = 0; h[1] = h[2] = 1;
        cur.clear();
        cur.emplace_back(a[1][0]);
        cur.emplace_back(a[2][0]);
        for (int t = 1, id; t*3 <= k-2; ++t) {
            id = 0;
            for (int i = 0; i < 3; ++i) {
                if (a[i].size()-h[i] < 3) continue;
                v[i].assign(a[i].begin()+h[i], a[i].begin()+h[i]+3);
                if (id == 0 || v[i] > v[id]) id = i;
            }
            if (!id) break;
            cur.emplace_back(v[id].begin(), v[id].end());
            h[id] += 3;
        }
        if (k-cur.size() <= a[0].size()-h[0]) {
            cur.emplace_back(a[0].begin()+h[0], a[0].begin()+h[0]+k-cur.size());
            sort(cur.begin(), cur.end());
            reverse(cur.begin(), cur.end());
            if (res < cur) res = cur;
        }
    }
    if ((int)res.size() == k) {
        for (const int &i : res) cout << i;
        cout << endl;
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