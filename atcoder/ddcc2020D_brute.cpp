#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
long long res;
int d[N];
long long c[N];

int main()
{
    cin >> n;
    for (int i = 1, cur = 0; i <= n; ++i) {
        cin >> d[i] >> c[i];
        for (long long j = 1; j <= c[i]; ++j) {
            cur += d[i];
            ++res;
            if (cur >= 10) {
                cur = cur%10+1;
                ++res;
            }
        }
    }
    cout << res-1 << endl;
    return 0;
}

