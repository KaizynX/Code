#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, res;

inline bool check(string &str)
{
    string tmp;
    for (int i = 0; i < str.length()-2; ++i) {
        tmp = str.substr(i, 3);
        if (tmp == "AGC" || tmp == "ACG" || tmp == "GAC")
            return false;
    }
    return true;
}

void dfs(int cur, string str)
{
    if (cur > n) {
        if (check(str)) {
            ++res;
        } else {
            cout << str << endl;
        }
        return;
    }

    dfs(cur+1, str+'A');
    dfs(cur+1, str+'C');
    dfs(cur+1, str+'G');
    dfs(cur+1, str+'T');
}

int main()
{
    cin >> n;
    dfs(1, "");
    cout << res << endl;
    return 0;
}
