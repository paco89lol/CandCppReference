#include <iostream>
#include <strstream>

using namespace std;

class Sth
{
	char *str;
public:
	Sth(char * Str){str = Str;}
	~Sth();
	friend ostream& operator<<(ostream&, Sth&);
};

ostream& operator<<(ostream& os, Sth& sth)
{
	return os << sth.str;
}

int main(int argc, char **argv)
{
	cout << Sth("ABC")<<endl;
	return 0;
}