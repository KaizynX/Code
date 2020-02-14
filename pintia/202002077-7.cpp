#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
char ch[] = "GPLT";

string s;
int cnt[4];

inline bool check()
{
    for (int i = 0; i < 4; ++i)
        if (cnt[i]) return true;
    return false;
}

int main()
{
    getline(cin, s);
    for (unsigned i = 0; i < s.length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] += 'A'-'a';
    }
    for (char c : s) {
        if (c == 'G') ++cnt[0];
        if (c == 'P') ++cnt[1];
        if (c == 'L') ++cnt[2];
        if (c == 'T') ++cnt[3];
    }
    while (check()) {
        for (int i = 0; i < 4; ++i)
            if (cnt[i]) {
                putchar(ch[i]);
                --cnt[i];
            }
    }
    putchar('\n');
    return 0;
}
