#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;

int lena, lenb;
char a[kN], b[kN];
int nex[kN], extend[kN];

inline void GetNext(char *s, int *_nex)
{
    int len = strlen(s);
    int a = 0, p = 0;
    _nex[0] = len;
    for (int i = 1; i < len; ++i) {
        if (i >= p || i+_nex[i-a] >= p) {
            if (i > p) p = i;
            while (p < len && s[p] == s[p-i]) ++p;
            a = i;
            _nex[i] = p-i;
        } else {
            _nex[i] = _nex[i-a];
        }
    }
}


inline void GetExtend(char *s, char *ss, int *_ext, int *_nex)
{
    int lens = strlen(s), lenss = strlen(ss);
    int a = 0, p = 0;
    for (int i = 0; i < lens; ++i) {
        if (i >= p || i+_nex[i-a] >= p) {
            if (i > p) p = i;
            while (p < lens && p-i < lenss && s[p] == ss[p-i]) ++p;
            a = i;
            _ext[i] = p-i;
        } else {
            _ext[i] = _nex[i-a];
        }
    }
}

int main()
{
    scanf("%s%s", &a, &b);
    lena = strlen(a);
    lenb = strlen(b);
    GetNext(b, nex);
    GetExtend(a, b, extend, nex);
    for (int i = 0; i < lenb; ++i)
        printf("%d%c", nex[i], (i == lenb-1 ? '\n' : ' '));
    for (int i = 0; i < lena; ++i)
        printf("%d%c", extend[i], (i == lena-1 ? '\n' : ' '));
    return 0;
}
