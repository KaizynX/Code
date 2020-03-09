#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

inline int f(const long long &a)
{
    long long l = 0, r = 1e9;
    while (l < r) {
        long long mid = (l+r+1)>>1;
        if (mid*mid <= a) l = mid;
        else r = mid-1;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long x;
    while (cin >> x) {
        cout << f(x) << endl;
    }
    return 0;
}