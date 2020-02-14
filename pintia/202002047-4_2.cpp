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
        if (p1-3 >= 0 && s.substr(p1-3, 3) == "ong" && p2-3 >= 0 && s.substr(p2-3, 3) == "ong") {
            int p = s.length(), cnt = 0;
            while (cnt < 3) {
                if (s[--p] == ' ') ++cnt;
            }
            cout << s.substr(0, p) << " qiao ben zhong.\n";
        } else {
            cout << "Skipped\n";
        }
    }
    return 0;
}
