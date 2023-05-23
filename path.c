#include "main.h"
#include <stdlib.h> 
#include <string.h> 
#include <sys/stat.h>
/**
 * path_find - finds the path to the command
 * @cmd: pointer to an array of commands 
 *
 * Return: pointer to thr path , 0 if not found
 */

char *path_find(char **cmd)
{
char *path = getenv("PATH");
char *dir;
char *path_hold = strtok(path, ":");
struct stat buffer;
/*calculate the length of string and store in dir_len*/
int dir_len = _strlen(argv[0]);
/*check if has  NULL */
while (path_hold != NULL)
{
/*calculate contents of path_hold */
size_t path_len = _strlen(path_hold);
/*allocate memory for path_len and path_hold */ 
dir = malloc(dir_len + path_len + 2);

/*check if malloc was successful */

if (dir == NULL) 
{
/*check if  allocation failed*/
return (NULL);
}
/*copy path_hold to dir*/

_strcpy(dir, path_hold);

/*append  characters to dir*/
_strcat(dir, "/");
_strcat(dir, argv[0]);
_strcat(dir, '\0');

/*check if stat retrieved infor successesfuly */
if (stat(dir, &buffer) == 0) 
{
/*File exists, return the path*/
return (dir);
}
/*free memory allocated to dir*/
free(dir);
/*check if all the path have been tokenized yet */
path_hold = strtok(NULL, ":");
}

/* File not found in any of the directories*/
return (0);
}
