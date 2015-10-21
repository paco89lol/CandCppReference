#include <assert.h>
#include <Windows.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
	int i, copy_time;
	char buffer[BUFFER_SIZE];
	FILE *fp_read;
	FILE *fp_write;

	copy_time = 2;
	fopen_s(&fp_read, "text.txt", "r");
	assert(fp_read);
	fopen_s(&fp_write, "output_text.txt", "w");
	assert(fp_write);

	for (i = 0; i<copy_time; ++i)
	{
		fseek(fp_read,0,SEEK_SET);
		fseek(fp_write,0,SEEK_END);
		while (fgets(buffer, BUFFER_SIZE, fp_read) != NULL)
		{
			fputs(buffer, fp_write);
		}
		fputc('\n', fp_write);
	}

	fclose(fp_read);
	fclose(fp_write);
	return 0;
}
