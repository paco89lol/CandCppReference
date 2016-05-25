#include <Windows.h>
#include <iostream>

using namespace std;

class Has_cc
{
public:
	int x;
	Has_cc(){}
	Has_cc(int x)
	{
		this->x = x;
	}
	Has_cc(const Has_cc &obj)
	{
		x = obj.x;
		cout << "Has_cc Copy Constructor is calling." << endl;
	}
};
class No_cc
{
public:
	int x;
	No_cc(){}
	No_cc(int x)
	{
		this->x = x;
	}
};
class Com
{
private:
	/*
	 *If we want to prevent someone to pass object by value,
	 *we can set a copy constructor declaration as private and no definition of the copy constructor.
	 */
	//Com(const Com &obj);
public:
	Has_cc has_cc;
	No_cc no_cc;
	Com(int a, int b) :has_cc(a),no_cc(b)
	{
	}
	Com(const Com &obj) :has_cc(Has_cc(obj.has_cc)), no_cc(No_cc(obj.no_cc))
	{
		//has_cc = Has_cc(obj.has_cc);
		//no_cc = No_cc(obj.no_cc);
		cout << "Com Copy Constructor is calling." << endl;
	}
};

int main(int argc, char **argv)
{
	Com com(1,2);
	Com com_copy = com; // Com com_copy = Com(com);
	Sleep(2000);
	return 0;
}