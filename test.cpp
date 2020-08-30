/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 16:51:41
 * @LastEditTime: 2020-08-29 21:55:56
 */
#include <bits/stdc++.h>

using namespace std;

struct Node {
  static int n;
  int f(int l = 1, int r = n) {
    return r-l;
  }
};

int n;
int f(int l = 1, int r = n) {
  return r-l;
}
int main() {
  f();
  return 0;
}