#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int l, r;
int cnt[10];

inline bool check(int x)
{
    for (int i = 0; i <= 9; ++i) cnt[i] = 0;
    while (x) {
        if (cnt[x%10]) return false;
        cnt[x%10] = 1;
        x /= 10;
    }
    return true;
}

int main()
{
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        if (check(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
