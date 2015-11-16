#include <Windows.h>
#include <iostream>

using namespace std;

struct Hello // this class only need 8 bytes memory to create a instance
{
	int x; // 4 bytes
	const int y; // 4 bytes
	static int z; // staic dont occupy memory
	enum // enum dont occupy memory
	{
		A, B, C, D
	} my_enum;
	Hello() :y(5)
	{

	}
};
int Hello::z = 10;//initialization of a static variable 

int main(int argc, char **argv)
{
	cout << sizeof(Hello);
	Sleep(2000);
	return 0;
}
