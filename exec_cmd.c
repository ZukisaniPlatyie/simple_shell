#include "shell.h"

void exec_cmd(char **av)
{
	char *cmd_one = NULL;
	char *full_path = NULL;
	int val = 0;

	if(av)
	{
		cmd_one = av[0];	/*assign 1st argv[0] to cmd_one variable*/
		/*val = execve(cmd_one, av, NULL);*/
		full_path = cmd_path(cmd_one);	/*call the cmd_path fnc to get the command path*/

		val = execve(full_path, av, NULL);	/*call the execve sys call fnc to execute the cmd path*/

		if(val == -1)
		{
			perror(cmd_one);
		}
	}
}
