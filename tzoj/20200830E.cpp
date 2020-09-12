/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 13:13:51
 * @LastEditTime: 2020-08-30 13:20:52
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 10;

struct Node {
  string name;
  int m1, m2, g, id;
  friend istream& operator >>(istream &is, Node &nd) {
    return is >> nd.name >> nd.m1 >> nd.m2 >> nd.g;
  }
  friend bool operator <(const Node &lhs, const Node &rhs) {
    if (lhs.m1 != rhs.m1) return lhs.m1 > rhs.m1;
    if (lhs.m2 != rhs.m2) return lhs.m2 > rhs.m2;
    return lhs.g < rhs.g;
  }
};

Node a[N];
vector<pair<int, string>> res;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n = 7;
  for (int i = 1; i <= n; ++i) cin >> a[i], a[i].id = i;
  sort(a+1, a+n+1);

  res.clear();
  int m = a[2].m1;
  for (int i = 1; i <= n; ++i) {
    if (a[i].m1 >= m) res.emplace_back(a[i].id, a[i].name);
  }
  sort(res.begin(), res.end());
  cout << "Gold:\n";
  for (auto &p : res) cout << p.second << endl;
  res.clear();
  for (int i = 1; i <= 5; ++i) {
    res.emplace_back(a[i].id, a[i].name);
  }
  sort(res.begin(), res.end());
  cout << "\nTeam:\n";
  for (auto &p : res) cout << p.second << endl;
  return 0;
}