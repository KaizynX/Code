/*
 * @Author: Kaizyn
 * @Date: 2021-03-10 12:16:29
 * @LastEditTime: 2021-03-10 12:19:26
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 250000+7;

int n, m;
int dif[N];
vector<int> a[N];

inline void print(vector<int> &arr) {
  cout << "Yes\n";
  for (int &i : arr) cout << i << ' ';
  cout << '\n';
}

inline bool check(vector<int> &arr) {
  for (int i = 0, t; i < n; ++i) {
    t = 0;
    for (int j = 0; j < m; ++j) {
      t += a[i][j] != arr[j];
    }
    if (t > 2) return false;
  }
  return true;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  int mxi = 0;
  for (int i = 0; i < n; ++i) {
    a[i].resize(m);
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      dif[i] += a[i][j] != a[0][j];
    }
    if (dif[i] > dif[mxi]) mxi = i;
  }
  if (dif[mxi] > 4) return cout << "No\n", 0;
  if (dif[mxi] <= 2) return print(a[0]), 0;
  for (mxi = 1; mxi < n; ++mxi) if (dif[mxi] > 2) {
    vector<int> difp, res;
    for (int i = 0; i < m; ++i) {
      if (a[mxi][i] != a[0][i]) {
        difp.emplace_back(i);
      }
    }
    // 4(2), 3(1, 2)
    for (int i = 0; i < 1<<dif[mxi]; ++i) {
      int bt = __builtin_popcount(i);
      if (bt <= 2 && bt >= dif[mxi]-2) {
        res = a[0];
        for (int j = 0; j < dif[mxi]; ++j) if ((i>>j)&1) {
          res[difp[j]] = a[mxi][difp[j]];
        }
        if (check(res)) return print(res), 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}
/*
5 5
185202051 546644673 256604854 809788696 204113467
757748286 49086372 256604854 809788696 666765043
185202051 361984662 256604854 909233087 841008011
185202051 372891934 256604854 809788696 928119866
185202051 361984662 290067511 809788696 581607532

Yes
185202051 361984662 256604854 809788696 666765043
*/