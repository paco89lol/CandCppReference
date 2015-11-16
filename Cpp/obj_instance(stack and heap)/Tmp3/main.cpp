#include <Windows.h>
#include <iostream>

using namespace std;

struct Hello // need 4 bytes
{
	int x;
};


int main(int argc, char **argv)
{
	Hello *tmp = (Hello *)malloc(sizeof(Hello));// It allocates 4 bytes momery in heap and return a heap address(the class instance) to pointer.
	Hello hello = *tmp;// It copies the class instance(in heap) to another class instance(4 bytes in stack). These two different instance have no any connection to each other.

	/*
	 * Create a Instance:
	 * - create in heap (1) // *Dont automatically free memory
	 * - create in stack (2) // *It only can survise in function
	 */

	/*(1)*/Hello *hello_1 = (Hello *)malloc(sizeof(Hello));
	free(tmp);

	/*(2)*/Hello hello_2;
	
	Sleep(2000);
	
	return 0;
}
