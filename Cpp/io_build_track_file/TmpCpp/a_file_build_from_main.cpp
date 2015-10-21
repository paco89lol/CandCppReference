#include <iostream>;
#include <Windows.h>;
#include <fstream>;
#define TRACK_AND_RUN(a) file_track_write << #a << endl; a
#define WRITE_IN(a) file_track_write << #a << endl;
using namespace std;
ofstream file_track_write("a_file_build_from_main.cpp");
int main (int argc, char **argv)
{
int num;
int num1;
num = 3;
num1 = 3;
printf("num + num1 is: %d\n", num + num1);
cout << "a_file_build_from_main.cpp file has been built." << endl;
Sleep(3000);
return 0;
}
