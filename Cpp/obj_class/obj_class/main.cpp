#include <Windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct Hello //default all functions and members are public 
{
	void say_hello();
};
class Bye //default all functions and members are private   
{
public:
	void say_bye();
};

void Hello::say_hello()
{
	printf("Hello!\n");
}
void Bye::say_bye()
{
	printf("Bye!\n");
}

int main(int argc, char **argv)
{
	Hello hello;
	Bye bye;

	hello.say_hello();
	bye.say_bye();
	return 0;
}