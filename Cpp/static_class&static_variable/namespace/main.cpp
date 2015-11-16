#include <Windows.h>
#include <iostream>

class Hello
{
	static int z;
	static Hello obj;
	Hello()
	{
	}
	Hello(int x, int y) :x(x), y(y)
	{
	};
public:
	int x;
	int y;
	
	static void setZ(int x)
	{
		z = x;
	}
	int getZ()
	{
		return z;
	}
	static Hello * getInstance()
	{
		return &obj;
	}
};
int Hello::z; //This must be defined after where the class/struct declares.  
Hello Hello::obj(1,2);

using namespace std;

int main(int argc, char **argv)
{
	cout << Hello::getInstance() << endl;
	cout << Hello::getInstance() << endl;
	Sleep(2000);
	return 0;
}