#include <Windows.h>
#include <iostream>

using namespace std;

class Object
{
	int x;
	int y;
	void fun0();
	void fun1(int x, int y);
	Object()
	{
		int x;
	}
};
class Object1
{
	int x;
	int y;
};

int main(int argc, char **argv)
{
	printf("The size of Object with one function = %d\n",sizeof(Object));
	printf("The size of Object with no function  = %d\n",sizeof(Object1));
	Sleep(2000);
	return 0;
}