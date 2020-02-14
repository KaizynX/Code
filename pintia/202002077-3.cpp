#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int a, b, n, aa, bb;

int main()
{
    cin >> a >> b >> n;
    int flag = 0;
    for (int i = 1, a1, a2, b1, b2, sum; i <= n; ++i) {
        cin >> a1 >> a2 >> b1 >> b2;
        sum = a1+b1;
        if (flag) continue;
        if ((a2 == sum && b2 == sum) || (a2 != sum && b2 != sum)) continue;
        if (a2 == sum) ++aa;
        if (b2 == sum) ++bb;
        if (aa > a) flag = 1;
        if (bb > b) flag = 2;
    }
    if (flag == 1) cout << "A\n" << bb << endl;
    else if (flag == 2) cout << "B\n" << aa << endl;
    return 0;
}
