#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

long long n, a, b;

int main()
{
    cin >> n >> a >> b;
    if ((b-a)%2 == 0) {
        cout << (b-a)/2 << endl;
    } else {
        long long res = 0;
        if (a-1 <= n-b) {
            b -= a-1;
            res += a-1;
            a = 1;
            --b;
            ++res;
            res += (b-a)/2;
        } else {
            a += n-b;
            res += n-b;
            b = n;
            ++a;
            ++res;
            res += (b-a)/2;
        }
        cout << res << endl;
    }
    return 0;
}
