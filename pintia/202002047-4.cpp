#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T;
string s;
vector<string> v;

int main()
{
    cin >> T;
    cin.get();
    while (T--) {
        getline(cin, s);
        int p1 = s.find(','), p2 = s.find('.');
        if (s.substr(p1-3, 3) == "ong" && s.substr(p2-3, 3) == "ong") {
            v.clear();
            stringstream ss;
            ss << s;
            while (ss >> s) {
                v.emplace_back(s);
            }
            for (int i = 0; i < (int)v.size()-3; ++i)
                cout << v[i] << " ";
            cout << "qiao ben zhong.\n";
        } else {
            cout << "Skipped\n";
        }
    }
    return 0;
}
