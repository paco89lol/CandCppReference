#include <Windows.h>
#include <fstream>
#include <iostream>
#include <assert.h>

#include "Data.cpp"

using namespace std;

int main(int argc, char **argv)
{
	int i;
	Data tmp_data;
	ifstream read_binary;

	read_binary.open("data.bin",ios::binary);
	assert(read_binary);
	i = 1;
	while (read_binary.read((char *)&tmp_data, sizeof(Data)))
	{
		cout << "Student\t"<<i<<" ----> "<<"Name: "<<tmp_data.name<<"\tID: "<<tmp_data.student_id<< endl;
		++i;
	}
	Sleep(2000);
	return 0;
}