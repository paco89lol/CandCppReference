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

	/*Offset a current pointer of the stream*/
	//in.seekg(0, ios::beg); //optional 
	//out.seekp(0,ios::beg); //optioal 

	/*Method: 1*/
	out << in.rdbuf() << endl; //rdbuf() is to return a current pointer of the stream.

	/*Method: 2 */
	/*
	while (in.getline(buf, BUFFER_SIZE))
	{
		out << buf << std::endl;
	}
	*/

	Sleep(2000);

	return 0;
}