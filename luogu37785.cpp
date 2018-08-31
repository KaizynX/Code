#include <cstdio>
#include <iostream>

using namespace std;

const string Tcame = "came!";
const string Tleft = "left!";
const string Sstart = "started playing games!";
const string Sstop = "stopped playing games!";
const string Bad = "How Bad Oiers Are!";
const string Good = "How Good Oiers Are!";

int n, has_t, states[10], died[10];
size_t lent[10], lens[10];
string teacher[10], student[10];
string message, words;

inline int find_teacher(string &str)
{
    for(int i = 1; i <= 3; ++i)
        if(str.find(teacher[i]) == 0) return i;
    return 0;
}

inline int find_student(string &str)
{
    for(int i = 1; i <= 5; ++i)
        if(str.find(student[i]) == 0) return i;
    return 0;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= 3; ++i)
    {
        cin >> teacher[i];
        lent[i] = teacher[i].length();
    }
    for(int i = 1; i <= 5; ++i)
    {
        cin >> student[i];
        lens[i] = student[i].length();
    }
	scanf("\n");
    while(n--)
    {
        getline(cin, message);
        int tea = find_teacher(message);
        if(tea)
        {
            words = message.substr(lent[tea]+1, message.length()-lent[tea]-1);
            if(words == Tcame)
            {
                has_t = 1;
                for(int i = 1; i <= 5; ++i)
                    if(states[i]) died[i] = 1;
            }
            else if(words == Tleft)
                has_t = 0;
        }
        else
        {
            int stu = find_student(message);
            if(!stu) continue;
            words = message.substr(lens[stu]+1, message.length()-lens[stu]-1);
            if(words == Sstart)
            {
                states[stu] = 1;
                if(has_t) died[stu] = 1;
            }
            else if(words == Sstop)
                states[stu] = 0;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= 5; ++i)
        if(died[i])
        {
            if(cnt) cout << " ";
            cout << student[i];
            ++cnt;
        }
    if(cnt) cout << endl;
    if(cnt == 5) cout << Bad << endl;
    else if(cnt == 0) cout << Good << endl;
    return 0;
}
