#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define DEBUG

using namespace std;

const int Maxn = 5e4 + 7;

string at_sb,said;

struct Message
{
	vector<string> str;

	Message(){}
	
	inline void add(const string &tmp) { str.push_back(tmp); }
	inline size_t size() { return str.size(); }
	inline size_t length() { return str.back().length(); }

	inline string get_sender()
	{
		string &tmp = str.back();
		return tmp.substr(0, tmp.find(':')-1);
	}
	inline string get_reciever(size_t st = 0)
	{
		string &tmp = str.back();
		size_t pos = tmp.find('@',st);
		if(pos == tmp.npos) return "NO";
		// pos+01234567890123
		//    "@yyy loves XXX"
		return tmp.substr(pos+1,tmp.find(' ',pos+11)-pos-1);
	}
	inline int judge() 
	{
		// first one
		if(str.size() == 1)
		{
			at_sb = get_reciever();
			return 0;
		}
		else
		{
			if(get_sender() == at_sb) return 1;
			// if @ more than one
			size_t pos = 0;
			string tmp;
			while( (tmp = get_reciever(pos)) != "NO")
			{
				if(tmp != at_sb) return 2;
				pos = str.back().find('@',pos) + 1;
			}
			// if @ no
			return pos == 0 ? 2 : 0;
		}
	}

} message;

istream &operator >> (istream &in, Message &m)
{
	string tmp;
	getline(in,tmp);
	m.add(tmp);
	return in;
}

int main()
{
	// file end with a empty line
	while(cin >> message && message.length() != 0)
	{
#ifdef DEBUG
		cout << message.get_sender() <<'!'<< endl;
		cout << message.get_reciever() <<'!'<< endl;
		// cout << message.get_words() <<'!'<< endl;
#endif
		if(message.judge() == 1)
		{
			cout << "Successful @" << at_sb << " attempt" << endl;
			return 0;
		}
		else if(message.judge() == 2)
		{
			cout << "Unsuccessful @" << at_sb << " attempt" << endl
			     << message.size() << endl
				 << message.get_sender() << endl;
			return 0;
		}
	}
	cout << "Unsuccessful @" << at_sb << " attempt" << endl
		 << message.size()-1 << endl // last line is none
		 << "Good Queue Shape" << endl;
	return 0;
}
