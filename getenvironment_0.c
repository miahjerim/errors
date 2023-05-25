#include "shell.h"

/**
 * _getenv - retrieves the value of an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @name: Name of the environment variable
 *
 * Return: The value of the environment variable
 */
char *_getenv(info_t *info, const char *name)
{
	char *s
	list_t *node = info->env;

	while (node)
	{
		s = starts_with(node->str, name);
		if (s && *s)
			return (s);
		node = node->next;
	}
	return (NULL);
}

/**
 * _myenv - prints the current environment variables
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 * Return: Always returns 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _mysetenv - Initializes a new environment variable or modifies an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always returns 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Removes the specified environment variable from the environment
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always returns 0
 */
int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);

	return (0);
}

/**
 * populate_env_list - populates the environment linked list
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 * Return: Always returns 0
 */
int populate_env_list(info_t *info)
{
	size_t x;
	list_t *node = NULL;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);
	info->env = node;
	return (0);
}
