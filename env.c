#include "main.h"
/**
 * env - fucntion used to get environ variables
 *
 * Return: 1 - successful
 */
int  *env(void)
{
	size_t i = 0;
	/* check if the value of i is not NULL*/

	while(environ[i] != NULL)
	{
		if (_puts(environ[i]) == -1 || _puts("\n") == -1)
			return (-1);
		i++;
	}
	return (0);
}
/**
 * shellexit - free memory and exits the shell program
 *@cmd: commandlinepointer to be freed
 *@lineptr: input buffer to be freed
 */
int shellexit(char **cmd, char *lineptr)
{
	/*cleanup memory */
	free_all(cmd, lineptr, NULL);
	exit(EXIT_SUCCESS);
}
