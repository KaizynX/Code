#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxt = 3e5+7;
const int Maxm = 1e3+7;
const int Maxs = 1e8+7;

int m, s, t, rest;

int main()
{
    cin >> m >> s >> t;
    m /= 2;
    int tmp = m/5, T = t;
    if(min(t, tmp)*60 >= s)
    {
        cout << "Yes" << endl << (int)ceil(s/60.0) << endl;
        return 0;
    }
    rest = s - min(t, tmp)*60;
    m -= 5 * min(t, tmp);
    t -= min(t, tmp);
    while(t && rest > 0)
    {
        if(m == 1 || m == 2)
        {
            if(rest <= 34 || t <= 2)
            {
                tmp = (int)ceil(rest/17.0);
                rest -= 17*min(t, tmp);
                t -= min(t, tmp);
            }
            else
            {
                t -= 3;
                m -= 1;
                rest -= 60;
            }
        }
        else if(m == 3 || m == 4)
        {
            if(rest <= 17 || t <= 1)
            {
                t--;
                rest -= 17;
            }
            else
            {
                t -= 2;
                m -= 3;
                rest -= 60;
            }
        }
        else if(m == 0)
        {
            if(t <= 4 || rest <= 68)
            {
                tmp = (int)ceil(rest/17.0);
                rest -= 17*min(t, tmp);
                t -= min(t, tmp);
            }
            else
            {
                t -= 4;
                rest -= 60;
                m = 1;
            }
        }
    }
    if(rest > 0) cout << "No" << endl << s-rest << endl;
    else cout << "Yes" << endl << T - t << endl;
    return 0;
}
