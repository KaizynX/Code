#include <bits/stdc++.h>

using namespace std;

const int kN = 1e2+7;

int T;
char s[kN];

int main()
{
    scanf("%d", &T);
    while (T--){
        scanf("%s", s);
        int p = 0, len = strlen(s);
        while (p < len && s[p] == 'y') ++p;
        if (s[p] != 'z') {
            printf("%s\n", s);
        } else {
            s[p] = 'b';
            printf("%s\n", s);
        }
    }
    return 0;
}
