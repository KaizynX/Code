/*
 * @Author: Kaizyn
 * @Date: 2020-05-17 13:56:56
 * @LastEditTime: 2020-05-17 15:36:21
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

string s;

signed main() {
  freopen("pi.txt", "r", stdin);
  freopen("L_data.txt", "w", stdout);
  cin >> s;
  for (int i = 0; i < 11000; i += 8) {
    char c = 0;
    for (int j = 0; j < 8; ++j) {
      c = c*2+(s[i+j]-'0');
    }
    putchar(c);
  }
  /*
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> s;
  int n = s.size();
  double base = 1, res = 3;
  for (int i = 0; i < n; ++i) {
    base /= 2;
    if (s[i] == '1') res += base;
  }
  cout << res << endl;
  cout << PI << endl;
  */
  return 0;
}