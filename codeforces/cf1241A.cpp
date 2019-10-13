#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int q, n;

int main()
{
    cin >> q;
    while (q--) {
        cin >> n;
        if (n <= 4) {
            cout << 4-n << endl;
        } else {
            cout << (n%2) << endl;
        }
    }
    return 0;
}
