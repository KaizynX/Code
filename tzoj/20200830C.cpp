/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 13:00:23
 * @LastEditTime: 2020-08-30 16:45:58
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int n;
string s;

inline void solve() {
  if (n) {
    getline(cin, s);
    cout << s.size()-1 << endl;
    // int res = 0;
    // for (char ch : s) if (isalpha(ch))++res;
    // printf("%d\n", res);
  } else {
    int a, b;
    cin >> a >> b;
    printf("%.2f\n", 1.0*a/b);
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n) solve();
  return 0;
}