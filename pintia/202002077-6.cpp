#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, cnt;

int main()
{
    cin >> n;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        cnt += a&1;
    }
    cout << cnt << " " << n-cnt << endl;
    return 0;
}
