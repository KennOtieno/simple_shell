#inlcude "shell.h"

/**
 * main - the main entry point
 * @ac: argument count
 * @av: argument vector (array)
 * Return: 0 (Success) 1 (Failure)
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	/*inline assembly code*/
	asm ("mov %1, %0\n\t"
	     "add $3, %0"
	     : "=r" (fd),
	     : "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_READONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
