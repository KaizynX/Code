/*
 * @Author: Kaizyn
 * @Date: 2020-04-18 13:03:44
 * @LastEditTime: 2020-04-18 13:36:00
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1000;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

// 2000 01 01 6
const int md[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int run(const int &y) {
    return y%400 == 0 || (y%4 == 0 && y%100);
}

struct Node {
    int y, m, d;
    Node(){}
    Node(const int &_y, const int &_m, const int &_d) : y(_y), m(_m), d(_d) {}
    friend bool operator < (const Node &lhs, const Node &rhs) {
        if (lhs.y != rhs.y) return lhs.y < rhs.y;
        if (lhs.m != rhs.m) return lhs.m < rhs.m;
        return lhs.d < rhs.d;
    }
    int day() const {
        int res = 5;
        for (int i = 2000; i < y; ++i) res += 365+run(i);
        for (int i = 1; i < m; ++i) res += md[i];
        if (2 < m && run(y)) ++res;
        res = (res+d-1)%7+1;
        return res;
    }
};

inline void solve()
{
    int y, m, d, flag;
    cin >> y >> m >> d;
    Node now(y, m, d), res, tmp;
    flag = 1;
    m = 5;
    for (y = now.y ; y <= 2101 && flag; ++y) {
        for (d = 8; d <= 14 && flag; ++d) {
            tmp = Node (y, m, d);
            if (now < tmp && tmp.day() == 7) {
                res = tmp;
                flag = 0;
            }
        }
    }
    flag = 1;
    m = 6;
    for (y = now.y ; y <= 2101 && flag; ++y) {
        for (d = 15; d <= 21 && flag; ++d) {
            tmp = Node (y, m, d);
            if (now < tmp && tmp.day() == 7 && tmp < res) {
                res = tmp;
                if (res.d == 21 || res.d == 31) printf("Father's Day: June %dst, %d\n", res.d, res.y);
                else if (res.d == 22) printf("Father's Day: June %dnd, %d\n", res.d, res.y);
                else printf("Father's Day: June %dth, %d\n", res.d, res.y);
                return;
            }
        }
    }
    if (res.d == 21 || res.d == 31) printf("Mother's Day: May %dst, %d\n", res.d, res.y);
    else if (res.d == 22) printf("Mother's Day: May %dnd, %d\n", res.d, res.y);
    else printf("Mother's Day: May %dth, %d\n", res.d, res.y);
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