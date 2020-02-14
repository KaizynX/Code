#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

string a, b;
int mp[256];

int main()
{
    getline(cin, a);
    getline(cin, b);
    for (char c : b) mp[c] = 1;
    for (char c : a) if (!mp[c]) cout << c;
    cout << endl;
    return 0;
}
