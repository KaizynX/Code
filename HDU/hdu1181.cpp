#include <bits/stdc++.h>

using namespace std;

int f[26][26];

inline void add_edge(const string &str) {
    f[str.front()-'a'][str.back()-'a'] = 1;
}

int main()
{
    string str;
    while (cin >> str) {
        memset(f, 0, sizeof f);
        while (str != "0") {
            add_edge(str);
            cin >> str;
        }
        for (int k = 0; k < 26; ++k)
        for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            f[i][j] |= f[i][k]&f[k][j];
        cout << (f['b'-'a']['m'-'a'] ? "Yes." : "No.") << endl;
    }
    return 0;
}
