#include "shell.h"

/* string functions */

/**
 * _strlen - length of a string
 * @s: string
 * Return: length of string
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);

}

/**
 * _puts - prints a string
 * @str : string
 * Return: 0
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		putchar(str[i]);
	putchar('\n');
}
/**
 * _putchar - writes a character to STDOUT
 * @c: The character to print
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcpysource - copies a string at specific index
 * @dest: destination
 * @src: source (index)
 * @n: legnth of destination
 * Return: string copied
*/
char *_strcpysource(char *dest, char *src, int n)
{
	int c;

	for (c = 0 ; src[c] != '\0' ; c++, n++)
		dest[c] = src[n];
	dest[c] = '\0';
	return (dest);
}
