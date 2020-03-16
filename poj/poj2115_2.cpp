/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 21:13:01
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 21:21:38
 * @FilePath: \Code\poj\poj2115_2.cpp
 */
#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

template <typename T>
T exgcd(const T a, const T b, T &x, T &y)
{
    if (!b) { x = 1; y = 0; return a; }
    T d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

signed main()
{
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // a+t*c = b % 2^k
    // c*x-2^k*y = b-a
    long long a, b, c, k;
    while (scanf("%lld %lld %lld %lld", &a, &b, &c, &k) && a|b|c|k) {
        long long x, y, g, p;
        g = exgcd(c, 1ll<<k, x, y);
        p = (1ll<<k)/g;
        if ((b-a)%g) puts("FOREVER");
        else printf("%lld\n", ((b-a)/g*x%p+p)%p);
    }
    return 0;
}