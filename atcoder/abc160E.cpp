/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 19:57:58
 * @LastEditTime: 2020-03-28 21:03:32
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int X, Y, A, B, C;
vector<int> a, b, c;
priority_queue<int, vector<int>, greater<int>> q;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> X >> Y >> A >> B >> C;
    a.resize(A);
    b.resize(B);
    c.resize(C);
    for (int i = 0; i < A; ++i) cin >> a[i];
    for (int i = 0; i < B; ++i) cin >> b[i];
    for (int i = 0; i < C; ++i) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    long long sum = 0;
    for (int i = 0; i < X && i < A; ++i) q.push(a[i]), sum += a[i];
    for (int i = 0; i < Y && i < B; ++i) q.push(b[i]), sum += b[i];
    int t = 0;
    for (int i = A; i < X; ++i) q.push(c[t++]), sum += c[i];
    for (int i = B; i < Y; ++i) q.push(c[t++]), sum += c[i];
    while (t < C && c[t] > q.top()) {
        sum += c[t++]-q.top();
        q.pop();
    }
    cout << sum << endl;
    return 0;
}