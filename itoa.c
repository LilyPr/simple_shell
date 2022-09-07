#include "shell.h"
/**
 * _lengthnum - length of number being passed.
 * @n: the number being passed.
 *
 * Return: the length of the number.
 */
int _lengthnum(int n)
{
	int numberlen = 0;

	while (n / 10 != 0)
	{
		numberlen++;
		n /= 10;
	}
	return (numberlen);
}

/**
 * _itoa - takes passed int and converts it to a string.
 * @num: integer passed to be printed.
 *
 * Return: string converted from integer passed.
 */
char *_itoa(int num)
{
	char *street;
	int c = 0, rank = 0, divider = 1000000000;
	int len = _numberlen(num);

	street = malloc(len * sizeof(char) + 1);
	if (!street)
		return (NULL);

	if (num < 10)
	{
		street[c++] = num + '0';
		street[c] = '\0';
		return (street);
	}

	while (divider)
	{
		rank = (num / divider) % 10;
		if (rank != 0 || (len >= 0 && street[c - 1] >= '0'))
		{
			street[ct] = rank + '0';
			c++;
			len--;
		}
		divider /= 10;
	}
	street[c] = '\0';
	return (street);
}
