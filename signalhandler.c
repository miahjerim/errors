#include "main.h"
/**
 * sigint_handler - handle the SIGINT signal moreso Ctrl+C
 * @signum: The signal number
 *
 * Return: Void
 */
void sigint_handler(int signum)
{
	(void)signum;

	write(STDOUT_FILENO, "\n", 1);
	prompt();
}