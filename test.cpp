/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 16:51:41
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-17 13:45:12
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

template <class T>
void add(T a) {
    ++a;
    cout << typeid(a).name() << endl;
}

signed main()
{
    const int a = 10;
    long long b = 1;
    string c = "233";
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    add(a);
    return 0;
}