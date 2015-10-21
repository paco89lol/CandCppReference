#include <iostream>
#include <assert.h>
#include <fstream>
#include <Windows.h>

using namespace std;

int main(int argc, char **argv)
{
	int i, copy_time;
	copy_time = 1;
	ifstream file_read("text.txt", ios::in | ios::out);
	ifstream file_read_tmp("text.txt", ios::in | ios::out);
	ostream file_write(file_read.rdbuf());
	
	file_write.seekp(0, ios::end);
	file_write << endl;

	for (i = 0; i < copy_time; ++i)
	{
		file_write.seekp(0, ios::end);
		file_write << file_read_tmp.rdbuf();
	}

	Sleep(1000);
	return 0;
}