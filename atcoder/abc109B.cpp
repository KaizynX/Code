#include <map>
#include <iostream>

using namespace std;

const int Maxn = 107;

int n;
char last;
string str;
map<string, int> m;

int main()
{
    cin >> n >> str;
    m.insert(make_pair(str, 1));
    last = str[str.length()-1];
    for(int i = 1; i < n; ++i)
    {
        cin >> str;
        if(str[0] != last || m.count(str))
        {
            cout << "No" << endl;
            return 0;
        }
        m.insert(make_pair(str, 1));
        last = str[str.length()-1];
    }
    cout << "Yes" << endl;
    return 0;
}
