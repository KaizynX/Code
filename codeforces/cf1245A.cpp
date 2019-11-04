#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int t, a, b;

int main()
{
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << (__gcd(a, b) == 1 ? "Finite" : "Infinite") << endl;
    }
    return 0;
}
