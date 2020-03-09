/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 13:46:03
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 14:06:22
 * @FilePath: \Code\uva\uva12230.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

/*
struct Node
{
    int p, l, v;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.p < n2.p;
    }
    friend istream& operaotr >> (istream &is, Node &nd) {
        return is >> nd.p >> nd.l >> nd.v;
    }
} a[15];
*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0, n, d;
    while (cin >> n >> d && n | d) {
        double t = d;
        for (int i = 1, p, l, v; i <= n; ++i) {
            cin >> p >> l >> v;
            t += 2.0*l/v-l;
        }
        printf("Case %d: %.3f\n", ++T, t);
    }
    return 0;
}