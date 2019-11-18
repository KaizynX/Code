#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, x, a, b, t;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> x >> a >> b;
        if (a > b) swap(a, b);
        int tmp = min(a-1, x);
        a -= tmp;
        x -= tmp;
        tmp = min(n-b, x);
        b += tmp;
        x -= tmp;
        cout << b-a << endl;
    }
    return 0;
}
