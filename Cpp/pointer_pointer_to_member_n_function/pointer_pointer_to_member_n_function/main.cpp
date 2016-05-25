#include <Windows.h>
#include <iostream>

using namespace std;

class Hello
{
public:
	int x;
	Hello(int x) : x(x)
	{
		cout << "Constructor is calling." << endl;
	}
	void fun()
	{
		cout << "Fun is calling." << endl;
	}
};

int main(int argc, char **argv)
{
	int Hello::*ptr_x = &Hello::x;
	void(Hello::*ptr_fun)() = &Hello::fun;
	Hello hello(10);
	/*Pointer to member*/
	cout << hello.*ptr_x << endl;
	/*Pointer to funtion*/
	(hello.*ptr_fun)();
	Sleep(2000);
	return 0;
}