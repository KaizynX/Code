/*
 * @Author: Kaizyn
 * @Date: 2020-04-04 13:05:23
 * @LastEditTime: 2020-04-04 13:37:22
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
int res[N];

inline int query(const int &p)
{
    int v;
    cout << p << endl;
    cin >> v;
    return v;
}

inline bool answer()
{
    char ch;
    string str;
    for (int i = 1; i <= n; ++i) str += (char)(res[i]+'0');
    cout << str << endl;
    cin >> ch;
    return ch == 'Y';
}

bool solve()
{
    vector<int> same, diff;
    int l = 1, r = n;
    for (int i = 1; i <= 5 && l <= r; ++i) {
        res[l] = query(l);
        res[r] = query(r);
        if (res[l] == res[r]) same.emplace_back(l);
        else diff.emplace_back(l);
        ++l; --r;
    }
    while (l <= r) {
        if (same.size()) {
            int v = query(same[0]);
            if (v != res[same[0]]) {
                for (int i : same) {
                    res[i] ^= 1;
                    res[n-i+1] ^= 1;
                }
            }
        } else {
            query(1);
        }
        if (diff.size()) {
            int v = query(diff[0]);
            if (v != res[diff[0]]) {
                for (int i : diff) {
                    res[i] ^= 1;
                    res[n-i+1] ^= 1;
                }
            }
        } else {
            query(1);
        }
        for (int i = 1; i <= 4 && l <= r; ++i) {
            res[l] = query(l);
            res[r] = query(r);
            if (res[l] == res[r]) same.emplace_back(l);
            else diff.emplace_back(l);
            ++l; --r;
        }
    }
    return answer();
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T >> n;
    while (T--) {
        if (!solve()) break;
    }
    return 0;
}