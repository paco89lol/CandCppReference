#include <Windows.h>
#include <iostream>

using namespace std;
int pass_by_value(int x)
{
	x = 4;
	return x;
}
void pass_by_reference(int &x)
{
	x = 5;
}
void pass_by_pointer(int *x)
{
	*x = 6;
}
int main(int argc, char **argv)
{
	int y, *ptr = &y;
	y = 19;
	y = pass_by_value(y);
	pass_by_reference(y);// y or *ptr are also accepted
	pass_by_pointer(&y);// &y or ptr are also accepted
	cout << y<<endl;
	Sleep(2000);
	return 0;
}