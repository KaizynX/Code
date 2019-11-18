#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int K = 15;

int n;
int a[N], b[N];

inline int count(int x) {
    int res = 0;
    for ( ; x; x >>= 1) res += x&1;
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int x = 0; x < (1<<K); ++x) {
        for (int i = 0; i < n; ++i) {
            b[i] = a[i]^x;
        }
        int flag = 1;
        for (int i = 0; i < n; ++i) {
            if (count(b[i]) != count(b[0])) {
                flag = 0;
                break;
            }
        }
        if (flag) cout << x << endl;
    }
    return 0;   
}
