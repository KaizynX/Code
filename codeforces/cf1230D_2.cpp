#include <bits/stdc++.h>

using namespace std;

const int N = 7e3+7;

int n;
int b[N];
long long res;
long long a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        long long now = 0;
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (a[i] == a[j]) ++cnt;
            if ((a[i]|a[j]) == a[i]) {
                now += b[j];
            }
        }
        if (cnt >=2) res = max(res, now);
    }
    cout << res << endl;
    return 0;
}
