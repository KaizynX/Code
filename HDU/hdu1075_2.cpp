#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

int n;
string word[N], str, article;

struct TireTree
{
    static const int SZ = 5e5+7;
    int nex[SZ][26], tar[SZ], cnt;
    TireTree() {
        memset(nex, 0, sizeof nex);
        cnt = 0;
    }
    void insert(const string &s, const int id) {
        int p = 0;
        for (int i = 0, c; i < (int)s.length(); ++i) {
            c = s[i]-'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;
            p = nex[p][c];
        }
        tar[p] = id;
    }
    string find(const string &s) {
        int p = 0;
        for (int i = 0, c; i < (int)s.length(); ++i) {
            c = s[i]-'a';
            if (!nex[p][c]) return s;
            p = nex[p][c];
        }
        return tar[p] ? word[tar[p]] : s;
    }
} TT;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str;
    while (cin >> str && str != "END") {
        word[++n] = str;
        cin >> str;
        TT.insert(str, n);
    }
    cin >> str; cin.get();
    while (getline(cin, str) && str != "END")
        article += str+'\n';
    for (int i = 0, j; i < (int)article.length();) {
        if (article[i] < 'a' || article[i] > 'z') cout << article[i++];
        else {
            str = "";
            j = 0;
            while (article[i+j] >= 'a' && article[i+j] <= 'z')
                str += article[i+j++];
            i += j;
            cout << TT.find(str);
        }
    }
    return 0;
}
