#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int a, b, c, d, e, f;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c >> d >> e >> f;
    int n1 = min(a, d), n2 = min(b, min(c, d));
    cout << max(e*n1+f*min(n2, d-n1), e*min(n1, d-n2)+f*n2) << endl;
    return 0;
}
