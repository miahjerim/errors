#include "main.h"

/**
 * execute_command - execute command by forking a child process & using execve.
 * @command: the command.
 *
 * Return: 1 if successful.
 */
int execute_command(char *command)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		char error_message[] = "Error: Failure on fork\n";

		write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		char *args[] = {command, NULL}

		if (execve(command, args, NULL) == -1)
		{
			char error_message[] = "Error: not found\n";

			write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
			write(STDERR_FILENO, command, my_strlen(command));
			write(STDERR_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}
	} else
	{
		int status;

		waitpid(pid, &status, 0);
	}
	return (1);
}
/**
 * my_strlen - calculate the length of a string.
 * @str: the input string.
 *
 * Return: the length of the string.
 */
size_t my_strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}