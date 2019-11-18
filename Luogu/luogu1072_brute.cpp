#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a/gcd(a, b)*b; }

int main()
{
    int n, a, b, c, d;
    cin >> n;
    while (n--) {
        // gcd(x, a) = c
        // lcm(x, b) = d
        int res = 0;
        cin >> a >> c >> b >> d;
        for (int x = 1; x <= d; ++x) {
            if (gcd(x, a) == c && lcm(x, b) == d)
                ++res;
        }
        cout << res << endl;
    }
    return 0;
}
