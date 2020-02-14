#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int mp[10];
string s;

int main()
{
    cin >> s;
    for (char c : s) mp[c-'0'] = 1;
    cout << "int[] arr = new int[]{";
    for (int i = 9, tot = 0; i >= 0; --i) {
        if (!mp[i]) continue;
        if (tot) cout << ",";
        mp[i] = tot++;
        cout << i;
    }
    cout << "};\nint[] index = new int[]{";
    for (int i = 0; i < (int)s.length(); ++i) {
        if (i) cout << ",";
        cout << mp[s[i]-'0'];
    }
    cout << "};\n";
    return 0;
}
