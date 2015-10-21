#include <iostream>
#include <Windows.h>
#include <fstream>

#define TRACK_AND_RUN(a) file_track_write << #a <<endl; a
#define WRITE_IN(a) file_track_write << #a << endl;

using namespace std;

ofstream file_track_write("a_file_build_from_main.cpp");

int main(int argc, char **argv)
{
	WRITE_IN(#include <iostream>;);
	WRITE_IN(#include <Windows.h>;);
	WRITE_IN(#include <fstream>;);
	WRITE_IN(#define TRACK_AND_RUN(a) file_track_write << #a << endl; a);
	WRITE_IN(#define WRITE_IN(a) file_track_write << #a << endl;);
	WRITE_IN(using namespace std;);
	WRITE_IN(ofstream file_track_write("a_file_build_from_main.cpp"););
	WRITE_IN(int main (int argc, char **argv));
	WRITE_IN({);
	TRACK_AND_RUN(int num;);
	TRACK_AND_RUN(int num1;);
	TRACK_AND_RUN(num = 3;);
	TRACK_AND_RUN(num1 = 3;);
	TRACK_AND_RUN(printf("num + num1 is: %d\n", num + num1););
	TRACK_AND_RUN(cout << "a_file_build_from_main.cpp file has been built." << endl;);
	TRACK_AND_RUN(Sleep(3000););
	WRITE_IN(return 0;);
	WRITE_IN(});
	return 0;
}