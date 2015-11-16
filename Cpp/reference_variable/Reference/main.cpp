#include <Windows.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int x;
	int &ref = x;
	ref = 10;
	cout << x << endl; // output 10
	Sleep(2000);
	return 0;
}