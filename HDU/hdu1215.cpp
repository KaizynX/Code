#include <bits/stdc++.h>

using namespace std;

const int N = 5e5;

int T, n;

inline int f(int x)
{
    if (x <= 1) return 0;
    int res = 1;
    for (int i = 2; i*i <= x; ++i) {
        if (x%i) continue;
        res += x/i;
        if (x/i != i) res += i;
    }
    return res;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}

