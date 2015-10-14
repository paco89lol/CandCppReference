#include <stdio.h>
#include <assert.h>
#include <Windows.h>
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{

	FILE *fp_read;
	FILE *fp_write;
	char buffer[BUFFER_SIZE];

	fopen_s(&fp_read, "text.txt", "r");
	assert(fp_read);
	fopen_s(&fp_write, "output_text.txt", "w");
	assert(fp_read);

	/*offset FILE current pointer*/
	//fseek(fp_read, 0, SEEK_SET); //optional 
	//fseek(fp_write,0, SEEK_SET); //optional

	while (fgets(buffer, BUFFER_SIZE, fp_read) != NULL)
	{
		fputs(buffer,fp_write);
	}
	fclose(fp_read);
	fclose(fp_write);
	Sleep(2000);
	return 0;
}