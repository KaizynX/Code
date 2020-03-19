/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 16:51:41
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-18 13:14:52
 * @FilePath: \Code\test.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

signed main()
{
    int n = 0;
    char s;
    while ((s = getchar()) && s != '.') {
        putchar(s);
        if (s == ' ') {
            cout << n << " ";
            n = 0;
        } else {
            ++n;
        }
    }
    if (n) cout << n << endl;
    return 0;
}