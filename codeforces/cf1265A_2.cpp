#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, T;
char s[N];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s+1);
        int n = strlen(s+1), flag = 1;
        s[0] = s[n+1] = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '?') {
                for (int j = 0; j < 3; ++j) {
                    if ('a'+j != s[i-1] && 'a'+j != s[i+1]) {
                        s[i] = 'a'+j;
                        break;
                    }
                }
            }
            if (s[i] == '?' || s[i] == s[i-1] || s[i] == s[i+1]) {
                flag = 0;
                break;
            }
        }
        if (flag) puts(s+1);
        else puts("-1");
    }
    return 0;
}

