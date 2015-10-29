#include <Windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Phone
{
private:
	int window_width = 100; // this is private
	int window_height;
public:
	void set_window_width(int window_width);
	//friend int Smartphone::get_phone_width(Phone *ptr_phone);
	friend struct Smartphone; //it gives a way for other classes to access or modify members , evevn if it is a private.
};
void Phone::set_window_width(int window_width)
{
	this->window_width = window_width;
}
class Smartphone
{
public:
	int get_phone_width(Phone *ptr_phone);

};
int Smartphone::get_phone_width(Phone *ptr_phone)
{
	return ptr_phone->window_width;
}

int main(int argc, char **argv)
{
	Phone phone;
	Smartphone smartphone;
	phone.set_window_width(100);
	printf("The phone window width is: %d\n", smartphone.get_phone_width(&phone));

	Sleep(2000);
	return 0;
}