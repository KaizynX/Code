#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

long long n;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    if (n&1) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    long long cnt2 = -1, cnt5 = 0;
    for (long long i = 2; i <= n; i *= 2) cnt2 += n/i;
    n /= 2;
    for (long long i = 5; i <= n; i *= 5) cnt5 += n/i;
    cout << min(cnt2, cnt5) << endl;
    return 0;
}
