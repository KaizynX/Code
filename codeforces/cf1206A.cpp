#include <bits/stdc++.h>

using namespace std;

const int kN = 1e2+7;

int n, m;
int a[kN], b[kN], t[kN*4];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        t[a[i]]++;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
        t[b[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!t[a[i]+b[j]]) {
                cout << a[i] << " " << b[j] << endl;
                return 0;
            }
        }
    }
    return 0;
}
