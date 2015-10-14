#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void error_log(const char *str);
void make_food(int *food, int size_gameboard, char *p_arr);
DWORD WINAPI thread_get_keyboard(int *tmp_keyboard);

typedef struct SNACK
{
	int position;
	int offset;
	char *ptr;
	struct Snack *pre, *next;
}Snack;

int main(void)
{
	int i = 0,  j= 0, k = 0;
	int is_gg = 0;
	int width = 40, height = 20;
	int food, score = 0;
	int snack_size = 4, keyboard = 0, tmp, direction = 1, tmp_offset = 0;

	char *p_arr;
	Snack *head_snack = NULL, *tail_snack, *p_snack = NULL, *tmp_snack = NULL;

	if ((p_arr = calloc(width*height, sizeof(char))) == NULL)
		error_log("Failure to allocate memory for p_arr.");

	for (i = 0; i<width*height; ++i)
	{
		if (i / width == 0 || i / width == height - 1 || i%width == 0 || i%width == width - 1)
			*(p_arr + i) = '#';
		else
			*(p_arr + i) = ' ';
	}
	for (i = 0, tmp = width + snack_size; i<snack_size; ++i, --tmp)
	{
		p_snack = malloc(sizeof(Snack));
		//if (p_snack = malloc(sizeof(Snack)) == NULL)
		//	error_log("Failure to allocate memory for p_snack.");
		//if it is not the first element in a linklist, set the previous next and offset.
		
		if (tmp_snack != NULL)
		{
			tmp_snack->next = p_snack;
			p_snack->offset = tmp_snack->position - tmp;
			p_snack->pre = tmp_snack;
		}
		else
		{
			p_snack->offset = 0;
			head_snack = p_snack;
		}
		p_snack->position = tmp;
		p_snack->ptr = p_arr + tmp;
		*(p_snack->ptr) = '@';
		//save current element for next loop;
		tmp_snack = p_snack;
	}
	tail_snack = tmp_snack;
	make_food(&food, width*height, p_arr);
	HANDLE thread = CreateThread(NULL, 0, thread_get_keyboard, &keyboard, 0, NULL);

	while (1)
	{
		system("cls");
		//generate a new dot position
		if (keyboard == 75 || keyboard == 97)
			tmp = -1;
		else if (keyboard == 77 || keyboard == 100)
			tmp = 1;
		else if (keyboard == 72 || keyboard == 119)
			tmp = -width;
		else if (keyboard == 80 || keyboard == 115)
			tmp = width;
		else
			tmp = 0;
		keyboard = 0;
		if (tmp == 0 || (tmp + direction) == 0)
			tmp = direction;
		else
			direction = tmp;
		tmp = tmp + head_snack->position;
		//check hit boundary || eat itself
		if (*(p_arr + tmp) == '#' || (*(p_arr + tmp) == '@' && tmp != tail_snack->position))
			is_gg = 1;

		//check is game over
		if (is_gg == 1)
		{
			CloseHandle(thread);
			system("cls");
			printf("You got %d score.\nGame Over.");
			Sleep(3000);
			exit(EXIT_SUCCESS);
		}
		//move
		//if eat food
		// add new dot
		//else
		// update the last dot become the front dot;
		if (tmp == food)
		{
			++score;
			if ((p_snack = malloc(sizeof(Snack))) == NULL)
				error_log("Faliure to allocate memory for a new p_snack.");
			p_snack->position = tmp;
			p_snack->offset = tmp - head_snack->position;
			p_snack->ptr = (p_arr + tmp);
			*(p_snack->ptr) = '@';
			p_snack->next = head_snack;

			head_snack->pre = p_snack;
			head_snack->offset = head_snack->position - ((Snack *)head_snack->next)->position;
			//update head_snack;
			head_snack = p_snack;

			make_food(&food, width*height, p_arr);
		}
		else
		{
			((Snack *)tail_snack->pre)->next = NULL;
			*(tail_snack->ptr) = ' ';

			p_snack = tail_snack;
			tmp_snack = tail_snack->pre;
			p_snack->pre = NULL;
			p_snack->next = head_snack;
			p_snack->position = tmp;
			p_snack->offset = tmp - head_snack->position;
			p_snack->ptr = (p_arr + tmp);
			*(p_snack->ptr) = '@';
			
			head_snack->pre = p_snack;
			head_snack->offset = head_snack->position - ((Snack *)head_snack->next)->position;
			//update head_snack and tail_snack
			tail_snack = tmp_snack;
			head_snack = p_snack;
		}
		//print
		for (i = 0; i<width*height; ++i)
		{
			if (i != 0 && i%width == 0)
				printf("\n");
			printf("%c", *(p_arr + i));
		}
		//sleep
		Sleep(900);
	}
	free(p_arr);
	for (p_snack = head_snack; p_snack != NULL;)
	{
		tmp_snack = p_snack->next;
		free(p_snack);
		p_snack = tmp_snack;
	}
	return EXIT_SUCCESS;
}

void error_log(const char* str)
{
	printf("%s", str);
	Sleep(2000);
	exit(EXIT_FAILURE);
}
void make_food(int *food, int size_gameboard, char *p_arr)
{
	srand((unsigned)time(0));
	do
	{
		*food = (rand() * rand()) % size_gameboard;
	} while (*(p_arr + *food) != ' ');
	*(p_arr + *food) = 'A';
}
DWORD WINAPI thread_get_keyboard(int *keyboard)
{
	for (;;)
	{
		*keyboard = _getch();
	}
}
