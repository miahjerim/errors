#include "shell.h"

/**
 * get_environ - returns a copy of the string array variables
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 * Return: Pointer to the string array of environment variables
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Removes an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: The string representing the environment variable to be removed
 * Return: 1 if the variable is successfully deleted, 0 otherwise
 */
int _unsetenv(info_t *info, char *var)
{
	char *z;
	list_t *node = info->env;
	size_t i = 0;

	if (!node || !var)
		return (0);

	while (node)
	{
		z = starts_with(node->str, var);
		if (z && *z == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initializes a new environment variable or modifies an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: The string representing the environment variable to be set or modified
 * @value: The string representing the value of the environment variable
 * Return: Always returns 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	list_t *node;
	char *p;
	char *buf = NULL;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		x = starts_with(node->str, var);
		if (x && *x == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}