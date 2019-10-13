#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, cnt;
long long b[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        cnt += static_cast<int>(b[i]&1);
    }
    cout << min(cnt, n-cnt) << endl;
    int choose = (cnt <= n-cnt ? 1 : 0);
    for (int i = 0; i < n; ++i) {
        if ((b[i]&1) == choose) {
            cout << b[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
