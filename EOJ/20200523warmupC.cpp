/*
 * @Author: Kaizyn
 * @Date: 2020-05-23 12:28:07
 * @LastEditTime: 2020-05-23 12:31:50
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

inline int check(const int &x) {
  static string s;
  cout << x << endl;
  cin >> s;
  if (s == "small") return -1;
  else if (s == "big") return 1;
  else return 0;
}

signed main() {
  int l = -1e9, r = 1e9;
  while (l < r) {
    int mid = (l+r)>>1;
    int flag = check(mid);
    if (flag == -1) {
      l = mid+1;
    } else if (flag == 0) {
      return 0;
    } else if (flag == 1) {
      r = mid-1;
    }
  }
  check(l);
  return 0;
}