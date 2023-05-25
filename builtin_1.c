#include "shell.h"

/**
 * _myalias - emulates the behavior of the "alias" built-in command (man alias)
 * @info: A structure that holds possible arguments. It is used to preserve
 *         the function prototype consistently.
 * Return: Always returns 0
 */
int _myalias(info_t *info)
{
	list_t *node = NULL;
	int x = 0;
	char *s = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		s = _strchr(info->argv[x], '=');
		if (s)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}

/**
 * myhistory - displays the history list, with each command on a separate line
 *              preceded by line numbers starting at 0.
 * @info: A structure that holds possible arguments. It is used to preserve
 *        the function prototype consistently.
 * Return: Always returns 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - assigns a string value to an alias
 * @info: parameter struct
 * @str: the string representing the alias
 *
 * Return: Always returns 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	int ret;
	char *s, c;

	s = _strchr(str, '=');
	if (!s)
		return (1);
	c = *s;
	*s = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*s = c;
	return (ret);
}

/**
 * set_alias - assigns a string value to an alias
 * @info: parameter struct
 * @str: the string representing the alias
 *
 * Return: Always returns 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *s;

	s = _strchr(str, '=');
	if (!s)
		return (1);
	if (!*++s)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints the string value of an alias
 * @node: the alias node
 *
 * Return: Always returns 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *a = NULL, *s = NULL;

	if (node)
	{
		s = _strchr(node->str, '=');
		for (a = node->str; a <= s; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(s + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}