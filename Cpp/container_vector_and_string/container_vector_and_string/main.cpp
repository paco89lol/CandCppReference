#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int i;
	vector<string> vec_str; // declare vector containing a data type of string.
	string str0 = "A";
	string str1 = "B";
	string str2 = "C";
	string str3 = "D";
	string str4 = "E";
	str4 = str0 + str1 + str3 + str4 + "F"; //string type can allow you to use "+" operator to concatenate strings.

	vec_str.push_back(str0);//push_back(<T>) is to add T to the current vector
	vec_str.push_back(str1);
	vec_str.push_back(str2);
	vec_str.push_back(str3);
	vec_str.push_back(str4);

	for (i = 0; i < vec_str.size(); ++i)
	{
		cout << vec_str[i]<<endl;
	}
	Sleep(2000);
	return 0;
}