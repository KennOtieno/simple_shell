#include "shell.h"
/**
 * read_buf - reads buffer
 * @info:
 * @buf:
 * @i:
 * Return:
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{

	size_t r = 0;

	if(*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * getline - gets line from user input
 * @info:
 * @lineptr:
 * @buffsize:
 * Return: Amount of chacter's read, @c_count
 */
int _getline(info_t *info, char **lineptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t j;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *lineptr;
	if(p && length)
		s = *length;
	if(i == len)
		i = len = 0;
	r = read_buf(info, buf &len);
	if (r == -1 || (r = 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);
	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k -1 + 1);
	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*lineptr = p;
	return (s);
}
