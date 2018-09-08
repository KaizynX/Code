#include <cstdio>
#include <cstring>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 30;
const int Maxp = 110;

int n, m, p, ans, lier[Maxn];
string stud[Maxn];

inline int getnum(string str)
{
	for(int j = 1; j <= m; ++j)
		if(stud[j] == str) return j;
	return 0;
}

inline int getday(string str)
{
	if(str == "Monday.")    return 1;
	if(str == "Tuesday.")   return 2;
	if(str == "Wednesday.") return 3;
	if(str == "Thursday.")  return 4;
	if(str == "Friday.")    return 5;
	if(str == "Saturday.")  return 6;
	if(str == "Sunday.")    return 7;
	return 0;
}

struct Word
{
	int say, day, glt, nor;
	Word(){ say = day = glt = nor = 0; }
} word[Maxp];

int main()
{
	cin >> m >> n >> p;
	for(int i = 1; i <= m; ++i)
		cin >> stud[i];
	string str;
	for(int i = 1; i <= p; ++i)
	{
		cin >> str;
		str.erase(str.end()-1);
		word[i].say = getnum(str);
		getline(cin, str);
		str.erase(str.begin());
		str.erase(str.end()-1);
		if(str == "I am guilty.") word[i].glt = word[i].say, word[i].nor = 1;
		else if(str == "I am not guilty.") word[i].glt = word[i].say, word[i].nor = -1;
		else if(str.substr(0, 8) == "Today is") word[i].day = getday(str.substr(9));
		else if(str.substr(str.find(" ")) == " is guilty.")
			word[i].glt = getnum(str.substr(0, str.find(" "))), word[i].nor = 1;
		else if(str.substr(str.find(" ")) == " is not guilty.")
			word[i].glt = getnum(str.substr(0, str.find(" "))), word[i].nor = -1;
#ifdef DEBUG
		printf("%d %d %d %d\n", word[i].say, word[i].day, word[i].glt, word[i].nor);
#endif
	}
	for(int guilty = 1, flag; guilty <= m; ++guilty)
	{
		for(int today = 1; today <= 7; ++today)
		{
			flag = 1;
			memset(lier, 0, sizeof lier);
			for(int i = 1; i <= p && flag; ++i)
			{
				if(word[i].day)
				{
					if(!lier[word[i].say])
						lier[word[i].say] = word[i].day == today ? 1 : -1;
					else if((word[i].day == today)^(lier[word[i].say] == 1)) flag = 0;
				}
				else if(word[i].nor)
				{
					int tmp = (word[i].glt == guilty)^(word[i].nor == -1) ? 1 : -1;
					if(!lier[word[i].say]) lier[word[i].say] = tmp;
					else if(lier[word[i].say] != tmp) flag = 0;
				}
			}
			if(!flag) continue;
			int cnt_lier = 0, cnt_none = 0;
			for(int i = 1; i <= m; ++i)
				if(lier[i] == -1) ++cnt_lier;
				else if(lier[i] == 0) ++cnt_none;
			if(n < cnt_lier || n > cnt_lier+cnt_none) continue;
			if(!ans) ans = guilty;
			else if(ans != guilty)
			{
				cout << "Cannot Determine" << endl;
				return 0;
			}
		}
	}
	if(ans) cout << stud[ans] << endl;
	else cout << "Impossible" << endl;
	return 0;
}
