#include <bits/stdc++.h>

using namespace std;

int n;
string str;
map<string, int> mp;

int main()
{
    while (cin >> n) {
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> str;
            ++mp[str];
        }
        for (auto p : mp) {
            if (p.second == 1) {
                cout << p.first << endl;
                break;
            }
        }
    }
    return 0;
}
