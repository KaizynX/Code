#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int x;

inline bool check(int n)
{
    int d = 0;
    for (int i = 1; i <= n; ++i) {
        d = d*10+1;
        d %= x;
    }
    return d == 0;
}

inline void print(int n)
{
    for (int i = 1, flag = 0, d = 0, p; i <= n; ++i) {
        d = d*10+1;
        p = d/x;
        d %= x;
        if (p) {
            printf("%d", p);
            flag = 1;
        }
        else {
            if (flag) putchar('0');
        }
    }
}

int main()
{
    cin >> x;
    for (int i = 1; ; ++i) {
        if (check(i)) {
            print(i);
            printf(" %d\n", i);
            break;
        }
    }
    return 0;
}
