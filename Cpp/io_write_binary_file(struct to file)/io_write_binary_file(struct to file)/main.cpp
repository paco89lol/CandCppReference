#include <Windows.h>
#include <iostream>
#include <fstream>


struct Data
{
	char name[8];
	char student_id[8];
	Data()
	{
	}
	Data(const char *string_name, const char *string_student_id)
	{
		strcpy_s(name,20, string_name);
		strcpy_s(student_id, 20, string_student_id);
	}
};


using namespace std;

int main(int argc, char **argv)
{
	int i;
	Data datas[3];
	ofstream write_binary;
	
	*(datas + 0) = Data("Paco", "D001");
	*(datas + 1) = Data("Kitty", "D002");
	*(datas + 2) = Data("Sally", "D003");
	write_binary.open("data.bin", ios::binary);

	for (i = 0; i < sizeof(datas) / sizeof(Data); ++i)
	{
		write_binary.write((const char *)(datas + i), sizeof(Data));
	}
	
	Sleep(2000);
	return 0;

}