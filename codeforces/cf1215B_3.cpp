#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int MAXN = 2e5+7;

int n;
long long nn, np;
int a[MAXN], cnt[MAXN][3];
// cnt[][0] < 0
// cnt[][1] == 0
// cnt[][2] > 0

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 3; ++j) cnt[i][j] = cnt[i-1][j];
        if (a[i] < 0) ++cnt[i][0];
        if (a[i] == 0) ++cnt[i][1];
        if (a[i] > 0) ++cnt[i][2];
    }
    // c0 +, c1 -, flag if it is the first
    for (int i = 1, c0 = 0, c1 = 0; i <= n; ++i) {
        if (a[i] < 0) {
            nn += c0+1;
            np += c1;
            swap(c0, c1);
            ++c1;
        } else if (a[i] == 0) {
            c0 = c1 = 0;
        } else {
            nn += c1;
            np += c0+1;
            ++c0;
        }
#ifdef DEBUG
        cout << c0 << " " << c1 << " " << nn << " " << np << endl;
#endif
    }
    cout << nn << " " << np << endl;
    return 0;
}
