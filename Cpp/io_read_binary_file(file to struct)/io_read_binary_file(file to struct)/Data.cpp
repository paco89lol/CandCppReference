#include <iostream>

struct Data
{
	char name[8];
	char student_id[8];
	Data()
	{
	}
	Data(const char *string_name, const char *string_student_id)
	{
		strcpy_s(name, 20, string_name);
		strcpy_s(student_id, 20, string_student_id);
	}
};
