#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const string res[] = {"ChuiZi", "Bu", "JianDao"};

int k, t;
string s;

int main()
{
    cin >> k;
    while (cin >> s && s != "End") {
        if (++t > k) {
            t = 0;
            cout << s << endl;
        } else {
            for (int i = 0; i < 3; ++i) {
                if (s == res[i]) {
                    cout << res[(i+1)%3] << endl;
                }
            }
        }
    }
    return 0;
}
