#include <cstdio>
#include <cstring>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 25;
const int Maxp = 107;

int m, n, p;
int lie[Maxn], res[Maxn], guilty[Maxn], today[10];
string name[Maxn];

inline int getnum(string str)
{
	for(int j = 1; j <= m; ++j)
		if(name[j] == str) return j;
	return 0;
}

inline int getday(string str)
{
	if(str == "Monday")    return 1;
	if(str == "Tuesday")   return 2;
	if(str == "Wednesday") return 3;
	if(str == "Thursday")  return 4;
	if(str == "Friday")    return 5;
	if(str == "Saturday")  return 6;
	if(str == "Sunday")    return 7;
	return 0;
}

struct Word
{
	string message;
	int say, glt, is_not, day;
	Word(){ say = 0; glt = 0; is_not = 0; day = 0; }
	inline void analyse()
	{
		string tmp = message.substr(0, message.find(":"));
		say = getnum(tmp);
		tmp = message.substr(message.find(" ")+1);
		if(tmp == "I am guilty.")
			glt = say, is_not = 1;
		else if(tmp == "I am not guilty.")
			glt = say, is_not = -1;
		else if(tmp.substr(tmp.find(" ")+1) == "is guilty.")
			glt = getnum(tmp.substr(0, tmp.find(" "))), is_not = 1;
		else if(tmp.substr(tmp.find(" ")+1) == "is not guilty.")
			glt = getnum(tmp.substr(0, tmp.find(" "))), is_not = -1;
		else if(tmp.substr(0, 8) == "Today is")
			day = getday(tmp.substr(9, tmp.length()-10));
#ifdef DEBUG
		printf("say:%d glt:%d is_not:%d day:%d\n", say, glt, is_not, day);
#endif
	}
} word[Maxp];

int main()
{
	scanf("%d%d%d", &m, &n, &p);
	for(int i = 1; i <= m; ++i)
		cin >> name[i];
	getline(cin, word[0].message); // \r\n
	for(int i = 1; i <= p; ++i)
	{
		getline(cin, word[i].message);
		word[i].analyse();
	}
	int cur = (1<<n)-1, x, y, flag, cnt = 0, days;
	while(cur < 1<<m)
	{
		memset(guilty, 0, sizeof guilty);
		memset(today, 0, sizeof today);
		flag = 1; days = 0;
		// set the lier
		for(int i = 1; i <= m; ++i)
			lie[i] = (cur>>(i-1))&1;
		// analyse the words
		for(int i = 1; i <= p; ++i)
		{
			// not say about guilty
			if(!word[i].is_not)
			{
				// useless words
				if(word[i].day == 0) continue;
				int tmp = lie[word[i].say] ? -1 : 1;
				if(!today[word[i].day]) 
				{
					today[word[i].day] = tmp;
					if(tmp == 1 && ++days > 1) { flag = 0; break; }
				}
				else if(today[word[i].day] != tmp) { flag = 0; break; }
			}
			else
			{
				int tmp = (word[i].is_not == 1)^lie[word[i].say] ? 1 : -1;
				if(!guilty[word[i].glt]) guilty[word[i].glt] = tmp;
				else if(guilty[word[i].glt] != tmp) { flag = 0; break; }
			}
		}
		// set the answer
		if(flag)
		{
			for(int i = 1; i <= m; ++i)
			{
				// more than one case who tell the lie
				if(cnt && res[i]^(guilty[i] == 1))
				{
					cout << "Cannot Determine" << endl;
					return 0;
				}
				if(guilty[i] == 1) res[i] = 1;
			}
			cnt++;
		}
		// come to next case
		x = cur&-cur;
		y = cur+x;
		cur = ((cur&~y)/x>>1)|y;
	}
	
	cnt = 0; flag = 0;
	for(int i = 1; i <= m; ++i)
		if(res[i]) cnt++, flag = i;
	if(cnt > 1) cout << "Cannot Determine" << endl;
	else if(!cnt) cout << "Impossible" << endl;
	else cout << name[flag] << endl;
	return 0;
}
/*
2 2 4
HELLO
GUILTY
HELLO: What is your name?
GUILTY: I am GUILTY.
GUILTY: Are you guilty?
HELLO: I am not guilty.

Me: Impossible
True: HELLO
*/
