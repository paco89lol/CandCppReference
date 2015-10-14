//#include <iostream>
#include <Windows.h>
#include <fstream> //it included <iostream>
#include <assert.h>
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
	
	char buf[BUFFER_SIZE];

	std::ifstream in("text.txt");
	assert(in);
	std::ofstream out("output_text.txt");
	assert(out);

	while (in.getline(buf, BUFFER_SIZE))
	{
		out << buf << std::endl;
	}
	
	Sleep(2000);

	return 0;
}