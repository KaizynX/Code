#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int n;
char s[N];

int main()
{
    scanf("%d%s", &n, s);
    for (int i = 0, len = strlen(s); i < len; ++i) {
        s[i] = (s[i]-'A'+n)%26+'A';
    }
    printf("%s\n", s);
    return 0;
}
