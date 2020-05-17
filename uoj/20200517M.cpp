/*
 * @Author: Kaizyn
 * @Date: 2020-05-17 13:44:26
 * @LastEditTime: 2020-05-17 13:47:11
 */ 
#include <bits/stdc++.h>
// #include "lcs.h"

// #define DEBUG

using namespace std;

const int N = 107;
int res[N], arr[N];

void find_permutation(int n, int res[])
{
    int A[3];
    for (int i = 0; i < 3; ++i) A[i] = 1;
    get_lcs(3, A); // 询问数组 [1, 1, 1] 与镁团手中排列的最长公共子序列。
    for (int i = 0; i < n; ++i) res[i] = i + 1; // 返回 1, 2, ..., n
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}