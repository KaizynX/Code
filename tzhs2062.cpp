#include <iostream>

using namespace std;

const string c = "`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?"; 

int main()
{
	string str;
	while(getline(cin, str))
	{
		for(size_t i = 0; i < str.length(); ++i)
		{
			cout << (str[i] == ' ' ? ' ': c[ c.find(str[i])-1 ] );
		}
	}
	return 0;
}
