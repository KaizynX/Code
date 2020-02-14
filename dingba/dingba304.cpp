#include <bits/stdc++.h>

using namespace std;

long long n, x, res;

int main()
{
    cin >> n >> x;
    for (int i = 62; i >= 0; --i) {
        if ((x>>i)&1) {
            if (n >= (1ll<<i)) {
                n -= 1ll<<i;
            } else {
                res += 1ll<<i;
            }
        }
    }
    cout << (res == x ? x^1 : res) << endl;
    return 0;
}
