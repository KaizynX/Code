#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, st, in, ex;

int main()
{
    cin >> T;
    while (T--) {
        cin >> st >> in >> ex;
        int res = st-in+ex;
        if (res <= 0) {
            cout << 0 << endl;
            continue;
        }
        res = res/2+res%2;
        cout << min(ex+1, res) << endl;
    }
    return 0;
}
