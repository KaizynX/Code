#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define DEBUG

using namespace std;

const int Maxl = 100;

int T;

struct Node
{
    int l, o, true_o, num_f, err;
    int arg[256];
    inline void init()
    {
        l = o = true_o = num_f = err = 0;
        memset(arg, 0, sizeof arg);
    }

} info;

inline int get_O()
{
    string s;
    cin >> s;
    if(s[2] == '1') return 0;
    int res = 0, pos = 4;
    while(pos < (int)s.length() && isdigit(s[pos]))
        res = res*10+(s[pos++]-'0');
    return res;
}

inline int get_i()
{
    string s;
    cin >> s;
    if(s == "n") return -1;
    int pos = 0, res = 0;
    while(pos < (int)s.length() && isdigit(s[pos]))
        res = res*10+(s[pos++]-'0');
    return res;
}

inline void get_flag(int x, int y, int &flag, int &add)
{
    if(x == -1 && y != -1) flag = 0, add = 0; // n 1
    else if(y == -1) flag = 1, add = 1; // 1/n n
    else if(x <= y) flag = 1, add = 0; // 1 1/2
    else if(x > y) flag = 0, add = 0; // 2 1
}

int read(int now, int flag) // n^now, is bad for? return is end?
{
    if(info.l == 0) return 0;
    info.l--;
    info.true_o = max(info.true_o, now);

    char op, arg;
    int x, y, nex_flag = 0, add_o = 0;
    cin >> op;
    if(op == 'F')
    {
        info.num_f++;
        cin >> arg;
        if(info.arg[(int)arg]) info.err = 1;
        info.arg[(int)arg]++;
        x = get_i(); y = get_i();
        get_flag(x, y, nex_flag, add_o);
        /*
        if(flag) read(now+add_o, nex_flag);
        else read(now, flag); // bad for
        */
        while(read(now+(flag ? add_o : 0), min(flag, nex_flag)));
        info.arg[(int)arg]--;
        return 1;
    }
    else if(op == 'E')
    {
        // F & E
        if(info.num_f == 0) info.err = 1;
        else info.num_f--;
        return 0;
    }
    return 0;
}

int main()
{
    cin >> T;
    while(T--)
    {
        info.init();
        cin >> info.l;
        info.o = get_O();
        /*
#ifdef DEBUG
        printf("O(%d)\n", info.o);
#endif
        */
        while(info.l) read(0, 1);
        if(info.num_f || info.err) cout << "ERR" << endl;
        else cout << (info.o == info.true_o ? "Yes" : "No") << endl;
    }
    return 0;
}
