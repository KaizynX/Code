#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1, a, b, x, y; i <= n; ++i) {
        cin >> a >> b;
        x = 2*a-b; y = 2*b-a;
        if (x%3 || y%3 || x < 0 || y < 0 || (!a && b) || (!b && a)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
