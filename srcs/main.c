#include "main.h"

int	main()
{
	int pos;
	int *test;

	test = (int*)malloc(2 * sizeof(int));
	// [2, 1]
	pos = 7;
	test[0] = 0x00;
	test[1] = 0xFF;

	printf("field[%d][%d] %d", pos / 8, (8 - 1 - pos % 8), GET_CELL(test, pos));
	return (0);
}
