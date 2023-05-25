#include "main.h"
/**
 * form_arguments - converts command line into arguments
 * @cmd: command to use
 * @arguments: array to store args
 * @max_arguments: max no of args
 *
 * Return: no of args
 */
int form_arguments(char *cmd, char **arguments, int max_arguments)
{
	int argc = 0;/*count arguments*/
	char *token = strtok(cmd, " ");/*tokenize the command line string*/

	for (; token != NULL && argc < max_arguments - 1; token = strtok(NULL, " "), argc++)
	{
		arguments[argc] = token;
		/*assign token to arguments array*/
	}
	arguments[argc] = NULL;
	return argc;
}
/**
 * handle_command - forks a child process using execve
 * @command: command to be executed
 * @arguments: array of command args
 *
 * Return: 1 on success
 */
int handle_command(char *command, char **arguments)
{
	pid_t pid;/*process ID*/

	pid = fork();/*forks child process*/

	if (pid == -1)/*check if fork failed*/
	{
		write(STDERR_FILENO, "Error:fork failed\n", 18);
		exit(EXIT_FAILURE);
	} 
	/*child process*/
	else if (pid == 0)
	{
		/*execute command*/
		if (execve(command, arguments, NULL) == -1)
		/*if execve fails, write error msg, exit*/ 
		{
			write(STDERR_FILENO, command, i);

			/*write command to std error output*/
			write(STDERR_FILENO, "Error: command not found\n", 25);

			exit(EXIT_FAILURE);
		}

	}
	else
	/*parent process*/
	{
		int status;

		waitpid(pid, &status, 0);
		/*wait for the child process to finish and store status*/
	}
	return (1);/*return 1 to show success*/
}