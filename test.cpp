/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 16:51:41
 * @LastEditTime: 2020-08-03 22:59:46
 */
// MLE TEST

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 1e7 + 10;
const int K = 1e4;

int n, q;
int a[N];

typedef long long ll;

struct SegmentTree {
  std::bitset<K> a[N<<1];
} st;

int main() {
  // Sieve();
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]); // ft.Add(i, a[i]);
  while (q--) {}
}