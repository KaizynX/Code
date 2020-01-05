#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T;
long long x;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> x;
        if (x < 15) {
            cout << "NO" << endl;
            continue;
        }
        x %= 14;
        cout << (x <= 6 && x ? "YES" : "NO") << endl;
    }
    return 0;
}

