#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int T, n;
int f[N];

inline bool check(int x)
{
    int f3 = 0, f5 = 0;
    while (x) {
        if (x%10 == 3) f3 = 1;
        if (x%10 == 5) f5 = 1;
        x /= 10;
    }
    return f3 && f5;
}

inline void init()
{
    static const int sz = 1e5;
    for (int i = 1; i <= sz; ++i)
        f[i] = f[i-1]+check(i);
}

int main()
{
    init();
    cin >> T;
    while (T--) {
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}
