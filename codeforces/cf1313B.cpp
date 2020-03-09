#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T;
int n, x, y;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> x >> y;
        if (n == 1) { cout << "1 1" << endl; continue; }
        cout << max(1, min(n, x+y-n+1)) << " ";
        cout << min(x+y-1, n) << endl;
    }
    return 0;
}