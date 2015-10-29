#include <Windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct Hello
{
	void say_hello();
	void say_goodbye()
	{
		printf("say_goodbye() => Goodbye!\n");
	}
	void setNum(int num);
	int getNum();
	friend void say_hello_to_others();
private:
	int num;
};

void Hello::say_hello()
{
	printf("say_hello() => Hello, everyone!\n");
}
void Hello::setNum(int num)
{
	this->num = num;
}
int Hello::getNum()
{
	return this->num;
}
void say_hello_to_others()
{
	printf("Hello, the others!");
}

int main(int argc, char **argv)
{
	say_hello_to_others(); // It is a static function inside the "Hello" class
	Hello hello; // it is a object intance.
	hello.say_hello();
	hello.say_goodbye();
	hello.setNum(10);
	printf("The object stored num is: %d\n", hello.getNum());

	Sleep(2000);
	return 0;
}