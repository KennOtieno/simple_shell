#include "shell.h"
/**
 * main - the simple shell
 * argc - integer count of arguments
 * argv - double pointer for command line arguments
 * Return - 0
 */

int main(int argc, char **argv)
{
	char *prompt = "simpleshell$ ";
	char *lineptr = NULL, *lineptr_cpy = NULL;
	size_t n = 0;
	ssize_t exit_char_read = 0;
	char *delim = " \n";
	char *token = NULL;
	int token_count = 0;
	int i;

	(void)argc; (void)argv;
	while(1) /*shell loop*/
	{
		printf("%s", prompt);
		exit_char_read = getline(&lineptr, &n, stdin); /*user input*/
		/*checks for EOF character or if getline function fails*/
		if (exit_char_read == -1)
			return (-1);
		lineptr_cpy = malloc(sizeof(lineptr) * exit_char_read);
		if (lineptr_cpy == NULL)
		{
			perror("Memory Allocation Error");
			return(-1);
		}
		/*copying string*/
		strcpy(lineptr_cpy, lineptr);
		/*parsing through string*/
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			token_count++; /* counts from 1*/
			token = strtok(NULL, delim);
		}
		token_count++;
		argv = malloc(sizeof(char *) * token_count);
		token = strtok(lineptr_cpy, delim);
	        for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		int counter;
		for (counter = 0; counter < token_count -1; ++counter)
			printf("%s\n", argv[counter]);
		printf("%s\n", lineptr);
	}
	free(argv);
	free(lineptr);
	free(lineptr_cpy);
	return (0);
}
