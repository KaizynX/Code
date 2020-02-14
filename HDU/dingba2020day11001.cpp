#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n;
string a, b;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 'O') a[i] = '0';
            if (b[i] == 'O') b[i] = '0';
            if (a[i] == 'l') a[i] = 'I';
            if (b[i] == 'l') b[i] = 'I';
        }
        cout << (a == b ? "OK" : "NO") << endl;
    }
    return 0;
}
