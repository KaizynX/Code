#include <bits/stdc++.h>

using namespace std;

int T, n;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        int t = 0, tortoise = 0, rabbit = 0, rest = 0;
        while (t+10 <= n) {
            t += 10;
            tortoise += 30;
            --rest;
            if (rest <= 0) {
                rabbit += 90;
                if (rabbit > tortoise)
                    rest = 4;
            }
        }
        n -= t;
        tortoise += 3*n;
        if (rest <= 0) rabbit += 9*n;
        if (rabbit == tortoise) cout << "-_- ";
        if (rabbit > tortoise) cout << "^_^ ";
        else cout << "@_@ ";
        cout << max(rabbit, tortoise) << endl;
    }
    return 0;
}
