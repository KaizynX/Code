/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 16:51:41
 * @LastEditTime: 2021-03-23 21:58:26
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e4+7;


struct Euler {
  vector<int> prime;
  vector<bool> check;
  bool operator [](const int &i) { return check[i]; }
  void init(int n) {
    prime.clear();
    check = vector<bool>(n+1, true);
    check[1] = false;
    for (int i = 2; i <= n; ++i) {
      if (check[i]) prime.emplace_back(i);
      for (const int &j : prime) {
        if (i*j > n) break;
        check[i*j] = false;
        if (i%j == 0) break;
      }
    }
  }
} E;

struct Node {
  int mul, pi, pj, pk;
};

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  E.init(1e4);
  int s = 0, t = 0;
  auto &p = E.prime;
  Node r1, r2;
  /*
  int p1 = 998244353, p2 = 1e9+7;
  while (p[s] <= 666) ++s;
  while (p[t] < 2255) ++t;
  for (int i = s; i <= t; ++i)
  for (int j = i; j <= t; ++j)
  for (int k = j; k <= t; ++k) {
    ll mul = 1ll*p[i]*p[j]*p[k];
    if (abs(mul-p1) < abs(p1-r1.mul)) r1 = Node{mul, p[i], p[j], p[k]};
    if (abs(mul-p2) < abs(p2-r2.mul)) r2 = Node{mul, p[i], p[j], p[k]};
  }
  */
  int p1 = 998244353, p2 = 1e9+7;
  while (p[s] <= 1000) ++s;
  while (p[t] <= 2000) ++t;
  for (int i = s; i <= t; ++i)
  for (int j = i; j <= t; ++j)
  for (int k = j; k <= t; ++k) {
    ll mul = 1ll*p[i]*p[j]*p[k];
    if (abs(mul-p1) < abs(p1-r1.mul)) r1 = Node{mul, p[i], p[j], p[k]};
    if (abs(mul-p2) < abs(p2-r2.mul)) r2 = Node{mul, p[i], p[j], p[k]};
  }
  cout << r1.mul << " " << r1.pi << " " << r1.pj << " " << r1.pk << '\n';
  cout << r2.mul << " " << r2.pi << " " << r2.pj << " " << r2.pk << '\n';
  return 0;
}