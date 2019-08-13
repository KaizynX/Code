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
    _nex[0] = s.length();
    int a = 0, p = 0;
    for (int i = 1; i < s.length(); ++i) {
        if (i >= p || i+_nex[i-a] >= p) {
            if (i >= p) p = i;
            while (p < s.length() && s[p] == s[p-i]) ++p;
            _nex[i] = p-i;
            a = i;
        } else {
            _nex[i] = _nex[i-a];
        }
    }
}

int main()
{
    cin >> n >> res;
    for (int i = 2, p; i <= n; ++i) {
        cin >> str;
        p = 0;
        if (res.length() > str.length()) {
            tmp = str+res.substr(res.length()-str.length());
            GetNext(tmp, nex);
            for (int j = str.length(); j < tmp.length(); ++j)
                if (j+nex[j] == tmp.length()) p = max(p, nex[j]);
        } else {
            tmp = str.substr(0, res.length())+res;
            GetNext(tmp, nex);
            for (int j = res.length(); j < tmp.length(); ++j)
                if (j+nex[j] == tmp.length()) p = max(p, nex[j]);
        }
        p = min(p, (int)min(str.length(), res.length()));
        res += str.substr(p);
#ifdef DEBUG
        cout << nex[tmp.length()] << " " << res << endl;
#endif
    }
    cout << res << endl;
    return 0;
}
