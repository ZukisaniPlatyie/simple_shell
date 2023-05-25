#include "shell.h"

/**
 *@path - ponter to store the cmd path 
 */

char *cmd_path(char *cmd_one)
{
	char *path;
	char *path_cpy;
	char *path_token;
	char *file_path;
	int dir_len = 0;
	int cmd_len = 0;
	struct stat buf;

	path = getenv("PATH");	/*Pass in the 1st argv to search its path*/
	printf("%s\n",path);
	if(path)
	{
		path_cpy = strdup(path);	/*duplicate the path string*/

		cmd_len = strlen(cmd_one);	/*get the length of the cmd*/

		path_token = strtok(path_cpy, ":");	/*split the cmd into individual path strings*/

		while(path_token != NULL)
		{
			dir_len = strlen(path_token);	/*Get the lenth of the original path command*/

			file_path = malloc(cmd_len + dir_len + 2);	/*allocate memory for the file path and  include space for / and \0*/

			strcpy(file_path, path_token);	/*copy each string to file path*/

			strcat(file_path, "/");	/*add / after each string*/

			strcat(file_path, cmd_one);	/*add the 1st arg string to the file path*/

			strcat(file_path, "\0");	/*add a NULL terminating char to indicate the end*/

			if(stat(file_path, &buf) == 0)	/*checks if the file path exists*/
			{
				free(path_cpy);	/*free path string if it exists*/
				return (file_path);	/*return file path*/
			}
			else
			{
				free(file_path);	/*if it path doesnt exist free space to store ff string*/
				path_token = strtok(NULL, ":");	/* Run the ff path string*/
			}
		}

		free(path_cpy);
		
		if(stat(cmd_one, &buf) == 0)	/*checkk if the 1st cmd is a file*/
		{
			return (cmd_one);
		}
		return (NULL);
	}

	return (0);
}
