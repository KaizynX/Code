/*
 * @Author: Kaizyn
 * @Date: 2020-03-14 20:06:46
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 21:12:22
 * @FilePath: \Code\poj\poj2115.cpp
 */
#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
// #include <unordered_map>

// #define DEBUG

using namespace std;

map<long long, long long> mp;
// unordered_map<long long, long long> mp;

signed main()
{
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // a+t*c = b % 2^k
    // t*c = b-a % 2^k
    // x*(sqrt(2^k))*c + y*c = b-a % 2^k
    long long a, b, c, k;
    while (scanf("%lld %lld %lld %lld", &a, &b, &c, &k) && a|b|c|k) {
        mp.clear();
        long long sqr = 1ll<<(k/2),
                  p = 1ll<<k,
                  h = ((b-a)%p+p)%p,
                  res = p,
                  cur = 0;
        // sqr*i < 2^k
        for (int i = 0; i < 1ll<<(k-k/2); ++i) {
            if (!mp.count(cur)) mp[cur] = i*sqr;
            cur = (cur+sqr*c%p)%p;
        }
        for (int i = 0; i < sqr; ++i) {
            cur = (h-(c*i)%p+p)%p;
            if (mp.count(cur)) res = min(res, mp[cur]+i);
        }
        if (res >= p) puts("FOREVER");
        else printf("%lld\n", res);
    }
    return 0;
}