#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main()
{
    cin >> n >> s;
    if (n%2 == 0 && s.substr(0, n/2) == s.substr(n/2)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

