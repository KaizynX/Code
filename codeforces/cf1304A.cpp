#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const double err = 1e-9;
typedef pair<int, int> pii;

int testcase = 1;
long long n, x, y, a, b;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> x >> y >> a >> b;
        long long d = y-x, v = a+b;
        if (d%v) cout << -1 << endl;
        else cout << d/v << endl;
    }
    return 0;
}
