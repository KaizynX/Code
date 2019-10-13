#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, res;
int h[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        if (h[i] < h[i-1]) res += h[i-1]-h[i];
    }
    res += h[n];
    cout << res << endl;
    return 0;
}
