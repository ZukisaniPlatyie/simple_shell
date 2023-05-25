#include "shell.h"

int main(void)
{
	char **av;
	char *cmd;
	char *cmd_cpy;
	char *token = NULL;
	const char *delim = " \n";
	int n_tokens = 0;
	size_t n = 0;
	ssize_t n_cmd = 0;
	int i = 0;


	printf("($)");
	
	n_cmd = getline(&cmd, &n, stdin);		/*returns the number of char read*/
	cmd_cpy = malloc(sizeof(char) * n_cmd);         /*allocate memo with the size of char read*/

	if(cmd_cpy == NULL)
	{
		printf("memory Error");
		return (-1);
	}
	strcpy(cmd_cpy, cmd);                           /*make a copy of the string/cmd entered by user*/

	if(n_cmd == -1)
	{
		return (-1);
	}
	else
	{
		token = strtok(cmd, delim);			/*split cmd into individual strings*/

		while(token != NULL)
		{
			n_tokens++;                             /*count each token received*/
			token = strtok(NULL, delim);		/*give strtok function the remaining string to split*/
		}
		
		n_tokens++;					/*subtract the NULL Character that was counted*/

		av = malloc(sizeof(char *) * n_tokens);	/*alloate memory for the pointer array to No of tokens*/

		token = strtok(cmd_cpy, delim);

		for(i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, delim);
			printf("av[%d]: %s\n", i, av[i]);
		}
		
		free(cmd);
		free(cmd_cpy);
		free(av);
	}
	return (0);
}
