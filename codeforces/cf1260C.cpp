#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, r, b, k;
int a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> r >> b >> k;
        if (r > b) swap(r, b);
        /*
        int n = b/r+(b%r != 0);
        if (n >= k) {
            cout << "REBEL" << endl;
            continue;
        }
        */
        int g = __gcd(r, b);
        long long lcm = 1ll*r*b/g;
        int tr = b/g, tb = r/g;
        --tr;
        if (tr/tb+(tr%tb != 0) >= k) {
            cout << "REBEL" << endl;
        } else {
            cout << "OBEY" << endl;
        }
    }
    return 0;
}

