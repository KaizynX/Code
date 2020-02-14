#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n;
string s, a, b;

int main()
{
    while (cin >> s && s != ".") {
        ++n;
        if (n == 2) a = s;
        if (n == 14) b = s;
    }
    if (n < 2) cout << "Momo... No one is for you ...\n";
    else if (n < 14) cout << a << " is the only one for you...\n";
    else cout << a << " and " << b << " are inviting you to dinner...\n";
    return 0;
}
