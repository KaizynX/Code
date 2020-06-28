/*
 * @Author: Kaizyn
 * @Date: 2020-06-24 18:27:25
 * @LastEditTime: 2020-06-24 18:35:20
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const int N = ;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n;
  while (cin >> n && n) {
    cout << (n&-n) << endl;
  }
  return 0;
}