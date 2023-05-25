#include "main.h"

/**
 * read_line - Read input line in SO
 *
 * Return: input line as a string, OR NULL on end of file
 */
char *read_line(void)
{
	char *line = malloc(sizeof(char) * BUFFER_SIZE);

	if (line == NULL)
	{
		write(STDERR_FILENO, "Error: failure on malloc\n", 25);
		exit(EXIT_FAILURE);
	}
	ssize_t read_size;
	ssize_t total_size = 0;
	char c;

	while ((read_size = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (c == '\n')
		{
			line[total_size] = '\0';
			return (line);
		}
		line[total_size++] = c;
		if (total_size >= BUFFER_SIZE)
		{
			char *new_line = realloc(line, sizeof(char) * (BUFFER_SIZE + total_size));

			if (new_line == NULL)
			{
				write(STDERR_FILENO, "Error: failure on realloc\n", 26);
				exit(EXIT_FAILURE);
			}
			line = new line;
		}
	}
	if (read_size == -1)
	{
		write(STDERR_FILENO, "Error: failure on read\n", 23);
		exit(EXIT_FAILURE);
	} else
	{
		return (NULL);
	}
	free(line);
}