#include <stdio.h>
#include <stdlib.h> //EXIT_SUCCESS
#include <math.h> //pow();
#include <windows.h> //Sleep();

void my_error_log(const char *str);
int make_food(int food, int size_of_arr,unsigned int *p_gb_arr);
//void int_to_binary(size_t size, void *ptr);

int main(void)
{
	int i,j,k;
	int is_true, is_gameover;
	int width, height, score, food, keyboard, tmp, direction;
	unsigned int *p_gb_arr;
	int *p_snack_arr, arr_start;

	is_true = 1;
	is_gameover = 0;
	keyboard = 0;
	score = 0;
	width = 40;
	height = 20;
	(p_gb_arr = calloc(width*height, sizeof(int)) == NULL) ? my_error_log("Fail to allocate memory for p_gb_arr.") : NULL;
	(p_snack_arr = calloc(width*height, sizeof(int)) == NULL) ? my_error_log("Fail to allocate memory for p_snack_arr.") : NULL;
	//init gameboard
	for (i = 0;i<width*height; ++i)
	{
		tmp = i;
		((i / height == 0 || i / height == height - 1) || (i % width == 0 || i % width == width - 1)) ? tmp |= (1 << 26): NULL;
		*(p_gb_arr + i) = tmp;
	}
	//init snack
	for (i = width*2+6,j=arr_start;i>=width*2+2; --i,++j)
	{
		*(p_snack_arr + j) = i;
		*(p_gb_arr + i) = *(p_gb_arr + i) | (1<<25);
	}
	//init food
	food = make_food(food, width*height, p_gb_arr);

	//function - check hit board
	(*(p_snack_arr + arr_start) >> 25 == 2) ? is_gameover = 1 : NULL;
	//function - check eat itself
	for (i = arr_start+1; *(p_snack_arr + i) != 0; ++i)
	{
		(i == width*height) ? i=0: NULL;
		(*(p_snack_arr + arr_start) == *(p_snack_arr + i)) ? is_gameover = 1: NULL;
	}
	//function - print gameboard
	for (i = 0;i<width*height;++i)
	{
		(i != 0) ? ((i%width == 0) ? printf("\n") : NULL) : NULL;
		(*(p_gb_arr + i) >> 26 == 1) ? printf("♯") : ((*(p_gb_arr + i) >> 25 == 1) ? printf("☼") : ((*(p_gb_arr + i) >> 24 == 1) ? printf("❤") : printf(" ")));
	}
	//function - update snack
	direction = ((tmp = *(p_snack_arr + arr_start) - *(p_snack_arr + ((arr_start + 1 > width*height-1) ? 0 : arr_start))) > 0) ? ((abs(tmp) > 1) ? width/*bottom*/ : 1/*right*/) /*right or bottom*/ : ((abs(tmp) > 1) ? -width/*up*/ : -1/*left*/)/*left or up*/;
	tmp = *(p_snack_arr + arr_start) + (keyboard == -3275 || keyboard == 97) ? -1/*left*/ : ((keyboard == -3277 || keyboard == 100) ? 1/*right*/ : ((keyboard == -3272 || keyboard == 119) ? -width/*up*/ : ((keyboard == -3280 || keyboard == 115) ? width/*bottom*/ : direction)));
	(direction - tmp == 0) ? tmp = direction : NULL;
	tmp += *(p_snack_arr+arr_start);
	keyboard = 0;
	//insert new dot
	*(p_snack_arr + ((--arr_start < 0) ? arr_start = width*height - 1 : arr_start)) = tmp | (1<<25);
	//if snack is yet to eat food, delete the last dot
	//else make a new food
	if ((*(p_gb_arr+tmp) & (1<<24)) == 0)
	{
		for (i = arr_start; *(p_snack_arr + i) != 0; ++i)
		{
			(i == width*height) ? i = 0 : NULL;
		}
		tmp = *(p_snack_arr + ((i - 1 < 0) ? width*height - 1 : i - 1));
		*(p_gb_arr + tmp) = *(p_gb_arr + tmp) | (1 << 25);
		*(p_snack_arr + ((i - 1 < 0) ? width*height - 1 : i - 1)) = 0;
	}
	else
	{
		food = make_food(food, width*height, p_gb_arr);
	}
	getchar();
	free(p_gb_arr);
	free(p_snack_arr);
	return EXIT_SUCCESS;
}
void my_error_log(const char *str)
{
	printf("%s", str);
	Sleep(2000);
	exit(EXIT_FAILURE);
}
int make_food(int food, int size_of_arr, unsigned int *p_gb_arr)
{
	int tmp;
	*(p_gb_arr + food) = *(p_gb_arr + food) & ~(1<<24);
	srand((unsigned)time(0));
	do
	{
		tmp = rand() % size_of_arr;
	} while (*(p_gb_arr + tmp) >> 25 > 0);
	*(p_gb_arr + tmp) = *(p_gb_arr + tmp) | (1 << 24);
	return tmp;
}
/*
void int_to_binary(size_t size, void *ptr)
{
	unsigned char tmp;
	int i,j;
	char *my_ptr = (char *)ptr;

	for (j = size-1;j>=0; --j)
	{
		for (i = 7;i>=0; --i)
		{
			tmp = (*(my_ptr + j) & (1<<i));
			tmp >>= i;
			printf("%u",tmp);

		}
	}
}
*/
