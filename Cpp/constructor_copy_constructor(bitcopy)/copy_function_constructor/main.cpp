#include <Windows.h>
#include <iostream>

using namespace std;

class Hello
{
public:
	int x;
	Hello()
	{
		cout << "Hello constructor is calling." << endl;
	}
	/*The Copy-Constructor (Bitcopy)*/
	/*
	 *Every class implicitly has a copy-constructor, a bitcopy by default
	 *, which is not suitable for a class which contains a pointer data.
	 *You will have a result that only have another pointer pointing to the same data. 
	 */
	Hello(const Hello &hello)
	{
		cout << "Copy function constructor" << endl;
		x = hello.x;
	}

	~Hello()
	{
		cout << "Hello destructor is calling." << endl;
	}
};

Hello fun(Hello obj) //This line will call a Copy constructor 
{
	cout << "Fun function:" << endl;
	return obj; //This line will call a Copy constructor 
}
Hello * fun_ref(Hello &obj)
{
	cout << "Fun_ref function:" << endl;
	return &obj;
}
int main(int argc, char **argv)
{
	Hello hello;
	hello.x = 10;
	system("cls");
	fun(hello);
	cout << endl;

	fun_ref(hello);
	Sleep(2000);
	return 0;
}