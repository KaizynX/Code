#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int kN = 1e5+7;
const int kL = 1e6+7;

int n;
string res, str, tmp;
int nex[kL];

void GetNext(const string &s, int *_nex)
{
    _nex[0] = -1;
    int k = -1, j = 0;
    while (j < s.length()) {
        if (k == -1 || s[k] == s[j]) {
            // _nex[++j] = ++k;
            ++j; ++k;
            if (s[j] != s[k])
                _nex[j] = k;
            else 
                _nex[j] = _nex[k];
        } else {
            k = _nex[k];
        }
    }
}

int main()
{
    cin >> n >> res;
    for (int i = 2, p; i <= n; ++i) {
        cin >> str;
        if (res.length() > str.length()) {
            tmp = str+res.substr(res.length()-str.length());
        } else {
            tmp = str.substr(0, res.length())+res;
        }
        GetNext(tmp, nex);
        p = min(nex[tmp.length()], (int)min(str.length(), res.length()));
        res += str.substr(p);
#ifdef DEBUG
        cout << nex[tmp.length()] << " " << res << endl;
#endif
    }
    cout << res << endl;
    return 0;
}
