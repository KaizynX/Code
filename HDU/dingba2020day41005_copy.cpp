#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n, m;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (m == 9) {
            ;
        }else if (m%3) {
            n -= n%9;
        } else {
            n -= n%3;
        }
        if (!n) cout << -1 << endl;
        else {
            for (int i = 1; i <= n; ++i) 
                cout << m;
            cout << endl;
        }
    }
    return 0;
}
