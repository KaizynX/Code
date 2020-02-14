#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

struct TireTree
{
    static const int SZ = 2;
    char beg;
    int nex[N][SZ], cnt;
    bool exist[N];
    TireTree(char _beg = 'a') : beg(_beg) {
        memset(nex, 0, sizeof nex);
        memset(exist, 0, sizeof exist);
        cnt = 0;
    }
    bool insert(const char *s) {
        int len = strlen(s), p = 0, flag = 0;
        for (int i = 0, c; i < len; ++i, p = nex[p][c]) {
            c = s[i]-beg;
            if (exist[p]) return false;
            if (!nex[p][c]) {
                nex[p][c] = ++cnt;
                flag = 1;
            }
        }
        exist[p] = true;
        return flag;
    }
    bool insert(const string &s) { return insert(s.c_str()); }
    bool find(char *s) {
        int len = strlen(s), p = 0;
        for (int i = 0, c; i < len; ++i, p = nex[p][c]) {
            c = s[i]-beg;
            if (!nex[p][c]) return false;
        }
        return exist[p];
    }
};

int main()
{
    int T = 0, flag;
    string str;
    while (cin >> str) {
        TireTree tt('0');
        flag = 1;
        do {
            flag &= tt.insert(str);
            cin >> str;
        } while (str != "9");
        cout << "Set " << ++T << " is "
             << (flag ? "" : "not ")
             << "immediately decodable\n";
    }
    return 0;
}
