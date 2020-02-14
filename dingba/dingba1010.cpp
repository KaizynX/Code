#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int T;
int cnt[26];

int main()
{
    scanf("%d", &T);
    char c;
    c = getchar();
    while (T--) {
        memset(cnt, 0, sizeof cnt);
        while ((c=getchar()) != '\n')
            if (c != ' ') ++cnt[c-'A'];
        for (int i = 0; i < 26; ++i)
            printf("%d%c", cnt[i], " \n"[i==25]);
    }
    return 0;
}
