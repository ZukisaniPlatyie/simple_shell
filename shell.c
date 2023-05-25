#include "shell.h"

/**
 * @ac - argument count variable
 * @argv - argument vector array pointer
 * @cmd - pointer array/buffer to store user intput
 * @cmd_cpy - copy of the pointer array/ buffer
 * @token - array string to store spited cmd
 * @delim - variable to store separating char 
 * @No_cmd - total No of characters read by getline function
 * Return : 0 always
 */

int main(void)
{
	char **av;
	char *cmd = NULL; 
	char *cmd_cpy = NULL;
	char *prompt = "($)";
	char *token;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t n_cmd;
	int n_token = 0;
	int i = 0;
	
	while(1)
	{
		printf("%s", prompt);	/*print the prompt symbol*/
		
		n_cmd = getline(&cmd, &n, stdin);	/*read in the number chr from getline fnc*/

		if(n_cmd == -1)
		{
			return (-1);
		}
		
		cmd_cpy = malloc(sizeof(char) * n_cmd);	/*allocate spcae to store char read from getline fnc*/
		
		if(cmd_cpy == NULL)
		{
			perror("Memory allocation error\n");
			return (-1);
		}

                strcpy(cmd_cpy, cmd);	/*make copy of the comand entered*/
		
		token = strtok(cmd, delim);	/*Splits the command string entered by the user into small strings*/

		while(token)
		{
			n_token++;
			token = strtok(NULL, delim);
		}

		n_token++;
		
		av = malloc(sizeof(char *) * n_token);	/*allocate memory to to the argv with the size of the tokens/strings*/

		token = strtok(cmd_cpy, delim);	/*split the original commands entered by the user*/

		for(i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, delim);
		}
			
		av[i] = NULL;	/*add in the NULL char to the last string in the array*/
		
		exec_cmd(av);	/*call the execve function to execute the commands*/
	}
	free(cmd);
	free(cmd_cpy);
		
	return (0);
}
