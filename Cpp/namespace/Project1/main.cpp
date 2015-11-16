#include <Windows.h>
#include <iostream>

namespace paco {
	int x;
	int y;
}

using namespace std;

/*
 * we can think that the variable x and y are stored in a undefine namespace,
 * which is the mean that we can change the values by using the namespace specifier(e.g. now, ::x and ::y).
 */
int  x;
int  y;

class Hello
{
public:
	Hello()
	{
		x = 444;// the x variable is depended on outer variable x;
		y = 444;// the y variable is depended on outer variable y;
		paco::x = 777;
		paco::y = 777;
	}
	void print()
	{
		cout << "x: " << ::x << "\ny: " << ::y << endl;
	}
	void paco_print()
	{
		cout << "paco_x: " << paco::x << "\npaco_y: " << paco::y << endl;
	}
};

int main(int argc, char **argv)
{
	Hello hello;
	hello.print();
	hello.paco_print();
	Sleep(2000);
	return 0;
}