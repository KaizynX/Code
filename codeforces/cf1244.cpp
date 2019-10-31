#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int a, b, c, d, k, t;

int main()
{
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> k;
        int x = a/c+(a%c != 0), y = b/d+(b%d != 0);
        if (x+y > k) {
            cout << -1 << endl;
        } else {
            cout << x << " " << y << endl;
        }
    }
    return 0;
}
