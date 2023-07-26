#include "shell.h"

/**
 * _strlen - finds string length
 * @s: string
 * Return: string length
 */
int _strlen(char *s)
{
	int count = 0;

	if (!s)
		return (0);

	while (*s++) /*until NULL*/
		count++;
	return (a);
}

/**
 * _strcmp - strings lexicogarphic comparison
 * @s1: first string
 * @s2: second string
 * Return: @s1 and @s2 comparison
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - check if the needle begin with haystack
 * @haystack: search the str
 * @needle: find substring
 * Return: @haystack if found, NULL otherwise
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concats two strings together
 * @dest: buffer
 * @src: buffer source
 * Return: pointer buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
