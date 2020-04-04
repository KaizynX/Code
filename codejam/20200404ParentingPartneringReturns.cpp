/*
 * @Author: Kaizyn
 * @Date: 2020-04-04 09:49:46
 * @LastEditTime: 2020-04-04 13:01:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

struct Node 
{
    int s, e, id;
    friend bool operator < (const Node &lhs, const Node &rhs) {
        return lhs.s < rhs.s;
    }
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.s >> nd.e;
    }
};

int n;
int res[N];
Node a[N];

string solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i].id = i;
    }
    sort(a+1, a+n+1);
    int j = 0, c = 0;
    for (int i = 1; i <= n; ++i) {
        if (j <= a[i].s) {
            j = a[i].e;
            res[a[i].id] = 'J';
        } else if (c <= a[i].s) {
            c = a[i].e;
            res[a[i].id] = 'C';
        } else {
            return "IMPOSSIBLE";
        }
    }
    string str;
    for (int i = 1; i <= n; ++i) str += (char)res[i];
    return str;
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