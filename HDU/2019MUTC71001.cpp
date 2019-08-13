#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int kN = 1e5+7;

int T;
int len[10], p[10];
char str[10][kN];

inline bool cmp_small(int x, int y)
{
    if(len[x] != len[y]) return len[x] < len[y];
    for(int i = 1; i <= len[x]; ++i) {
        if (str[x][i] != str[y][i])
            return str[x][i] < str[y][i];
    }
    return false;
}

inline bool cmp_equal(int x, int y)
{
    if(len[x] != len[y]) return false;
    for(int i = 1; i <= len[x]; ++i) {
        if (str[x][i] != str[y][i])
            return false;
    }
    return true;
}

inline void str_minus(int x, int y)
{
    // x-y x>y
    for(int i = 1; i <= len[x]; ++i) {
        char vy = (i <= len[y] ? str[y][i] : '0');
        if(str[x][i] < vy) {
            str[x][i] += 10;
            --str[x][i+1];
        }
        str[6][i] = str[x][i]-vy+'0';
    }
    len[6] = len[x];
    while(len[6] > 1 && str[6][len[6]] == '0') --len[6];
}

inline void print(int i1, int i2, int i3)
{
    int minp = min(p[i1], min(p[i2], p[i3]));
    printf("%d %d %d\n", p[i1]-minp, p[i2]-minp, p[i3]-minp);
}

#ifdef DEBUG
inline void print_num(int x)
{
    printf("%d %d:", x, len[x]);
    for(int i = 1; i <= len[x]; ++i)
        putchar(str[x][i]);
    putchar('\n');
}
#endif

int main()
{
    scanf("%d", &T);
    while(T--) {
        int flag = 1;
        // 输入，去掉末尾的0
        for(int i = 0; i < 3; ++i) {
            scanf("%s", str[i]+1);
            p[i] = 0;
            len[i] = strlen(str[i]+1);
            while(len[i] > 1 && str[i][len[i]] == '0')
                --len[i], --p[i];
        }
        // c-a == b ?
        // c-b == a ?
        for(int it = 0; it < 2; ++it) {
            int i[3] = { it+3, (it^1)+3, 5 };
            // 拷贝一下
            for(int j = 0; j < 3; ++j) {
                len[i[j]] = len[i[j]-3];
                p[i[j]] = p[i[j]-3];
                for(int k = 1; k <= len[i[j]]; ++k)
                    str[i[j]][k] = str[i[j]-3][k];
            }

            // 使得恰好 c >= a
            while(len[i[2]] < len[i[0]])
                str[i[2]][++len[i[2]]] = '0', p[i[2]]++;
            // now len[2] == len[i1]
            if (cmp_small(i[2], i[0])) // str[2] < str[i1]
                str[i[2]][++len[i[2]]] = '0', p[i[2]]++;
#ifdef DEBUG
            print_num(i[0]);
            print_num(i[2]);
#endif

            while(len[i[0]] < len[i[2]])
                str[i[0]][++len[i[0]]] = '0', p[i[0]]++;
            // now len[i1] == len[2]
            if (cmp_small(i[2], i[0]))
                --len[i[0]], p[i[0]]--;

#ifdef DEBUG
            print_num(i[0]);
            print_num(i[2]);
#endif
            //for(int j = 0; j < 3; ++j) 
            //    reverse(str[i[j]]+1, str[i[j]]+len[i[j]]+1);
            reverse(str[i[0]]+1, str[i[0]]+len[i[0]]+1);
            reverse(str[i[2]]+1, str[i[2]]+len[i[2]]+1);
            str_minus(i[2], i[0]);
            reverse(str[6]+1, str[6]+len[6]+1);
            while(len[6] > 1 && str[6][len[6]] == '0') --len[6], ++p[i[1]];
#ifdef DEBUG
            print_num(6);
            print_num(i[1]);
#endif
            if (cmp_equal(i[1], 6)) {
                print(3, 4, 5);
                flag = 0;
                break;
            }
        }
        if (!flag) continue;
        printf("-1\n");
    }
    return 0;
}
