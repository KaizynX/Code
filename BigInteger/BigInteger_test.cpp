#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
	long long n;
	double start,finish;
	cin >> n;
	for(int i = 1; i <= n; ++ i)
	{
		// create the data
		system("E:\\Learning\\Code\\BigInteger\\BigInteger_data.exe");
		// calcute the right answer
		system("E:\\Learning\\Code\\BigInteger\\BigInteger_cul.exe");
		// run the program
		start = clock();
		system("E:\\Learning\\Code\\BigInteger\\BigInteger.exe");
		finish = clock();
		if(system("fc E:\\Learning\\Code\\BigInteger\\test.out E:\\Learning\\Code\\BigInteger\\test_ans.out"))
		{
			cerr << "WA" << endl;
			return 0;
		}
		else
		{
			printf("date:%d %.1fms\n",i,finish - start);
		}
	}
	return 0;
}
