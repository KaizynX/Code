#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
long long res;
int d[N];
long long c[N];

int f(int a, long long t) {
    if (t == 0) return 0;
    if (t == 1) return a;

    res += t/2+2*a/10*t/2;
    int tmp = f(2*a%10+2*a/10, t/2);
    if (t&1) {
        tmp += a;
        ++res;
    }
    if (tmp >= 10) {
        tmp = tmp%10+tmp/10;
        ++res;
    }
    return tmp;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i] >> c[i];
        d[i] = f(d[i], c[i]);
    }
    for (int i = 2, cur = d[1]; i <= n; ++i) {
        cur += d[i];
        ++res;
        if (cur >= 10) {
            ++res;
            cur = cur%10+cur/10;
        }
    }
    cout << res << endl;
    return 0;
}

