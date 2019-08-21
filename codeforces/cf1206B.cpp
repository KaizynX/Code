#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;

int n;
long long res;
int a[kN], cnt[3];
// 0 -1
// 1 0
// 2 1

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) ++cnt[1], ++res;
        else if (a[i] < 0) {
            res += -1-a[i];
            ++cnt[0];
        } else if (a[i] > 0) {
            res += a[i]-1;
            ++cnt[2];
        }
    }
    if (cnt[0]&1 && !cnt[1]) res += 2;
    cout << res << endl;
    return 0;
}
