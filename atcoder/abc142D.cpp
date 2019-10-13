#include <bits/stdc++.h>

using namespace std;

int res;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a%b) : a;
}

int main()
{
    long long a, b, c;
    cin >> a >> b;
    c = gcd(a, b);
    for (long long i = 2; i*i <= c; ++i) {
        if (c%i == 0) {
            ++res;
            while (c%i == 0)
                c /= i;
        }
    }
    if (c != 1) ++res;
    cout << res+1 << endl;
    return 0;
}
