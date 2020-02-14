#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int l, n;
int a[10];

inline void pre()
{
    for (int i = l; i; --i) {
        --a[i];
        if (a[i] < 0) a[i] = 25;
        else break;
    }
}

int main()
{
    cin >> l >> n;
    for (int i = 1; i <= l; ++i) a[i] = 25;
    for (int i = 1; i < n; ++i) pre();
    for (int i = 1; i <= l; ++i) cout << (char)('a'+a[i]);
    cout << endl;
    return 0;
}
