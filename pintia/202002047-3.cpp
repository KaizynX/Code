#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

string str;

int main()
{
    getline(cin, str);
    int cnt = 0;
    for (char c : str) {
        if (c == '6') {
            ++cnt;
        } else {
            if (cnt > 9) {
                cout << "27";
            } else if (cnt > 3) {
                cout << "9";
            } else {
                for (int i = 0; i < cnt; ++i)
                    cout << '6';
            }
            cnt = 0;
            cout << c;
        }
    }
    if (cnt) {
        if (cnt > 9) {
            cout << "27";
        } else if (cnt > 3) {
            cout << "9";
        } else {
            for (int i = 0; i < cnt; ++i)
                cout << '6';
        }
    }
    cout << endl;
    return 0;
}
