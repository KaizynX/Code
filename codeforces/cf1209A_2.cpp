#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2+7;
const int INF = 1e9;

int n, res, choose;
int a[MAXN], b[MAXN];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        if (!a[i]) continue;
        ++res;
        for (int j = i+1; j <= n; ++j) {
            if (!a[j]) continue;
            if (a[j]%a[i] == 0) {
                a[j] = 0;
            }
        }
    }
    cout << res << endl;
    return 0;
}
