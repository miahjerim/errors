#include "main.h"
/**
 * main - simple shell program
 *
 * Return: EXIT_SUCCESS on success
 */
int main(void)
{
	char *cmd;
/*set signal handler for SIGINT signal(Ctrl+c)*/
	signal(SIGINT, sigint_handler);
/*run an infinite loop*/
	while (1)

	{
		
		prompt();/*display prompt*/
		cmd = read_line();/*read users input*/

		/*if input is NULL, exit*/
		if (cmd == NULL)

		{
			write(STDOUT_FILENO, "Exiting\n", 8);
			break;
		}
		/*if not empty, handle command*/
		if (cmd[0] != '\0')
		{
			execute_command(cmd);
		}
		free(cmd);/*free memory*/
	}

	return (EXIT_SUCCESS);

}