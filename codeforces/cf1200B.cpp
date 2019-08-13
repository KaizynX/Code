#include <bits/stdc++.h>

using namespace std;

const int kN = 1e2+7;

int T, n, m, k;
int h[kN];

int main()
{
    cin >> T;
    while(T--) {
        int flag = 1;
        cin >> n >> m >> k;
        for(int i = 1; i <= n; ++i)
            cin >> h[i];
        for(int i = 1; i < n; ++i) {
            m += h[i]-max(0, h[i+1]-k);
            if (m < 0) {
                flag = 0;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
