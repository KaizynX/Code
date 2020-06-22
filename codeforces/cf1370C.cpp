/*
 * @Author: Kaizyn
 * @Date: 2020-06-20 22:23:57
 * @LastEditTime: 2020-06-20 22:48:10
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n;

inline bool is_prime(long long x) {
  if(x == 1) return false;
  if(x == 2 || x == 3) return true;
  if(x%6 != 1 && x%6 != 5) return false;
  for(long long i = 5; i*i <= x; i += 6)
    if(x%i == 0 || x%(i+2) == 0) return false;
  return true;
}

inline bool solve() {
  cin >> n;
  if (n == 1) return false;
  if (n == 2) return true;
  if (n&1) return true;
  int k = 0;
  while (n%2 == 0) n /= 2, ++k;
  if (n == 1) return false;
  if (k == 1 && is_prime(n)) return false;
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Ashishgup" : "FastestFinger") << endl;
  }
  return 0;
}