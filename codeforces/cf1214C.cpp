#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, cntl, cntr;
string str;

int main()
{
    cin >> n >> str;
    for (char c : str) {
        if (c == '(') ++cntl;
        else ++cntr;
    }
    if (cntl != cntr) {
        cout << "No" << endl;
        return 0;
    }
    cntl = cntr = 0;
    int flag = 0;
    for (char c : str) {
        if (c == '(') {
            ++cntl;
        } else {
            if (!cntl) {
                ++flag;
            } else {
                --cntl;
            }
        }
    }
    if (flag > 1 || cntl != flag) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
