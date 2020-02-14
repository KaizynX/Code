#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

int n;
string word[N], str, article;

struct TireTree
{
    static const int SZ = 1e5+7;
    int nex[SZ][256], tar[SZ], cnt;
    TireTree() {
        memset(nex, 0, sizeof nex);
        cnt = 0;
    }
    void insert(const string &s, const int id) {
        int p = 0;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (!nex[p][s[i]]) nex[p][s[i]] = ++cnt;
            p = nex[p][s[i]];
        }
        tar[p] = id;
    }
    int find(int s) {
        int p = 0;
        for (int i = s; i < (int)article.length(); ++i) {
            int c = article[i];
            if (!nex[p][c]) break;
            p = nex[p][c];
            if (tar[p]) {
                cout << word[tar[p]];
                return i+1;
            }
        }
        return s;
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
    cin >> str;
    while (getline(cin, str) && str != "END")
        article += str+'\n';
    for (int i = 0, j; i < (int)article.length(); i = j) {
        j = TT.find(i);
        if (j == i) cout << article[j++];
    }
    return 0;
}
