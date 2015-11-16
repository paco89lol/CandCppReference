#include <Windows.h>
#include <iostream>
#include <time.h> //time() //localtime_s()

using namespace std;

/*
 *It is the "tm" structure in a C std library.
 */
/*
struct tm {
	int tm_sec; 0-59 minutes
	int tm_min; 0-59 minutes
	int tm_hour; 0-23 hours
	int tm_mday; day of month
	int tm_mon; 1-12 months
	int tm_year; calendar year
	int tm_wday; Sunday == 0 , etc.
	int tm_yday; 0-365 day of year
	int tm_isdst; daylight savings?
}
*/

int main(int argc, char **argv)
{
	time_t timer;
	tm my_tm;

	timer = time(NULL); // return total seconds from 1970

	localtime_s(&my_tm, &timer);// It is to set a "tm" struct which stored the time information based on the total seconds.
	cout << " ";
	cout << my_tm.tm_mon << "\\";
	cout << my_tm.tm_mday << "\\";
	cout << my_tm.tm_year << " ";
	cout << my_tm.tm_hour << ":";
	cout << my_tm.tm_min << ":";
	cout << my_tm.tm_sec << " " << endl;

	Sleep(2000);
	return 0;
}