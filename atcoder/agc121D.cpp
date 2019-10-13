#include <bits/stdc++.h>
#define DEBUG

using namespace std;

long long a, b;

inline long long calc(long long x)
{
    ++x;
    long long bit = 2, res = (x%4 < 2 ? 0 : 1);
    while (bit <= x) {
        if (((x/bit)&1) && ((x-x/bit*bit)&1))
            res += bit;
        bit <<= 1;
    }
    return res;
}

#ifdef DEBUG
inline long long brute(long long x)
{
    long long res = 0;
    for (long long i = 1; i <= x; ++i)
        res ^= i;
    return res;
}
#endif

int main()
{
    cin >> a >> b;
#ifdef DEBUG
    cout << calc(b) << " " << brute(b) << endl;
    cout << calc(a-1) << " " << brute(a-1) << endl;
    cout << (a ? brute(b)^brute(a-1) : brute(a)) << endl;
#endif
    cout << (a ? calc(b)^calc(a-1) : calc(b)) << endl;
    return 0;
}
