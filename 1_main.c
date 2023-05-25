#include "main.h"
/**
 * main - handles arguments
 *
 * Return: EXIT_SUCCESS on success
 */
int main(void)
{
	char *cmd;
	char *arguments[MAX_ARGUMENTS];

/*set signal handler for SIGINT signal (Ctrl+c)*/
	signal(SIGINT, sigint_handler);

/*infinite loop*/
	while (1)
	{

		prompt();/*display prompt to user*/
		cmd = read_line();/*read input*/

		if (cmd == NULL)/*if input is NULL exit*/
		{
			write(STDOUT_FILENO, "Exit\n", 8);
			break;
		}

		if (cmd[0] != '\0')/*if input not empty handle command*/
		{
			/*create argument array for input command*/
			int argc = create_arguments(cmd, arguments, MAX_ARGUMENTS);
			/*execute command with command name and arguments*/
			execute_command(arguments[0], arguments);
		}

		free(cmd);/*free memory*/

	}

	return (EXIT_SUCCESS);

}