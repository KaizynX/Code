#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int q, c, m, x;
int a[N][N];

int main()
{
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> c >> m >> x;
        cout << min(min(c, m), (c+m+x)/3) << endl;
    }
    return 0;
}
