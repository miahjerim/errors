#include "shell.h"

/**
 * _strcpy - Copies a string
 * @dest: The destination
 * @src: The source
 *
 * Return: Pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - Creates a duplicate of a string
 * @str: The string to duplicate
 *
 * Return: Pointer to the newly allocated duplicated string,
 *         or NULL if memory allocation fails
 */
char *_strdup(const char *str)
{
	char *ret;
	int length = 0;


	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - Prints a string to the standard output
 * @str: The string to be printed
 *
 * Return: None
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - Writes the character c to the standard output
 * @c: The character to print
 *
 * Return: On success, 1.
 *         On error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}