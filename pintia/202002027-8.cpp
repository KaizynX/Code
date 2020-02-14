#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;
char c;
string s;

int main()
{
    cin >> n >> c;
    cin.get();
    getline(cin, s);
    for (int i = 0; i < n-(int)s.length(); ++i)
        cout << c;
    for (int i = max(0, (int)s.length()-n); i < (int)s.length(); ++i)
        cout << s[i];
    cout << endl;
    return 0;
}
