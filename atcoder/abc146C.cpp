#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

long long a, b, x, n;

inline int d(long long x)
{
    int res = 0;
    while (x) {
        ++res;
        x /= 10;
    }
    return res;
}

int main()
{
    cin >> a >> b >> x;
    long long l = 0, r = 1e9;
    while (l < r) {
        long long mid = (l+r+1)/2;
        if (a*mid+b*d(mid) > x) r = mid-1;
        else l = mid;
    }
    cout << l << endl;
    return 0;
}
