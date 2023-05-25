#include "shell.h"

/**
 * _strncpy - copies a string with specified length
 * @dest: Destination string
 * @src: Source string
 * @n: Number of characters to copy
 * Return: Pointer to the destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *p = dest;
	int x, y;

	x = 0;
	while (src[x] != '\0' && x < n - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < n)
	{
		y = x;
		while (y < n)
		{
			dest[y] = '\0';
			y++;
		}
	}
	return (p);
}

/**
 * _strncat - concatenates two strings with a max length
 * @dest: The first string
 * @src: The second string
 * @n: Max bytes to be used
 * Return: Pointer to the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	char *s = dest;
	int j, i;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - finds a character in a string
 * @p: The string to search in
 * @x: The character to find
 * Return: A pointer to the first occurrence of the character
 */
char *_strchr(char *p, char x)
{
	do {
		if (*p == x)
			return (p);
	} while (*p++ != '\0');

	return (NULL);
}
