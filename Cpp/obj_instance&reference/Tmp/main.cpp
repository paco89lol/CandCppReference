#include <iostream>
#include <Windows.h>

using namespace std;

struct Hello
{
	int x;
};

int main(int argc, char **argv)
{
	Hello hello, *ref_hello;
	hello.x = 100;
	ref_hello = &hello;
	printf("X = %d", ref_hello->x);

	Sleep(2000);
	return 0;
}
