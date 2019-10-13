#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+7;

int n, ls, rs, le, re;
string str;

int main()
{
    cin >> n >> str;
    for (int i = 0; i < n/2; ++i) {
        if (str[i] == '?') ++le;
        else ls += str[i]-'0';
    }
    for (int i = n/2; i < n; ++i) {
        if (str[i] == '?') ++re;
        else rs += str[i]-'0';
    }

    if (ls > rs) swap(ls, rs), swap(le, re);
    // ls <= rs
    if (ls == rs) {
        cout << (le == re ? "Bicarp" : "Monocarp") << endl;
        return 0;
    }
    if (le <= re) {
        cout << "Monocarp" << endl;
        return 0;
    }
    le -= re;
    int me = (le+1)/2, be = le/2;
    if (me > be || be*9 < rs-ls || me*9 > rs-ls) {
        cout << "Monocarp" << endl;
        return 0;
    }
    cout << "Bicarp" << endl;
    return 0;
}
