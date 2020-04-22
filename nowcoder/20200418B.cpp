/*
 * @Author: Kaizyn
 * @Date: 2020-04-18 12:15:57
 * @LastEditTime: 2020-04-18 12:23:18
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

struct Node {
    int date, id;
    double temp;
    friend bool operator < (const Node &lhs, const Node &rhs) {
        if (lhs.date != rhs.date) return lhs.date > rhs.date;
        if (lhs.temp != rhs.temp) return lhs.temp > rhs.temp;
        return lhs.id < rhs.id;
    }
    /*
    friend istream operator >> (istream &is, Node &nd) {
        return is >> nd.date >> nd.id >> nd.temp;
    }
    */
};

int n, m;
Node a[N];
vector<Node> v;

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].date >> a[i].id >> a[i].temp;
        if (a[i].temp >= 38) v.emplace_back(a[i]);
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (Node &i : v) {
        printf("%d %d %.1f\n", i.date, i.id, i.temp);
    }
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