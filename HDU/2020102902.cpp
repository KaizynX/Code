/*
 * @Author: Kaizyn
 * @Date: 2020-06-17 18:33:22
 * @LastEditTime: 2020-10-29 10:20:58
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

struct Node {
  string name;
  double score;
  int age;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    if (lhs.score != rhs.score) return lhs.score > rhs.score;
    if (lhs.age != rhs.age) return lhs.age < rhs.age;
    return lhs.name < rhs.name;
  }
};

int n;
Node a[N];

inline void solve() {
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].name >> a[i].age >> a[i].score;
  }
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; ++i) {
    cout << a[i].name << " " << a[i].age << " "
        << setiosflags(ios::fixed) << setprecision(2) << a[i].score << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n) {
    solve();
  }
  return 0;
}