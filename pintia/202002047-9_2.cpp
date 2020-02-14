#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T;
string s, str;
stringstream ss;
vector<string> v;

inline bool biaodian(char c)
{
    return !isalpha(c) && !isdigit(c);
}

int main()
{
    cin >> T;
    cin.get();
    while (T--) {
        getline(cin, s);
        str = "";
        cout << s << endl << "AI: ";
        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] != 'I' && s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a'-'A';
            if (s[i] == '?') s[i] = '!';
            if (biaodian(s[i])) {
                str += ' '; str += s[i];
            } else {
                str += s[i];
            }
        }
        ss.clear();
        v.clear();
        ss << str;
        while (ss >> s) v.emplace_back(s);
        for (unsigned i = 0; i < v.size(); ++i) {
            if (v[i] == "can" && i+1 < v.size() && v[i+1] == "you") {
                v[i] = "I"; v[i+1] = "can";
            } else if (v[i] == "could" && i+1 < v.size() && v[i+1] == "you") {
                v[i] = "I"; v[i+1] = "could";
            } else if (v[i] == "I" || v[i] == "me") {
                v[i] = "you";
            }
        }
        for (unsigned i = 0; i < v.size(); ++i) {
            cout << v[i];
            if (i+1 == v.size()) { cout << '\n'; break; }
            if (biaodian(v[i+1][0])) continue;
            cout << ' ';
        }
    }
    return 0;
}
