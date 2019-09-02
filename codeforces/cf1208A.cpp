#include <bits/stdc++.h>

using namespace std;

int T, n, a, b;

int main()
{
    cin >> T;
    while (T--) {
        int res = 0;
        cin >> a >> b >> n;
        if (n == 0) {
            cout << a << endl; 
            continue;
        } else if (n == 1) {
            cout << b << endl;
            continue;
        } 

        for (int i = 0; i < 31; ++i) {
            int bit = 1<<i;
            int ai = a&bit, bi = b&bit;
            if (!ai && !bi) continue;
            else if (ai && bi) {
                if (n%3 != 2) res += bit;
            } else if (ai) {
                if (n%3 != 1) res += bit;
            } else if (bi) {
                if (n%3 != 0) res += bit;
            }
        }
        cout << res << endl;
    }
    return 0;
}
