#include <iostream>
#include <fstream>
#include <assert.h>
#include <Windows.h>

#define BUFFER_SIZE 1024

using namespace std;

int main(int argc, char **argv)
{
	int i, copy_time;
	
	copy_time = 2;
	ifstream file_read("text.txt");
	assert(file_read);
	ofstream file_write("output_text.txt");
	assert(file_write);
	
	for (i = 0; i<copy_time; ++i)
	{
		file_read.seekg(0, ios::beg);
		file_write.seekp(0, ios::end);
		file_write << file_read.rdbuf() << endl;
	}

	Sleep(1000);
	return 0;
}