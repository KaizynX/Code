#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2+7;

int n;
string str;
vector<int> v;

int main()
{
    cin >> str;
    if (str.length() == 1) {
        cout << 0 << endl;
        return 0;
    }
    int flag = 0;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == '1') {
            flag = 1;
            break;
        }
    }
    if (str.length()&1)
        cout << str.length()/2+(flag ? 1 : 0) << endl;
    else cout << str.length()/2 << endl;
    return 0;
}
