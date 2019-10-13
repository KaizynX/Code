#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 20;

int m, k;

inline int count(int x)
{
    int res = 0;
    for (int i = 0; i < m; ++i)
        if (x&(1<<i)) ++res;
    return res;
}

int main()
{
    cin >> m >> k;
    if (k == 0) {
        for (int i = 0; i < (1<<m); ++i) {
            cout << i << " " << i << " ";
        }
        cout << endl;
        return 0;
    }
    if (k >= (1<<m)) {
        cout << -1 << endl;
        return 0;
    }
    int a, b, n = count(k);
#ifdef DEBUG
    cout << "n:" << n << endl;
#endif
    if (n == 1) {
        a = 0; b = k;
        for (int i = 0; i < m; ++i) {
            if (k&(1<<i)) continue;
            a += 1<<i;
            b += 1<<i;
            break;
        }
        if (!a) {
            cout << -1 << endl;
            return 0;
        }
    } else {
        for (int i = 0; i < 17; ++i) {
            if (k&(1<<i)) {
                b = 1<<i;
                a = k-b;
                break;
            }
        }
    }
    for (int i = 1; i < (1<<m); ++i) {
        if (i == a || i == b || i == k) continue;
        cout << i << " ";
    }
    cout << a << " " << b << " ";
    for (int i = (1<<m)-1; i; --i) {
        if (i == a || i == b || i == k) continue;
        cout << i << " ";
    }
    cout << 0 << " " << k << " " << b << " " << a << " " << k << " 0" << endl;
    return 0;
}
