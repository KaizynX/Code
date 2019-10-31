#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int t, a, b, c;

int main()
{
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int res = 0, tmp;
        tmp = min(b, c/2);
        res += tmp*3;
        b -= tmp;
        tmp = min(a, b/2);
        res += tmp*3;
        cout << res << endl;
    }
    return 0;
}
