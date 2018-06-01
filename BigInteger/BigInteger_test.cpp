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
		system("D:\\Learning\\Code\\BigInteger\\BigInteger_data.exe");
		// calcute the right answer
		system("D:\\Learning\\Code\\BigInteger\\BigInteger_cul.exe");
		// run the program
		start = clock();
		system("D:\\Learning\\Code\\BigInteger\\BigInteger.exe");
		finish = clock();
		if(system("fc D:\\test.out D:\\test_ans.out"))
		{
			cerr << "WA" << endl;
			system("D:\\test.in");
			system("D:\\test.out");
			system("D:\\test_ans.out");

			system("del D:\\test.in");
			system("del D:\\test.out");
			system("del D:\\test_ans.out");
			return 0;
		}
		else
		{
			printf("date:%d %.1fms\n",i,finish - start);
			system("del D:\\test.in");
			system("del D:\\test.out");
			system("del D:\\test_ans.out");
		}
	}
	return 0;
}
